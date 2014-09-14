//
//  StringToInteger.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/14/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "StringToInteger.h"

class Solution {
public:
    int atoi(const char *str) {
        int sign = 1, base = 0, i = 0;
        while (str[i] == ' ') { i++; }
        if (str[i] == '+') {
            i++;
        }
        else if (str[i] == '-') {
            sign = -1;
            i++;
        }
        while (str[i] >= '0' && str[i] <= '9') {
            if (((base > (INT_MAX / 10)) || ((base == (INT_MAX / 10)) && ((str[i] - '0') > (INT_MAX % 10)))) && (sign == 1)) {
                return INT_MAX;
            }
            else if(((base > (INT_MAX / 10)) || ((base == (INT_MAX / 10)) && ((str[i] - '0') > (INT_MAX % 10 + 1)))) && (sign == -1)){
                return INT_MIN;
            }
            base  = base * 10 + (str[i++] - '0');
        }
        return base * sign;
    }
};