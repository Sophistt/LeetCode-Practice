/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   @file:solution.cpp
*   @author: Sophistt
*   @date:2019-12-03 10:47
*   @description: 
*
================================================================*/


#include<vector>
#include<iostream>

using namespace std;

class Solution {
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }


    void backtrack(vector<string>& ans, string cur, size_t open, size_t close, size_t max) {
        if (cur.length() == max * 2) {
            ans.push_back(cur);
            return;
        }

        if (open < max) backtrack(ans, cur+"(", open+1, close, max);
        if (close < open) backtrack(ans, cur+")", open, close+1, max);
    }
};



int main() {
    
    Solution solution;
    vector<string> testVector = solution.generateParenthesis(3);

    for(size_t i = 0; i < testVector.size(); i++) {
        cout << testVector[i] << endl;
    }
}
