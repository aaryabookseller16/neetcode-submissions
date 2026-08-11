class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # make a hash map which stores complement -> index mappings
        complement = {}
        for idx, num in enumerate(nums):
            comp = target - num
            if comp not in complement:
                complement[num] = idx
            else:
                return [complement[comp], idx]

        return []