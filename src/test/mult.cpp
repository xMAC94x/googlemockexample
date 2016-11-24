#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mult.h"

namespace {

	TEST(GMock, SmallNumbers)
	{
		ASSERT_THAT(multNumbers(1,1), Eq(1));
		ASSERT_THAT(multNumbers(1,2), Eq(2));
		ASSERT_THAT(multNumbers(2,2), Eq(4));
		ASSERT_THAT(multNumbers(2,3), Eq(6));
	}
	
	TEST(GMock, ThreeTimesThree)
	{
		ASSERT_THAT(multNumbers(3,3), Eq(9));
	}

}