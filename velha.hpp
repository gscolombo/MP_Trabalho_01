#include <iostream>
#include <vector>
#include <fstream>
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