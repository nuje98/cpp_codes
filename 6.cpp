class Solution {
public:
    bool isPowerOfFour(unsigned int n) {
    	// n shouldn't be zero, n should have just one bit set, AND of n & 0xAAAAAAAA should be zero
        return n != 0 && ((n&(n-1)) == 0) && !(n & 0xAAAAAAAA); 
    }
};
