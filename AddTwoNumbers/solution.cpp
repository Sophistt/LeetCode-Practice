/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   @file:solution.cpp
*   @author: Sophistt
*   @date:2019-11-19 13:42
*   @description: 
*
================================================================*/


#include<iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class CommonSolution {

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int sum = 0;

        while (l1 != NULL || l2 != NULL || sum > 0) {
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            if (head == NULL) {
                head = new ListNode(sum % 10);
                tail = head;
                sum /= 10;
            }
            else {
                tail = new ListNode(sum % 10);
                tail = tail->next;
                sum /= 10;
            }
        }
        
        return head;
    }

};

class PptrSolution {

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode** ptr = & head;
        int sum = 0;

        while (l1 != NULL || l2 != NULL || sum > 0) {
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            (*ptr) = new ListNode(sum % 10);
            sum /= 10;
            ptr = &((*ptr)->next);

        }
        
        return head;
    }
};


int main() {
    
    ListNode l1 = ListNode(5);
    ListNode m1 = ListNode(1);
    
    ListNode l2 = ListNode(5);
    ListNode m2 = ListNode(6);
    
    l1.next = & m1;
    l2.next = & m2;

    CommonSolution commonSolution;

    ListNode* ptr = commonSolution.addTwoNumbers(&l1, &l2);
}
