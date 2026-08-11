class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.max_diameter = 0

        def dfs(node):
            if not node:
                return 0
            #left + right is the height of the present node
            left = dfs(node.left) 
            right = dfs(node.right)
            self.max_diameter = max(self.max_diameter, left + right)
            return 1 + max(left, right) # 1 + height of children

        dfs(root)
        return self.max_diameter