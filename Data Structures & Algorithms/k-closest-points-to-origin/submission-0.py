import heapq
from typing import List

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # 1. Build map: distance^2 -> list of points
        dist_map = {}
        distances = []

        for x, y in points:
            d2 = x * x + y * y  # squared distance
            if d2 not in dist_map:
                dist_map[d2] = []
                distances.append(d2)  # we only push distinct distances into the heap later
            dist_map[d2].append([x, y])

        # 2. Build a min-heap of distances
        heapq.heapify(distances)

        # 3. Pop from heap until we collect k points
        result = []
        while len(result) < k:
            d2 = heapq.heappop(distances)   # smallest distance
            pts = dist_map[d2]              # all points with this distance

            # take points one by one from this bucket
            for p in pts:
                if len(result) < k:
                    result.append(p)
                else:
                    break

        return result