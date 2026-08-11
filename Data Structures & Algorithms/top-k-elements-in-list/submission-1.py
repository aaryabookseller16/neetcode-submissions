class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # element -> frequency mapping
        numsDict = defaultdict(int)
        for n in nums:
            numsDict[n] += 1

        #sort by the frequency with the most frequent ones at the top
        sorted_dict = dict(sorted(numsDict.items(), key=lambda x: x[1], reverse=True))

        #store keys in a list because we want to return the keys
        sorted_keys = list(sorted_dict.keys()) 

        # return top k
        answer = []
        for i in range(k):
            answer.append(sorted_keys[i])
        
        return answer



            