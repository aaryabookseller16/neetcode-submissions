class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda pair: pair[0])
        merged = [intervals[0]]

        for start, end in intervals:
            lastend = merged[-1][1]

            if start <= lastend:
                merged[-1][1] = max(lastend, end)
            else:
                merged.append([start,end])
            
        return merged
            

        