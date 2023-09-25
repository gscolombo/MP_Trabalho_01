#include <vector>
#include "./velha.hpp"

using std::cout;

int main() {
    cout << "\nThis program validates a game of tic-tac-toe";
    cout << "given a 3x3 matrix of 0's, 1's and 2's\n";
    cout << "representing an empty space, a cross";
    cout << "and a circle, respectively.\n\n";
    cout << "Please input a matrix like the following";
    cout << "(you can choose the numbers): \n\n";
    cout << "1 2 1\n2 2 1\n0 1 1\n\n";

    vector<vector<int>> game = parseHash();
    int res = validateTicTacToe(game);

    cout << outputResult(res);
    return res;
}
