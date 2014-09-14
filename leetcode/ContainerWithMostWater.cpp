//
//  ContainerWithMostWater.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/14/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "ContainerWithMostWater.h"
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxA = 0;
        int l = 0;
        int r = static_cast<int>(height.size()) - 1;
        while(l < r) {
            maxA = max(maxA, (r-l) * min(height[l],height[r]));
            if(height[l] > height[r]) {
                --r;
            }
            else {
                ++l;
            }
        }
        return maxA;
    }
};