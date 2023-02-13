#include <iostream>
#include <fstream>
#include <vector>

class Solution {
public:

    void variationsWithoutRepetition(std::vector<std::vector<int>> &finalVector, const int &n, const int &k, std::vector<int> &sol, int depth){
        for (int i = depth; i <= n; ++i) {
            sol.emplace_back(i);
            sol.size() == k? finalVector.push_back(sol): variationsWithoutRepetition(finalVector, n, k, sol, i+1);
            sol.pop_back();
        }
    }

    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<int> solution;
        std::vector<std::vector<int>> finalVector;
        variationsWithoutRepetition(finalVector, n, k, solution, 1);
        return finalVector;
    }
};

int main() {

    Solution sol;
    std::vector<std::vector<int>> res = sol.combine(3, 2);
    
    for (int i=0; i<res.size(); ++i){
        for (int j=0; j<res[i].size(); ++j) std::cout<<res[i][j]<<" ";
        std::cout<<"\n";
    }
}
