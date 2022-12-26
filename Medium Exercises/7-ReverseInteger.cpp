//
//  main.cpp
//  Test
//
//  Created by Javier Piernagorda Olivé on 2022-12-20.
//
//  Time Complexity: O(logn)
//  Space Complexity: O(1)
//

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long sum = 0;
        while (std::abs(x)>0){
                sum *=10;
                sum +=x%10;
                x/=10;
        }
        if (sum>=numeric_limits<int>::max() || sum<=numeric_limits<int>::min()) return 0;
        else return sum;
    }
};
    
int main(int argc, const char * argv[]) {
    Solution sol;
    std::cout<<sol.reverse(123)<<endl;
}