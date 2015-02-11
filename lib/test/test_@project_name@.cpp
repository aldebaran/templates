#include <gtest/gtest.h>
#include <@project_name@/@project_name@.hpp>

TEST(@PROJECT_NAME@, foo) {
  ASSERT_EQ(42, foo());
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
