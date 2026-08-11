class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        merged = []
        new_start, new_end = newInterval
        new_interval_inserted = False

        for current_start, current_end in intervals:

            # new interval is completely before one of the current intervals
            # [new_start ---- new_end]   [current_start ---- current_end]
            if new_end < current_start:
                if not new_interval_inserted:
                    merged.append([new_start, new_end])
                    new_interval_inserted = True
                merged.append([current_start, current_end])

            # new interval is completely after one of the current intervals
            # [current_start ---- current_end]   [new_start ---- new_end]
            elif current_end < new_start:
                merged.append([current_start, current_end])

            # new interval needs to be merged
            else:
                new_start = min(new_start, current_start)
                new_end = max(new_end, current_end)

        # if new interval was never inserted append at the end
        if not new_interval_inserted:
            merged.append([new_start, new_end])

        return merged