/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   @file:solution.cpp
*   @author: Sophistt
*   @date:2019-11-18 14:24
*   @description: 
*
================================================================*/

#include<iostream>
#include<vector>

using namespace std;

class BinarySolution {

public:
    int searchInsert(vector<int>&nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return target > nums[nums.size() - 1] ? lo + 1 : lo;
    }
};



class CommonSolution {

public:
    int searchInsert(vector<int>& nums, int target) {
        int j = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (target > nums[i]) {
                j++;
                continue;
            }
        }
        return j;
    }
};

int main() {

    vector<int> testVector;

    testVector.push_back(1);
    testVector.push_back(3);
    testVector.push_back(5);
    testVector.push_back(7);
    testVector.push_back(9);

    BinarySolution binarySolution;
    // CommonSolution commonSolution;

    cout << binarySolution.searchInsert(testVector, 9) << endl;
}
