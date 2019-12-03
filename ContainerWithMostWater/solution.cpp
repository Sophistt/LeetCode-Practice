/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   @file:solution.cpp
*   @author: Sophistt
*   @date:2019-11-20 18:54
*   @description: 
*
================================================================*/

#include<iostream>
#include<vector>

using namespace std;

class ExhaustiveSolution {

public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int minHeight = 0;
        for (size_t i = 0; i < height.size(); i++) {
            for (size_t j = i+1; j < height.size(); j++) {
                minHeight = height[i] < height[j] ? height[i] : height[j];
                maxArea = maxArea > minHeight * (j - i) ? maxArea : minHeight * (j - i);
            }
        }
        return maxArea;
    }
};



class TwoPointerSolution {

public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, minHeight = 0; 
        int head = 0, tail = height.size() - 1;
        while(head < tail) {
            minHeight = height[head] < height[tail] ? height[head] : height[tail];
            maxArea = maxArea > (tail - head) * minHeight ? maxArea : (tail - head) * minHeight;
            height[head] < height[tail] ? head++ : tail--;
        }
        return maxArea;
    }
};


int main() {

    vector<int> testVector = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    ExhaustiveSolution exhaustiveSolution;
    TwoPointerSolution twoPointerSolution;
    
    // cout << exhaustiveSolution.maxArea(testVector) << endl;
    cout << twoPointerSolution.maxArea(testVector) << endl;
}
