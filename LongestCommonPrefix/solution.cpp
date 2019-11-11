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

class Solution {

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while( strs[i].find(prefix) != 0 || strs[i].find(prefix) == string::npos ) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};



int main() {
    
    // test case
    vector<string> testVecotr;
    testVecotr.push_back("fl");
    testVecotr.push_back("float");
    testVecotr.push_back("flower");
    
    Solution solution;
    
    cout << solution.longestCommonPrefix(testVecotr) << endl;;
}
