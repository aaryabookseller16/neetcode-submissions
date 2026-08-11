class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        strDict = {} 
        
        # 1. Group the indices of anagrams by their sorted string key
        for idx, s in enumerate(strs):
            sortStr = "".join(sorted(s))
            if sortStr not in strDict:
                strDict[sortStr] = []
            strDict[sortStr].append(idx)
            
        answer = []
        
        # 2. Iterate through the dictionary values (the lists of indices)
        for indices in strDict.values():
            group = []
            for idx in indices:
                group.append(strs[idx]) # Grab the original word using the index
            answer.append(group) # Add the completed group to our final answer
            
        return answer
