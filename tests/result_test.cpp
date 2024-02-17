#include "gtest/gtest.h"
#include <gtest/gtest.h>

#include <filewatcher.h>

using namespace filewatcher;

TEST(ResultTest, Panic) {
  auto result = Result<int, int>::Err(1);
  EXPECT_DEATH({ result.unwrap(); }, "");
  EXPECT_DEATH({ result.expect(""); }, "");
  result.unwrap_err(); //Do not expect death here
  EXPECT_TRUE(true);

  //Do not expect death here

  result = Result<int, int>::Ok(1);
  EXPECT_DEATH({ result.unwrap_err(); }, "");
  EXPECT_DEATH({ result.expect_err(""); }, "");
  result.unwrap(); //Do not expect death here
  EXPECT_TRUE(true);
}