class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        def calc(nums):
            m = float('-inf')
            res = 1
            for n in nums:
                res *= n
                m = max(m, res)
                if n == 0: res = 1
            return m
        return max(calc(nums), calc(nums[::-1]))