#include <vector>

#include "gtest/gtest.h"
#include "velha.hpp"

TEST(Input, ParseMatrixHashFromUserInput) {
  vector<vector<int>> ref{
    {1, 2, 1},
    {2, 0, 1},
    {1, 2, 2}
  };

  EXPECT_EQ(parseHash(), ref);
}