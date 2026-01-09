class Solution:
    MOD = 10**9 + 7
    def matmul(self, a, b):
        res = [[0, 0], [0, 0]]
        res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % self.MOD
        res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % self.MOD
        res[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % self.MOD
        res[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % self.MOD
        return res

    def numOfWays(self, n: int) -> int:
        result = [[1, 0], [0, 1]]
        base = [[3, 2], [2, 2]]
        exponent = n - 1

        while exponent > 0:
            if exponent % 2 == 1:
                result = self.matmul(result, base)
            base = self.matmul(base, base)
            exponent //= 2
        
        return int(((result[0][0] + result[1][0] + result[0][1] + result[1][1]) * 6) % self.MOD)
    