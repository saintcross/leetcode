//
//  LongestPalindromie.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/13/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "LongestPalindromie.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = static_cast<int>(s.length()) * 2 +1;
        int* p = new int[len];
        p[0] = 0;
        p[1] = 1;
        p[len - 1] = 0;
        p[len - 2] = 1;
        int c = 1, r = 2;
        for(int i = 2; i < len - 2; ++i) {
            p[i] = (r > i)?min(r - i, p[c * 2 -i]):0;
            while(true) {
                if((i + p[i] + 1) % 2 == 0) {
                    p[i]++;
                }
                else if(s[(i + p[i] + 1)>>1] == s[(i - p[i] - 1)>>1]) {
                    p[i]++;
                }
                else {
                    break;
                }
            }
            if(i + p[i] > r) {
                c = i;
                r = i + p[i];
            }
        }
        int max_p = 0;
        int max_i = 0;
        for (int i = 1; i < len-1; i++) {
            if (p[i] > max_p) {
                max_p = p[i];
                max_i = i;
            }
        }
        delete[] p;
        return s.substr((max_i - max_p)>>1,max_p);
    }
};