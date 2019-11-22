/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   @file:solution.cpp
*   @author: Sophistt
*   @date:2019-11-22 15:32
*   @description: 
*
================================================================*/


#include<vector>
#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {} 
};


class Solution {

public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        struct ListNode *p1 = head, *p2 = head->next, *prev = NULL;
        
        while(p2) {
            p1->next = p2->next;
            p2->next = p1;

            if (prev) {
                head = p2;
                prev = p1; 
            }
            else {
                prev->next = p2;
                prev = p1;
            }

            if (p1->next) p1 = p1->next;
            p2 = p1->next;
        }
        return head;
    }
};


int main() {
    
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = 1; i < 5; i++) {
        
        if (!tail) {
            tail = new ListNode(i);
            head = tail;
        }
        
        else {
            tail->next = new ListNode(i);
            tail = tail->next;
        }
    }

    Solution solution;
    solution.swapPairs(head);
}
