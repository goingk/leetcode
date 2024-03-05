#
# @lc app=leetcode.cn id=14 lang=python3
#
# [14] 最长公共前缀
#

# @lc code=start
class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        prefix:str
        
        if not strs:
            return ""
        for i in range(len(strs[0])):
            prefix = strs[0][:i+1]
            for s in strs:
                if s[:i+1] != prefix:
                    return strs[0][:i]
        return strs[0]
# @lc code=end

