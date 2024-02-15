/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=0;
        int left=0, right=height.size()-1, w, h;
        while(right-left){
            w = right - left;
            h = min(height[right], height[left]);
            water = max(water, h*w);
            if(height[right]>height[left]){
                left++;
            }
            else{
                right--;
            }
        }

        return water;
    }
};
// @lc code=end

