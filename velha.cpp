#include <vector>
#include "./velha.hpp"

using std::cout;

int main() {
    vector<vector<int>> game = parseHash();
    int res = validateTicTacToe(game);

    switch (res) {
    case 2:
        cout << "Circles wins!";
        break;
    case 1:
        cout << "Crosses wins!";
        break;
    case 0:
        cout << "Game tied!";
        break;
    case -1:
        cout << "No winners yet";
        break;
    case -2:
        cout << "Game is invalid!";
        break;
    }

    return res;
}
