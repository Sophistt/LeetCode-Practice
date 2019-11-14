/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   @file:solution.cpp
*   @author: Sophistt
*   @date:2019-11-11 19:04
*   @description: 
*
================================================================*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class HorizontalScanningSolution {

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        
        for (size_t i = 1; i < strs.size(); i++) {
            while( strs[i].find(prefix) != 0 || strs[i].find(prefix) == string::npos ) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};


class VerticalScanningSolution {

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        
        for (size_t i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            for (size_t j = 1; j < strs.size(); j++) {
            if (i == strs[j].length() || strs[j][i] != c) return strs[0].substr(0, i);
            }
        }
        
        return strs[0];
    }
};



int main() {
    
    // test case
    vector<string> testVecotr;
    testVecotr.push_back("fl");
    testVecotr.push_back("float");
    testVecotr.push_back("flower");
    
    HorizontalScanningSolution horizontalScanningSolution;
    VerticalScanningSolution verticalScanningSolution;
    
    // cout << horizontalScanningSolution.longestCommonPrefix(testVecotr) << endl;;
    cout << verticalScanningSolution.longestCommonPrefix(testVecotr) << endl;;
}
