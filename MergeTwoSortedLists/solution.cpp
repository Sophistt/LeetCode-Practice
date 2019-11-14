/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   @file:solution.cpp
*   @author: Sophistt
*   @date:2019-11-13 14:48
*   @description: 
*
================================================================*/


#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
  
    ListNode(int x) : val(x), next(NULL) {}
};


class CommonSolution {

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* head = NULL;
        ListNode* tail = NULL;
    
        if (l1->val < l2->val) {
            head = l1;
            tail = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            tail = l2;
            l2 = l2->next;
        }

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }
            else {
                tail->next= l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }

        if (l1 != NULL) tail->next = l1;
        if (l2 != NULL) tail->next = l2;

        return head;
    }

};


class RecusiveSolution {

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode*l2) {
        if (l1 == NULL && l2 == NULL)  return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }

};


int main() {
  
    ListNode l1 = ListNode(1);
    ListNode m1 = ListNode(2);
    ListNode n1 = ListNode(4);

    ListNode l2 = ListNode(1);
    ListNode m2 = ListNode(3);
    ListNode n2 = ListNode(4);

    l1.next = & m1;
    m1.next = & n1;

    l2.next = & m2;
    m2.next = & n2;

    CommonSolution commonSolution;
    RecusiveSolution recusiveSolution;

    // ListNode *mergeList = commonSolution.mergeTwoLists(&l1, &l2);
    ListNode *mergeList = recusiveSolution.mergeTwoLists(&l1, &l2);

    return 0;
}
