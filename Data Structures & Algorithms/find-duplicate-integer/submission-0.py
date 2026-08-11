class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        #frequency map approach not O(1)
        freq = {}

        for num in nums:
            if num in freq:
                return num
            freq[num] = 1

        return -1 

        