class Solution:
    def sort(self, a: str, b: str):
        if a + b > b + a:
            return -1
        else:
            return 1

    def largestNumber(self, nums: List[int]) -> str:
        res = list(sorted(map(str, nums), key = functools.cmp_to_key(self.sort)))
        if res[0] == "0": return "0"
        return ''.join(res)
        