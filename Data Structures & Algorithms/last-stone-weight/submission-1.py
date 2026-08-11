class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:

        #we want to make a max heap as we are dealing with two heaviest stone
        for i in range(len(stones)):
            stones[i] = -stones[i]

        heapq.heapify(stones)

        while len(stones) >= 2:
            # extract two heaviest
            x = heapq.heappop(stones)
            y = heapq.heappop(stones)

            if x == y:
                continue
            else:
                new_weight = abs(y - x)
                heapq.heappush(stones, -new_weight)
            
        return -stones[0] if stones else 0






        