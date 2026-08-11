class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        sizeNums = len(nums)
        ans = [1]*sizeNums

        prefix = 1
        for i in range(sizeNums):
            ans[i] = prefix
            prefix *= nums[i]

        suffix = 1
        for i in range(sizeNums-1, -1, -1):
            ans[i] *= suffix
            suffix *= nums[i]
        
        return ans

        