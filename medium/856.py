class Solution:
    def score_sub(self, s: str, start: int, end: int) -> int:
        if start + 1 == end:
            return 1

        t = 0
        cur = 0
        for i in range(start + 1, end):
            if s[i] == '(': cur += 1
            else: cur -= 1
            if cur < 0:
                t = 1
                break

        cur = 0
        last = start if t else start + 1
        total = 0
        for i in range(start if t else start + 1, end+1 if t else end):
            if s[i] == '(': cur += 1
            else: cur -= 1
            if cur == 0 and last != i:
                total += self.score_sub(s, last, i)
                last = i + 1

        return total if t else total * 2

    def scoreOfParentheses(self, s: str) -> int:
        return self.score_sub(s, 0, len(s)-1)
        
