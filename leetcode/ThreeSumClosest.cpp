//
//  ThreeSumClosest.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/20/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "ThreeSumClosest.h"
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size() == 0) {
            return 0;
        }
        if(num.size() == 1) {
            return num[0];
        }
        if(num.size() == 2) {
            return num[0] + num[1];
        }
        if(num.size() == 3) {
            return num[0] + num[1] + num[2];
        }
        int i = 0;
        int j = i + 1;
        int k = static_cast<int>(num.size()) - 1;
        sort(num.begin(), num.end());
        int min_sum = num[i] + num[i + 1] + num[i + 2];
        int max_sum = num[k] + num[k - 1] + num[k - 2];
        if(target <= min_sum) {
            return min_sum;
        }
        if(target >= max_sum) {
            return max_sum;
        }
        int dis_min = 0;
        int sign_min = 0;
        if((target - min_sum) > (max_sum - target)) {
            dis_min = max_sum - target;
            sign_min = 1;
        }
        else {
            dis_min = target - min_sum;
            sign_min = -1;
        }
        for(i = 0; i != num.size(); ++i){
            if((i > 0) && (num[i] == num[i-1])) {
                continue;
            }
            if(((num[i] * 3) - target) > dis_min){
                break;
            }
            for(j = i+1, k = static_cast<int>(num.size()) - 1; k > j;){
                if((j > i+1) && (num[j] == num[j-1])){
                    ++j;
                    continue;
                }
                if((num[i] + (num[j] * 2) - target) > dis_min){
                    break;
                }
                int dis = num[i] + num[j] + num[k] - target;
                if(dis < 0) {
                    if((dis_min + dis) > 0) {
                        dis_min = -dis;
                        sign_min = -1;
                    }
                    ++j;
                }
                else if(dis > 0) {
                    if((dis_min - dis) > 0) {
                        dis_min = dis;
                        sign_min = 1;
                    }
                    --k;
                }
                else{
                    return target;
                }
            }
        }
        return target + sign_min * dis_min;
    }
};