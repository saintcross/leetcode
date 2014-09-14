//
//  RegularExpressionMatching.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/14/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "RegularExpressionMatching.h"

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(s[0] ==  '\0' && p[0] == '\0') {
            return true;
        }
        else if(s[0] == '\0') {
            if(p[1] == '*') {
                return isMatch(s, p+2);
            }
            else {
                return false;
            }
        }
        else if(p[0] == '\0') {
            return false;
        }
        else {
            bool isDot = false;
            if(p[0] == '.') {
                isDot = true;
            }
            bool isStar = false;
            if(p[1] == '*') {
                isStar = true;
            }
            bool isEqual = false;
            if(s[0] == p[0]) {
                isEqual = true;
            }
            if(isDot) {
                if(isStar) {
                    return isMatch(s+1, p) || isMatch(s, p+2);
                }
                else {
                    return isMatch(s+1, p+1);
                }
            }
            else if(isEqual){
                if(isStar) {
                    return isMatch(s+1, p) || isMatch(s, p+2);
                }
                else {
                    return isMatch(s+1, p+1);
                }
            }
            else {
                if(isStar) {
                    return isMatch(s, p+2);
                }
                else {
                    return false;
                }
            }
        }
    }
};