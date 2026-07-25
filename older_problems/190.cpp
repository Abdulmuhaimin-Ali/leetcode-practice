class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            // reverse bits
            uint32_t result = 0;
    
            for(uint32_t i = 0; i < 32; i++){
                result <<= 1;
                result |= (n&1);
                n >>= 1;
            }
            // Loop though unsigned int since it is a 32 bit unsigned int
    
            return result;
            //return result
        }
    
    
    };