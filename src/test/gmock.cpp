#include <gmock/gmock.h>
#include <gtest/gtest.h>
int answer() {
	return 42;
}

namespace {

	TEST(GMock, TestIf42Is42)
	{
		ASSERT_THAT(answer(), Eq(42));
	}

}