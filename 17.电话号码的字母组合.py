#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#

# @lc code=start
class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        corr = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        letters = []
        for digit in digits:
            letters.append(corr[int(digit) - 2])
        ans = self.f(letters)
        return ans

    def f(self, letters:list[str]):
        aph = []
        if len(letters) == 0:
            return aph
        aphnext =self.f(letters[1:])
        for letter in letters[0]:
            if len(aphnext) > 0:
                for a in aphnext:
                    aph.append(letter + a)
            else:
                aph.append(letter)
        return aph
# @lc code=end

