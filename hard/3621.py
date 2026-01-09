class Solution:
    def to_ll(self, avail):
        res = 0
        for i in range(6, -1, -1):
            if avail[i]: res += (2 ** i)
        return res
    
    def pc(self, num):
        popc = 0
        for i in range(0, 64):
            if (num >> i) % 2 == 1:
                popc += 1
        return popc
            
    def popcountDepth(self, n: int, k: int) -> int:
        if k == 0:
            return 1
        if k == 5:
            return 0

        seen_before = set()
        all_lengths = set()

        if k == 1:
            all_lengths = set([1])
        elif k == 3:
            seen_before = set([32, 1, 2, 64, 4, 8, 16])
            all_lengths = set([64, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 17, 18, 20, 23, 24, 27, 29, 30, 32, 33, 34, 36, 39, 40, 43, 45, 46, 48, 51, 53, 54, 57, 58, 60])
        elif k == 2:
            seen_before = set([1])
            all_lengths = ([32, 1, 2, 64, 4, 16, 8])
        elif k == 4:
            seen_before = set([1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 17, 18, 20, 23, 24, 27, 29, 30, 32, 33, 34, 36, 39, 40, 43, 45, 46, 48, 51, 53, 54, 57, 58, 60, 6])
            all_lengths = set([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64])

        m = 0
        for i in range(1, 64):
            if (n >> i) % 2 == 1: m = i    

        cur = n
        first = -1
        for i in range(k):
            cur = self.pc(cur)
            if cur == 1:
                first = i
                break
                
        res = 0
        if first == k-1 and cur == 1:
            res += 1

        for bits in all_lengths:
            if bits in seen_before: continue
            cur = bits
            if cur == 1:
                res -= 1
                
            for i in range(m, -1, -1):
                if (n >> i) % 2 == 1:
                    if cur < 0: break
                    if cur > i: continue

                    num = math.factorial(i)
                    den = math.factorial(cur) * math.factorial(i-cur)
                    cur -= 1

                    res += num / den
        

        return int(res)
        