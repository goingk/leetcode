/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (38.02%)
 * Likes:    7056
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 4.2M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), lenMax = 0;
        pair<int, int> output;
        string r;
        vector<vector<int>> v(n, vector<int>(n));
         
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                Palindrome(s, v, i, j, lenMax, r);
            }
        }
       
        return r;
    }
    int Palindrome(string &s, vector<vector<int>> &v, int left, int right, int &lenMaX, string &r){
        int output;
        if(v[left][right] > 0) return v[left][right];
        if(s[left] == s[right]){
            if(right - left > 1){
                int l = Palindrome(s, v, left+1, right-1, lenMaX, r);
                if(l > 0) v[left][right] = l + 2;
            }
            else if(right - left == 1) v[left][right] = 2;
            else if(left == right) v[left][right] = 1;
        }else return 0;
        output = v[left][right];
        if(output > lenMaX){
            lenMaX = output;
            r = string(s.begin()+left, s.begin()+right+1);
        }

        return output;
    }
};
// @lc code=end

