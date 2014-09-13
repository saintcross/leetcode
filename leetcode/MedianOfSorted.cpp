//
//  MedianOfSorted.cpp
//  leetcode
//
//  Created by Jingwei MIAO on 9/13/14.
//  Copyright (c) 2014 Jingwei MIAO. All rights reserved.
//

#include "MedianOfSorted.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int l = (m + n + 1) >> 1;
        int r = (m + n + 2) >> 1;
        if(l == r) {
        	return getkth(A, m ,B, n, l);
        }
        else {
        	return (getkth(A, m ,B, n, l) + getkth(A, m, B, n, r)) / 2.0;
        }
    }
    
    int getkth(int s[], int m, int l[], int n, int k){
        if (m > n) {
        	return getkth(l, n, s, m, k);
        }
        if (m == 0) {
            return l[k - 1];
        }
        if (k == 1) {
        	return min(s[0], l[0]);
        }
        int i = min(m, k >> 1), j = min(n, k >> 1);
        if (s[i - 1] > l[j - 1])
            return getkth(s, m, l + j, n - j, k - j);
        else
            return getkth(s + i, m - i, l, n, k - i);
    }
};