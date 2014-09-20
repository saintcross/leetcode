//
//  ThreeSum.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/20/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "ThreeSum.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > rets;
        if(num.size() < 3) {
            return rets;
        }
        sort(num.begin(),num.end());
        if(num.front() > 0 || num.back() < 0) {
            return rets;
        }
        for(int i = 0; i != num.size(); ++i){
            if(i > 0 && num[i] == num[i-1]) {
                continue;
            }
            if(num[i] > 0){
                break;
            }
            for(int j = i+1, k = static_cast<int>(num.size()) - 1; k > j;){
                if(j > i+1 && num[j] == num[j-1]){
                    ++j;
                    continue;
                }
                if(num[i] + num[j] > 0){
                    break;
                }
                if(num[i] + num[j] + num[k] < 0) {
                    ++j;
                }
                else if(num[i] + num[j] + num[k] > 0) {
                    --k;
                }
                else{
                    vector<int> ret;
                    ret.push_back(num[i]);
                    ret.push_back(num[j]);
                    ret.push_back(num[k]);
                    rets.push_back(ret);
                    ++j;
                    --k;
                }
            }
            
        }
        return rets;
    }
};