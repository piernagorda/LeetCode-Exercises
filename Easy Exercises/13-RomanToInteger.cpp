//
//  main.cpp
//  Test
//
//  Created by Javier Piernagorda Olivé on 2022-12-20.
//
//  Time Complexity: O(n)
//  Space Complexity: O(1)
//
//  I've seen a couple hardcoded solutions were they just replace IV by IIII, XL as XXXX but
//  I'm not a huge fan of doing that. This one solves any kind of number in theory (I say that because we would need
//  a way to express big roman numerals with strings)

#include <iostream>
using namespace std;

class Solution {
    
public:
    
    int romanToInt(string s) {
        
        int count = 0, tempCount = 0, lastElement = -1, currentLetter = charToInt(s[0]);
        
        tempCount+=currentLetter;
        lastElement = currentLetter;
        //We start in 1 since we already grabbed s[0]
        for (int i=1; i<s.length(); ++i){
    
            currentLetter = charToInt(s[i]);
    
            if (currentLetter==lastElement) tempCount += currentLetter;
            else if (currentLetter<lastElement){
                count+=tempCount;
                tempCount=currentLetter;
            }
            else{
                currentLetter-=tempCount;
                count+=currentLetter;
                tempCount=0;
            }
            lastElement = currentLetter;
        }
        return count + tempCount;
    }
    
    //We need a quick way to convert the roman numbers to decimal numbers
    int charToInt(char c){
        int ret = 0;
        switch(c){
            case 'I': ret=1; break;
            case 'V': ret=5; break;
            case 'X': ret=10; break;
            case 'L': ret=50; break;
            case 'C': ret=100; break;
            case 'D': ret=500; break;
            case 'M': ret=1000; break;
            default: break;
        }
        return ret;
    }
    
    
};

int main(int argc, const char * argv[]) {
    Solution sol;
    std::cout<<"III: "<<sol.romanToInt("III")<<std::endl;
    std::cout<<"LVIII: "<<sol.romanToInt("LVIII")<<std::endl;
    std::cout<<"MCMXCIV: "<<sol.romanToInt("MCMXCIV")<<std::endl;
    return 0;
}
