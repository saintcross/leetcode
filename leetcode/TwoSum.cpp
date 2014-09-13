//
//  TwoSum.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/13/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "TwoSum.h"
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        map<int, int> posMap;
        pair<map<int, int>::iterator, bool> insertRet;
        map<int, int>::iterator findRet;
        size_t size = numbers.size();
        for(int i = 0; i < size; ++i) {
        	insertRet = posMap.insert(make_pair(numbers[i], i));
        	if(!(insertRet.second) && (numbers[i] * 2 == target)) {
        		ret.push_back(insertRet.first->second + 1);
        		ret.push_back(i + 1);
        		return ret;
        	}
        }
        for(int i = 0; i < size; ++i) {
        	findRet = posMap.find(target - numbers[i]);
        	if(findRet != posMap.end() && (findRet->second != i)) {
        		ret.push_back(i + 1);
        		ret.push_back(findRet->second + 1);
        		return ret;
        	}
        }
        return ret;
    }
};