class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.min_heap = nums
        heapq.heapify(self.min_heap)

        # keep only k largest elements
        while len(self.min_heap) > k:
            heapq.heappop(self.min_heap)
        

    def add(self, val: int) -> int:
        if len(self.min_heap) < self.k:
            heapq.heappush(self.min_heap, val)
        elif val > self.min_heap[0]:
            # replace smallest of the k largest
            heapq.heapreplace(self.min_heap, val)

        # the root of the heap is the kth largest
        return self.min_heap[0]
        
