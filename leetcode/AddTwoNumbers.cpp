//
//  AddTwoNumbers.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/13/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "AddTwoNumbers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry = 0) {
    	if(NULL == l1 && NULL == l2) {
    		return ((carry==0)?(NULL):(new ListNode(carry)));
    	}
    	else if(NULL == l1) {
    		return addNumber(l2, carry);
    	}
    	else if(NULL == l2) {
    		return addNumber(l1, carry);
    	}
    	else {
    		ListNode* ret = new ListNode((l1->val + l2->val + carry)%10);
    		ret->next = addTwoNumbers(l1->next, l2->next, (l1->val + l2->val + carry)/10);
    		return ret;
    	}
    }
    
    ListNode *addNumber(ListNode *l1, int carry) {
    	if(NULL == l1) {
    		return ((carry==0)?(NULL):(new ListNode(carry)));
    	}
    	else {
    		ListNode* ret = new ListNode((l1->val + carry)%10);
    		ret->next = addNumber(l1->next,(l1->val + carry)/10);
    		return ret;
    	}
    }
};