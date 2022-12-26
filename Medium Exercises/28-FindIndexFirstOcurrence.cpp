//
//  main.cpp
//  Test
//
//  Created by Javier Piernagorda Olivé on 2022-12-26.
//
//  Time Complexity: O(n) since we iterate, in the worst case scenario, twice. This is O(2n) contained in O(n)
//  Space Complexity: O(1)
//

#include <iostream>
#include <chrono>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int posNeedle=0, i=0, i2=0;
        
        while (i2<haystack.size() && posNeedle!=needle.size()){
            if (haystack[i]==needle[posNeedle]){
                ++posNeedle;
                ++i;
            }
            else{
                ++i2;
                i=i2;
                posNeedle=0;
            }
        }
        if (posNeedle==needle.size()) return i-posNeedle;
        else return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    cout<<sol.strStr("mississippi",  "issip");
    std::cout<<"\n";
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    return 0;
}
