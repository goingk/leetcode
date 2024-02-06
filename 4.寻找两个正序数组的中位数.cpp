/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int l = m + n;
        vector<int> nums3(0);
        int odevity = l % 2;
        int i = 0, j = 0;
        double x = 0, y = 0;
        while(i+j <= ceil(l/2)){
            if(i+1<=m){
                x = nums1[i];
            }
            else if(j+1<=n){
                y = nums2[j];
                nums3.push_back(y);
                j++;
                continue;
            }
            if(j+1<=n){
                y = nums2[j];
            }
            else if(i+1<=m){
                x = nums1[i];
                nums3.push_back(x);
                i++;
                continue;
            }
            if(x<=y){
                nums3.push_back(x);
                i++;
            }
            else{
                nums3.push_back(y);
                j++;
            }
        }
        double z;
        if(odevity == 1){
            z = nums3.back();
        }
        else{
            double z1 = nums3.back();
            nums3.pop_back();
            double z2 = nums3.back();
            z = (z1 + z2) / 2;
        }
        return z;
    }
};
// @lc code=end

