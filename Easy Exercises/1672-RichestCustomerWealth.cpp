//
//  main.cpp
//  Test
//
//  Created by Javier Piernagorda Olivé on 2022-12-20.
//
//  Time Complexity: O(n)
//  Space Complexity: O(n)
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        unsigned int max = 0, rows = accounts.size(), columns = accounts[0].size();
        for (int i=0; i<rows; ++i){
            int tempMax = 0;
            for (int ii = 0; ii<columns; ++ii) tempMax += accounts[i][ii];
            if (tempMax > max) max = tempMax;
        }
        return max;
    }
};
    
int main(int argc, const char * argv[]) {
    Solution sol;
    vector<vector<int>> vec{ { 1, 2, 3 },
                             { 4, 5, 6 },
                             { 7, 8, 9 } };
    std::cout<<sol.maximumWealth(vec);
    return 0;
}
