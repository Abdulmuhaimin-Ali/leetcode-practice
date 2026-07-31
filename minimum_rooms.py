"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""
import heapq

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:

        if len(intervals) == 0:
            return 0

        if len(intervals) == 1:
            return 1
        
        intervals.sort(key=lambda interval: interval.start)

        max_meeting_rooms = 1

        interval_heap = []

        for i, interval in enumerate(intervals):
            if interval_heap:
                if interval_heap[0][0] <= interval.start:
                    # pop top and add new meeting
                    heapq.heappop(interval_heap)

            heapq.heappush(interval_heap, (interval.end, interval.start))
            max_meeting_rooms = max(max_meeting_rooms, len(interval_heap))
            

        return max_meeting_rooms