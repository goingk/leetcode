/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int n = s.size(), ans = 0;
        unordered_map<char, int> roman{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for(int i = n-1; i >= 0; i--) {
            char c = s[i];
            ans += roman[c];
            if(i-1 >= 0 && roman[c] > roman[s[i-1]]) {
                ans -= roman[s[i-1]];
                i--;
            }
        }

        return ans;
    }
};
// @lc code=end

