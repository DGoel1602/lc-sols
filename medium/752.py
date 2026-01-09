from collections import deque

class Solution:
    def openLock(self, deadends, target):
        target_rep = int(target)

        deads = [False] * 10000
        for d in deadends: deads[int(d)] = True

        q = deque()
        pows = [1, 10, 100, 1000]

        q.append((0, 0))

        while q:
            cur, dist = q.popleft()
            if cur == target_rep: return dist
            if deads[cur]: continue
            deads[cur] = True

            for p in pows:
                orig = (cur // p) % 10
                q.append((cur + (-p * 9 if orig == 9 else p), dist + 1))
                q.append((cur + (p * 9 if orig == 0 else -p), dist + 1))

        return -1
