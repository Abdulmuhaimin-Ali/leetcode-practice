class Solution {
public:
    int nextNumber(int n){
        // sum of squares of digits of n
        int sum = 0;
        while(n > 0){
            int num = n % 10;
            sum += num * num;
            n = floor(n / 10); // go to next number
        }
        return sum;
    }

    bool isHappy(int n) {
        
        int slow = n;
        int fast = n;

        while(true){
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));

            if(slow == fast){
                break;
            }
        }
        return slow == 1? true : false;
    }
};

// The pigeonhole principle employed in this problem is pretty interesting.