# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        lca = [root]

        def search(root):
            if not root:
                return
            
            lca[0] = root

            if root is p or root is q:
                return
            elif root.val < p.val and root.val < q.val: #search right subtree
                search(root.right)
            elif root.val > p.val and root.val > q.val: # search left subtree
                search(root.left)
            else: #if is confined in the middle

                return
        
        search(root)
        return lca[0]


            

       