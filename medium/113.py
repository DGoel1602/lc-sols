# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        all = []

        def df(cur, path, s):
            if s == targetSum and cur.left is None and cur.right is None:
                all.append(path[:])
            
            if cur.left is not None:
                path.append(cur.left.val)
                df(cur.left, path, s + cur.left.val)
                path.pop()

            if cur.right is not None:
                path.append(cur.right.val)
                df(cur.right, path, s + cur.right.val)
                path.pop()

        if root is not None:
            df(root, [root.val], root.val)
        
        return all