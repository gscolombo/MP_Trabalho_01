#include <vector>
#include "./velha.hpp"

using std::cout;

int main() {
    cout << "\nThis program validates a game of tic-tac-toe given a 3x3 matrix of 0's, 1's and 2's,\nrepresenting an empty space, a cross and a circle, respectively. \n\n";
    cout << "Please input a matrix like the following (you can choose the numbers): \n\n";
    cout << "1 2 1\n2 2 1\n0 1 1\n\n";

    vector<vector<int>> game = parseHash();
    int res = validateTicTacToe(game);

    switch (res) {
    case 2:
        cout << "\nCircles wins!\n";
        break;
    case 1:
        cout << "\nCrosses wins!\n";
        break;
    case 0:
        cout << "\nGame tied!\n";
        break;
    case -1:
        cout << "\nNo winners yet\n";
        break;
    case -2:
        cout << "\nGame is invalid!\n";
        break;
    }

    return res;
}
