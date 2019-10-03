/*
Reverse Bits
Reverse bits of an 32 bit unsigned integer Example 1: x = 0,
          00000000000000000000000000000000
=>        00000000000000000000000000000000
return 0 Example 2: x = 3,
          00000000000000000000000000000011
=>        11000000000000000000000000000000
return 3221225472 Since java does not have unsigned int, use long
*/

// if i th bit is set in original no. rev val would have (n-1) -i th bit set
unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int no_of_bits = sizeof(A) * 8;
    unsigned int rev=0;
    for(int i=0;i<no_of_bits;i++){
        int temp = A & (1 << i);
        if(temp){
            rev |= (1 << (no_of_bits - 1) -i) ;
        }

    }
    return rev;
}
