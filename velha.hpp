#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/**
 * Get user's input and return a 3x3 matrix representing the game's hash
*/
vector<vector<int>> parseHash()
{
    vector<vector<int>> hash(3);

    int a;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 && cin >> a; j++){
            hash[i].push_back(a);
        }
    }
    
    return hash;
}

vector<vector<int>> getTraces(vector<vector<int>> hash)
{
    vector<vector<int>> traces; // Initialize hash trays array
    int cross = 0, circle = 0;

    
    for (int i = 0; i < 3; i++) {
        traces.push_back(hash[i]); // Get rows

        vector<int> trace;
        for (int j = 0; j < 3; j++) {
            trace.push_back(hash[j][i]); // Get columns
        }

        traces.push_back(trace);
    }

    // Get diagonals
    traces.push_back({hash[0][0], hash[1][1], hash[2][2]});
    traces.push_back({hash[2][0], hash[1][1], hash[0][2]});

    return traces;
}