//
//  main.cpp
//  Test
//
//  Created by Javier Piernagorda Olivé on 2022-12-20.
//
//  Time Complexity: O(keys pressed * number of chars in each key) = O(n*m) = O(n)
//  Space Complexity: O(n) where n = number of keys pressed
//

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Solution {
public:
    
    //We could also store this in a vector and pass it through each iteration as a const &
    std::vector<char> charsInKey(char c){
        switch(c){
            case '2': return {'a','b','c'}; break;
            case '3': return {'d','e','f'}; break;
            case '4': return {'g','h','i'}; break;
            case '5': return {'j','k','l'}; break;
            case '6': return {'m','n','o'}; break;
            case '7': return {'p','q','r', 's'}; break;
            case '8': return {'t','u','v'}; break;
            case '9': return {'w','x','y', 'z'}; break;
            default: return {}; break;
        }
    }
    
    void solveTheThing(std::vector<std::string> &solution, std::string digits, std::string word, int depth){
            
        //We iterate through all the chars in a single key (the one at the current depth)
        for (int i=0; i<charsInKey(digits[depth]).size(); ++i){
            word += charsInKey(digits[depth])[i];; //We get the current char
            if (word.size()==digits.size()) solution.push_back(word);
            else solveTheThing(solution, digits, word, depth+1);
            word.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        std::vector<string> sol;
        solveTheThing(sol, digits, "", 0);
        return sol;
    }
};

 //-This is another possible solution using maps. Its less efficient and slower
 /*
class Solution {
public:
    
    void solveTheThing(std::vector<std::string> &solution, const std::string &digits, std::string &word, std::map<char, std::vector<char>> charsInKey){
        //We iterate through all the chars in a single key (the one at the current depth)
        for (int i=0; i<charsInKey[digits[word.size()]].size(); ++i){
            word += charsInKey[digits[word.size()]][i]; //We get the current char
            if (word.size()==digits.size()) solution.emplace_back(word); //We've reached a solution
            else solveTheThing(solution, digits, word, charsInKey); //Solution not complete yet -> next key pressed
            word.pop_back(); //We undo the current word
        }
    }
    
    vector<string> letterCombinations(string digits) {
        std::vector<string> sol;
        std::map<char, std::vector<char>> charsInKeyMap;
        
        charsInKeyMap.insert(std::pair<char, std::vector<char>>('2', {'a','b','c'}));
        charsInKeyMap.insert(std::pair<char, std::vector<char>>('3', {'d','e','f'}));
        charsInKeyMap.insert(std::pair<char, std::vector<char>>('4', {'g','h','i'}));
        charsInKeyMap.insert(std::pair<char, std::vector<char>>('5', {'j','k','l'}));
        charsInKeyMap.insert(std::pair<char, std::vector<char>>('6', {'m','n','o'}));
        charsInKeyMap.insert(std::pair<char, std::vector<char>>('7', {'p','q','r', 's'}));
        charsInKeyMap.insert(std::pair<char, std::vector<char>>('8', {'t','u','v'}));
        charsInKeyMap.insert(std::pair<char, std::vector<char>>('9', {'w','x','y', 'z'}));
        
        string word = "";
        solveTheThing(sol, digits, word, charsInKeyMap);
        return sol;
    }
};
 */
int main(int argc, const char * argv[]) {
    Solution sol;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    std::vector<string> ret = sol.letterCombinations("2345");
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    for (int i=0; i<ret.size(); ++i)std::cout<<ret[i]<<", ";
    std::cout<<"\n";
    return 0;
}
