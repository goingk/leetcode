/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int n;

        if(10 > x && x >= 0) return true;
        if(x < 0 || x > static_cast<long long>(pow(2, 31)-1)) return false;
        long long y = abs(x);

        for(n = 1; ; n++){
            if(y/long(pow(10, n)) == 0) break;
        }
        for(int k = 1; k <= n-k; k++){
            int a = y / long(pow(10, n-k)) % 10;
            int b = y % int(pow(10, k)) / int(pow(10, k-1));
            if(a != b) return false;
        }

        return true;
    }
};
// @lc code=end

