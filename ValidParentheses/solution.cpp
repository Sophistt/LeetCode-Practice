/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   @file:solution.cpp
*   @author: Sophistt
*   @date:2019-11-05 13:56
*   @description: 
*
================================================================*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {

public:
    bool isValid(string s) {
        string leftJudge = "([{";
        string rightJudge = ")]}";
        vector<char> strSave;
        size_t found = 0;
        
        for (int i = 0; i < s.length(); i++) {
            found = leftJudge.find(s[i]);
            if (found != string::npos) strSave.push_back(s[i]);
            else {
                if (strSave.size() == 0) return false;
                char pop = strSave.back();
                if (leftJudge.find(pop) == rightJudge.find(s[i])) {
                    strSave.pop_back();
                    continue;
                }
                else return false;
            }
        }
        return (strSave.size() != 0) ? false : true;
    }

};


int main() {
    Solution s;
    string testStr = "";
    cout << s.isValid(testStr) << endl;
    
    return 0;
}
