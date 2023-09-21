#include <iostream>
#include <vector>
#include <utility>

#ifndef VELHA_HPP_
#define VELHA_HPP_

using std::vector;
using std::cin;

/**
 * Get user's input and return a 3x3 matrix representing the game's hash
*/
vector<vector<int>> parseHash() {
    vector<vector<int>> hash(3);

    int a;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 && cin >> a; j++) {
            hash[i].push_back(a);
        }
    }

    return hash;
}


/**
 * Given a hash (3x3 matrix), returns a multidimensional array (as a vector) containing each
 * valid trace of the game (i.e. columns, rows and diagonals)
*/
vector<vector<int>> getTraces(vector<vector<int>> hash) {
    // Initialize hash trays array
    vector<vector<int>> traces;

    for (int i = 0; i < 3; i++) {
        // Get rows
        traces.push_back(hash[i]);

        vector<int> trace;
        for (int j = 0; j < 3; j++) {
            // Get columns
            trace.push_back(hash[j][i]);
        }

        traces.push_back(trace);
    }

    // Get diagonals
    traces.push_back({hash[0][0], hash[1][1], hash[2][2]});
    traces.push_back({hash[2][0], hash[1][1], hash[0][2]});

    return traces;
}


bool checkFull(vector<int> trace, int type) {
    return (trace[0] == type) && (trace[1] == type) && (trace[2] == type);
}


/**
 * Iterate over hash traces to check game status, checking the following conditions:
 * - If one and only one trace is full with crosses or circles, then we have a winner
 * - If one trace is empty and it wasn't found traces full with crosses or circles, the game is undefined
 * - If there is no full traces, the game is a tie
 * 
 *  Otherwise, the game is invalid
*/
int validateTicTacToe(vector<vector<int>> hash) {
    vector<vector<int>> traces = getTraces(hash);
    int fullCross = 0, fullCircle = 0, fullBlank = 0;

    // Iteration over traces
    for (int i = 0; i < static_cast<int>(traces.size()); i++) {
        if (checkFull(traces[i], 1)) {
            fullCross++;
        }

        if (checkFull(traces[i], 2)) {
            fullCircle++;
        }

        if (checkFull(traces[i], 0)) {
            fullBlank++;
        }
    }

    // Winner condition
    if (fullCross == 1 || fullCircle == 1) {
        if (fullCross == 1 && fullCircle == 0) {
            return 1;
        }

        if (fullCircle == 1 && fullCross == 0) {
            return 2;
        }

        // Two winners is invalid
        return -2;

    // No winners
    } else if (fullBlank > 1 && (fullCircle == 0 || fullCross == 0)) {
        return -1;
    // Tie
    } else if (fullBlank == 0 && fullCircle == 0 && fullCross == 0) {
        return 0;
    // Invalid game
    } else {
        return -2;
    }
}
#endif  // VELHA_HPP_
