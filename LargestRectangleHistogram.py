class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # going to solve this problem using a montonic stack

        stack = []
        heights.append(0)
        maxArea = 0


        for i in range(len(heights)):
           
            if stack and heights[i] <= heights[stack[-1]]:
                while stack[-1]:
                   
                    h = heights[stack[-1]] 
                    stack.pop()

                    left = stack[-1] if stack else -1
                    width = i - left - 1
                    maxArea = max(maxArea, (i - left - 1) * h)


            stack.append(i)
        return maxArea
