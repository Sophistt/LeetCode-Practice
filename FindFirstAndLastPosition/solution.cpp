/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   @file:solution.cpp
*   @author: Sophistt
*   @date:2019-11-21 11:39
*   @description: 
*
================================================================*/

#include<vector>
#include<iostream>

using namespace std;


class BinarySolution {

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        int head = binarySearch(nums, target, true);

        if (head == nums.size() || nums[head] != target) return {-1, -1};
        else return {head, binarySearch(nums, target, false) - 1};
    }

private:
    int binarySearch(const vector<int>& nums, int target, bool left) {
        int lo = 0, hi = nums.size();

        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || (left && target == nums[mid])) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};


int main() {

    vector<int> testVector = {1, 2, 3, 5, 5, 5, 7, 8, 9};
    
    BinarySolution binarySolution;
    vector<int> range = binarySolution.searchRange(testVector, 5); 

    cout << range[0] << ' ' << range[1] << endl;
}
