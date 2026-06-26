class Solution(object):
    def groupAnagrams(self, strs):
        
        Map = {}

        for i in range(len(strs)):
            cFreq = [0] * 26
            # make 
            for c in strs[i]:
                cFreq[ord(c) - ord('a')] += 1
            key = ','.join(str(x) for x in cFreq)
            print(key)
            if key in Map:

                Map[key].append(strs[i])
            else:
                Map[key] = [strs[i]]

        return list(Map.values())
    


    
        