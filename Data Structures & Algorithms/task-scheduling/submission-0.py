class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        
        #get the frequency of all the elements
        count = Counter(tasks)

        #make a max heap
        maxHeap = [-cnt for cnt in count.values()]
        heapq.heapify(maxHeap)

        #keep track of time
        time = 0
        
        #double ended queue to keep track of count and time when the same task can be executed next
        q = deque()

        while maxHeap or q:
            time += 1

            if maxHeap:
                cnt = heapq.heappop(maxHeap)
                cnt += 1
                if cnt != 0:
                    q.append([cnt, time + n])

            if q and q[0][1] == time:
                heapq.heappush(maxHeap, q.popleft()[0])

        return time
                


        