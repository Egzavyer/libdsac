#include <gtest/gtest.h>
#include <ds/darray.h>
#include "../src/ds/darray.c"
#include "../src/common.c"

class DynamicArrayTest : public testing::Test
{
public:
    DynamicArray *arr = nullptr;

    void SetUp() override
    {
        daCreate(5, &arr);
    }

    void TearDown() override
    {
        daDestroy(arr);
    }
};

TEST_F(DynamicArrayTest, daCreateTest)
{
    ASSERT_NE(arr, nullptr);
    EXPECT_EQ(arr->size, 0);
    EXPECT_EQ(arr->capacity, 5);

    testing::internal::CaptureStdout();
    EXPECT_EQ(daPrint(arr), 1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[]\n");
}

TEST_F(DynamicArrayTest, daPrintTest)
{
    daAppend(arr, 0);
    daAppend(arr, 1);
    daAppend(arr, 2);
    daAppend(arr, 3);

    testing::internal::CaptureStdout();
    EXPECT_EQ(daPrint(arr), 1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[0, 1, 2, 3]\n");
}

TEST_F(DynamicArrayTest, daPrintFailNullTest)
{
    DynamicArray *nullArr = nullptr;
    testing::internal::CaptureStderr();
    EXPECT_EQ(daPrint(nullArr), -2);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "daPrint failed: NULL_PARAM\n");
}

TEST_F(DynamicArrayTest, daCreateFailNullTest)
{
    testing::internal::CaptureStderr();
    EXPECT_EQ(daCreate(5, nullptr), -2);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "daCreate failed: NULL_PARAM\n");
}

TEST_F(DynamicArrayTest, daAppendFailNullTest)
{
    testing::internal::CaptureStderr();
    EXPECT_EQ(daAppend(nullptr, 1), -2);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "daAppend failed: NULL_PARAM\n");
}

TEST_F(DynamicArrayTest, daAppendFailIntOverTest)
{
    arr->size = INT_MAX;
    testing::internal::CaptureStderr();
    EXPECT_EQ(daAppend(arr, 1), -4);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "daAppend failed: INT_OVERFLOW\n");
}

TEST_F(DynamicArrayTest, daAppendFailDataNullTest)
{
    arr->data = nullptr;
    testing::internal::CaptureStderr();
    EXPECT_EQ(daAppend(arr, 1), -3);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "daAppend failed: NULL_POINTER\n");
}

TEST_F(DynamicArrayTest, daFillRandTest)
{
    daFillRand(arr);
    EXPECT_EQ(arr->size, 5);
    EXPECT_TRUE(arr->data[0] != 0);
}

TEST_F(DynamicArrayTest, daPopFailOOBTest)
{
    testing::internal::CaptureStderr();
    EXPECT_EQ(daPop(arr), 0);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "daPop failed: OUT_OF_BOUNDS\n");
}

TEST_F(DynamicArrayTest, daPopFailNullTest)
{
    testing::internal::CaptureStderr();
    EXPECT_EQ(daPop(nullptr), -2);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "daPop failed: NULL_PARAM\n");
}

class DynamicArrayInsertTest : public testing::Test
{
public:
    DynamicArray *arr = nullptr;

    void SetUp() override
    {
        daCreate(5, &arr);
    }

    void TearDown() override
    {
        daDestroy(arr);
    }
};

TEST_F(DynamicArrayInsertTest, appendTest)
{
    daAppend(arr, 0);
    EXPECT_EQ(arr->data[0], 0);
    EXPECT_EQ(arr->size, 1);
}

class DynamicArrayRemoveTest : public testing::Test
{
public:
    DynamicArray *arr = nullptr;

    void SetUp() override
    {
        daCreate(5, &arr);
        daAppend(arr, 0);
    }

    void TearDown() override
    {
        daDestroy(arr);
    }
};

TEST_F(DynamicArrayRemoveTest, removeAtTest)
{
    daRemove(arr, 0);
    EXPECT_EQ(arr->size, 0);
}

class DynamicArrayResizeTest : public testing::Test
{
public:
    DynamicArray *arr = nullptr;

    void SetUp() override
    {
        daCreate(4, &arr);
        daAppend(arr, 0);
        daAppend(arr, 1);
        daAppend(arr, 2);
        daAppend(arr, 3);
    }

    void TearDown() override
    {
        daDestroy(arr);
    }
};

TEST_F(DynamicArrayResizeTest, growTest)
{
    daAppend(arr, 4);
    EXPECT_EQ(arr->capacity, 8);
    EXPECT_EQ(arr->size, 5);
}

TEST_F(DynamicArrayResizeTest, shrinkTest)
{
    daPop(arr);
    daPop(arr);
    EXPECT_EQ(arr->capacity, 2);
    EXPECT_EQ(arr->size, 2);
}