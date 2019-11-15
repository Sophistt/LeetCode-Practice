/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   @file:soluction.cpp
*   @author: Sophistt
*   @date:2019-11-15 15:15
*   @description: 
*
================================================================*/


#include<iostream>
#include<vector>

using namespace std;

class EraseSolution {

public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int temp = nums[0];
        
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == temp) {
                nums.erase(nums.begin() + i);
                i -= 1;
            } 
            else temp = nums[i];
        }
        
        return nums.size();
    }
};


class SwitchSolution {

public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int i = 0;
        for (size_t j = 0; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i ++;
                nums[i] = nums[j];
            }
        }
        return ++i;
    }
};


int main() {

    // Test case
    vector<int> testVector;

    testVector.push_back(0);
    testVector.push_back(0);
    testVector.push_back(1);
    testVector.push_back(1);
    testVector.push_back(1);
    testVector.push_back(2);
    testVector.push_back(2);
    testVector.push_back(3);
    testVector.push_back(3);
    testVector.push_back(4);
    

    EraseSolution eraseSolution;
    SwitchSolution switchSolution; 
    
    cout << "length: " << switchSolution.removeDuplicates(testVector) << endl;

    return 0;
}
