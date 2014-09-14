//
//  RomanToInteger.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/14/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "RomanToInteger.h"
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        static int weights[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        static string tokens[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int ret = 0;
        int offset = 0;
        int pos = 0;
        while(offset < s.length()){
            if(s.compare(offset, tokens[pos].length(), tokens[pos]) == 0) {
                ret += weights[pos];
                offset += tokens[pos].length();
            }
            else {
                ++pos;
            }
        }
        return ret;
    }
};