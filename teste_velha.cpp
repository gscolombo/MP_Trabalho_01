#include <vector>

#include "gtest/gtest.h"
#include "velha.hpp"

vector<vector<int>> matrixRef {
    {1, 2, 1},
    {2, 0, 1},
    {1, 2, 2}
};

vector<vector<int>> matrixRefTraces {
  {1,2,1},
  {1,2,1},
  {2,0,1},
  {2,0,2},
  {1,2,2},
  {1,1,2},
  {1,0,2},
  {1,0,1}
};

TEST(Input, ParseMatrixHashFromUserInput) {
  EXPECT_EQ(parseHash(), matrixRef);
}

TEST(GameValidation, GetTracesFromMatrix) {
    EXPECT_EQ(getTraces(matrixRef), matrixRefTraces);
}