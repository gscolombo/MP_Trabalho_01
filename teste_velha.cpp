#include <vector>
#include <fstream>

#include "gtest/gtest.h"
#include "./velha.hpp"

vector<vector<int>> matrixRef {
    {1, 2, 2},
    {2, 0, 1},
    {1, 2, 0}
};

vector<vector<int>> matrixRefTraces {
  {1, 2, 2},
  {1, 2, 1},
  {2, 0, 1},
  {2, 0, 2},
  {1, 2, 0},
  {2, 1, 0},
  {1, 0, 0},
  {1, 0, 2}
};

TEST(Input, ParseMatrixHashFromUserInput) {
  std::ifstream inputFile("test_assets/text_input.txt");

  if (inputFile.is_open()) {
    EXPECT_EQ(parseHash(inputFile), matrixRef);
    inputFile.close();
  } else {
    ADD_FAILURE();
  }
}

TEST(GameValidation, GetTracesFromMatrix) {
    EXPECT_EQ(getTraces(matrixRef), matrixRefTraces);
}

TEST(GameValidation, CheckFullTracesDetection) {
    EXPECT_TRUE(checkFull({0, 0, 0}, 0));
    EXPECT_TRUE(checkFull({1, 1, 1}, 1));
    EXPECT_TRUE(checkFull({2, 2, 2}, 2));
    EXPECT_FALSE(checkFull({2, 1, 2}, 1));
    EXPECT_FALSE(checkFull({0, 2, 1}, 2));
    EXPECT_FALSE(checkFull({0, 0, 1}, 0));
}

TEST(GameValidation, ValidateGame) {
  vector<vector<int>> crossWins, circleWins, tieGame,
                      undefinedGame, invalidGame;

  crossWins = {
    {1, 2, 1},
    {1, 1, 2},
    {2, 2, 1}
  };

  circleWins = {
    {1, 2, 1},
    {1, 1, 2},
    {2, 2, 2}
  };

  tieGame = {
    {1, 2, 1},
    {2, 2, 1},
    {1, 1, 2}
  };

  undefinedGame = {
    {1, 0, 0},
    {0, 0, 2},
    {0, 0, 0}
  };

  invalidGame = {
    {1, 1, 1},
    {0, 0, 0},
    {2, 2, 2}
  };

  EXPECT_EQ(validateTicTacToe(crossWins), 1);
  EXPECT_EQ(validateTicTacToe(circleWins), 2);
  EXPECT_EQ(validateTicTacToe(tieGame), 0);
  EXPECT_EQ(validateTicTacToe(undefinedGame), -1);
  EXPECT_EQ(validateTicTacToe(invalidGame), -2);
}
