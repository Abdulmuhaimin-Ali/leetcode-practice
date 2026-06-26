class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        map_dict = {}
        res = []

        for i in range(len(nums2)):
            map_dict[nums2[i]] = i
        
        for val in nums1:
            index = map_dict[val]
            found = -1
            for j in range(index + 1, len(nums2)):
                if nums2[j] > val:
                    found = nums2[j]
                    break
            res.append(found)

        return res