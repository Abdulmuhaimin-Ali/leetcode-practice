class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if(k == len(num)):
            return "0"
        
        stk = []
        res = ""

        for i in range(len(num)):

            while k and stk and num[stk[-1]] > num[i]:
                stk.pop()
                k-=1
            
            stk.append(i)
        while k > 0 and stk:
            stk.pop()
            k-=1
        for i in stk:
            res += num[i]
        res = res.lstrip('0')



        return res if res else "0"


