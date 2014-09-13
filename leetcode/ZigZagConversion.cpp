//
//  ZigZagConversion.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/13/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "ZigZagConversion.h"

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1) {
            return s;
        }
        int len = static_cast<int>(s.length());
        if(len == 0) {
            return "";
        }
        int d = nRows * 2 - 2;
        int q = len / d;
        int r = len % d;
        string ret;
        for(int i = 0; i < q; ++i) {
            ret += s[i * d];
        }
        if(r > 0) {
            ret += s[len - r];
        }
        for(int j = 1; j < nRows - 1; ++j) {
            for(int i = 0; i < q; ++i) {
                ret += s[i * d + j];
                ret += s[(i + 1) * d - j];
            }
            if(r > j) {
                ret += s[len - r + j];
            }
            if(r > (d - j)) {
                ret += s[len - r + (d - j)];
            }
        }
        for(int i = 0; i < q; ++i) {
            ret += s[i * d + (nRows - 1)];
        }
        if(r > (nRows - 1)) {
            ret += s[len - r + (nRows - 1)];
        }
        return ret;
    }
};