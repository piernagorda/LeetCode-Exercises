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
    /*
     answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
     answer[i] == "Fizz" if i is divisible by 3.
     answer[i] == "Buzz" if i is divisible by 5.
     answer[i] == i (as a string) if none of the above conditions are true.
     */
    std::vector<string> fizzBuzz(int n) {
        
        std::vector<std::string> solution(n, "");
        for (int i = 1; i<=n; ++i){
            if ((i%15)==0) solution[i-1]="FizzBuzz";
            else if ((i%3)==0) solution[i-1]= "Fizz";
            else  if ((i%5)==0) solution[i-1] = "Buzz";
            else solution[i-1] = std::to_string(i);
        }
        return solution;
    }
    
};
    
int main(int argc, const char * argv[]) {
    Solution sol;
    int n =15; //Test number
    std::vector<std::string> solution = sol.fizzBuzz(n);
    for (int i = 0; i<n; ++i) std::cout<<solution[i]<<" ";
    std::cout<<"\n";
    return 0;
}
