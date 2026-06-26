class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        my_map = {}
        stk = []
        res = []

        for item in nums2[::-1]:
            while stk and stk[-1] <= item:
                stk.pop()   
            if(stk):
                my_map[item] = stk[-1]
            stk.append(item)

        for item in nums1:
            val = my_map.get(item) if item in my_map else -1 
            res.append(val)
        
        return res

