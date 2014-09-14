//
//  IntegerToRoman.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/14/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "IntegerToRoman.h"
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        static int weights[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        static string tokens[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ret;
        int pos=0;
        while(num>0){
            if(num >= weights[pos]) {
                num -= weights[pos];
                ret += tokens[pos];
            }
            else {
                ++pos;
            }
        }
        return ret;
    }
};