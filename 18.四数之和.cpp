/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode.cn/problems/4sum/description/
 *
 * algorithms
 * Medium (36.68%)
 * Likes:    1861
 * Dislikes: 0
 * Total Accepted:    549.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a],
 * nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 * 
 * 
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * 
 * 
 * 你可以按 任意顺序 返回答案 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> output;

        sort(nums.begin(), nums.end());
        for(int i=0; i<len-3; i++) {
            for(int j=i+1; j<len-2; j++) {
                long long diff = static_cast<long long>(target) - nums[i] - nums[j];
                int left = j + 1, right = len - 1;
                while(left < right) {
                    long long twosum = nums[left] + nums[right];
                    if(twosum < diff) {
                        left++;
                    } else if(twosum > diff) {
                        right--;
                    } else {
                        output.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while(nums[left] == nums[left-1] && left < right) {
                            left++;
                        }
                        while(nums[right] == nums[right+1] && left < right) {
                            right--;
                        }
                    }
                } 
                while(nums[j] == nums[j+1] && j<len-2) {
                    j++;
                }
            }
            while(nums[i] == nums[i+1] && i<len-3) {
                i++;
            }
        }
        
        return output;
    }
};
// @lc code=end

