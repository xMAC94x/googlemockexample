#include <gmock/gmock.h>
using namespace ::testing;

#include "gmock.cpp"
#include "mult.cpp"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
