#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "multiplier.h"


using namespace testing;
using ::testing::_;
using ::testing::InvokeArgument;
using ::testing::Matcher;

TEST(General, base_001)
{
    Multiplier mult;
    EXPECT_EQ(6,mult.invoke(2,3));
}

TEST(General, base_002)
{
    Multiplier mult;
    EXPECT_EQ(8,mult.invoke(2,4));
}