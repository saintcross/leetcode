//
//  ReserveInteger.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/14/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "ReverseInteger.h"

class Solution {
public:
    int reverse(int x) {
        int sign=(x>0)?1:-1;
        x=x*sign;
        int result = x % 10;
        while((x = x/10)){
            result = result * 10 + x % 10;
        }
        return result*sign;
    }
};