//
//  LongestWithoutRepeating.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/13/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "LongestWithoutRepeating.h"
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int offset = 0;
    	int ret = 0;
    	map<char, int> charMap;
    	pair<map<char, int>::iterator, bool> insertRet;
    	int len = static_cast<int>(s.length());
    	for(int i = 0; i < len; ++i) {
    		insertRet = charMap.insert(make_pair(s[i], i));
    		if(!insertRet.second) {
    			int plus = insertRet.first->second;
    			insertRet.first->second = i;
    			for(int j = offset; j < plus; ++j) {
    				charMap.erase(s[j]);
    			}
    			ret = max(ret, i - offset);
    			offset = plus + 1;
    		}
    	}
    	ret = max(ret, len - offset);
    	return ret;
    }
};