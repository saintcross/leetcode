//
//  PalindromeInteger.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/14/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "PalindromeInteger.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        else {
            int origin = x;
            int reverse = x % 10;
            while((x = x/10)){
                if ((reverse > (INT_MAX / 10)) || ((reverse == (INT_MAX / 10)) && ((x % 10) > (INT_MAX % 10)))) {
                    return false;
                }
                reverse = reverse * 10 + x % 10;
            }
            return reverse == origin;
        }
    }
};