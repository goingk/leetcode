/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode.cn/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (44.84%)
 * Likes:    1580
 * Dislikes: 0
 * Total Accepted:    539.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 * 
 * 返回这三个数的和。
 * 
 * 假定每组输入只存在恰好一个解。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,0,0], target = 1
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = 1e7; // 初始化为一个很大的数

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                // 如果找到更接近目标值的和，更新最接近的和
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }
                // 根据当前和与目标值的比较，移动左右指针
                if (currentSum > target) {
                    right--;
                } else if (currentSum < target) {
                    left++;
                } else {
                    // 如果已经等于目标值，直接返回
                    return target;
                }
            }
            // 跳过重复的值
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }

        return closestSum;
    }
};

// @lc code=end

