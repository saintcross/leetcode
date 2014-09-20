//
//  LongestCommonPrefix.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/20/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "LongestCommonPrefix.h"
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) {
            return "";
        }
        sort(strs.begin(),strs.end());
        int i = 0;
        while(strs.front()[i] == strs.back()[i] && strs.front()[i] != '\0'){
            ++i;
        }
        return strs.front().substr(0,i);
        
    }
};