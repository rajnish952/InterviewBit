/*
Ways to Decode
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it. 
Input Format:
The first and the only argument is a string A.
Output Format:
Return an integer, representing the number of ways to decode the string.
Constraints:
1 <= length(A) <= 1e5
Example :
Input 1:
    A = "8"

Output 1:
    1

Explanation 1:
    Given encoded message "8", it could be decoded as only "H" (8).

    The number of ways decoding "8" is 1.

Input 2:
    A = "12"

Output 2:
    2

Explanation 2:
    Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).

    The number of ways decoding "12" is 2.
*/

// Intution is to either an elemtn could be added individually or in pair, so the f(n)=f(n-1)+f(n-2)

int Solution::numDecodings(string A) {
    
    int n=A.size();
    int count[n+1];  // Create Memoization of N+1 elements
    count[0] = 1; 
    count[1] = 1; 

    if(A[0]=='0')   // if element is 0, out of range
         return 0; 
         
    for (int i = 2; i <= n; i++) // for elements of size 2 and greater
    { 
        count[i] = 0; // set count to 0 initially
        if (A[i-1] > '0') // if the last digit is > 0, take its count into picture, when added individually
            count[i] = count[i-1]; 

        if (A[i-2] == '1' ||  // now if the second last digit exist and its in proper range i.e pair of elements
              (A[i-2] == '2' && A[i-1] < '7') ) 
            count[i] += count[i-2]; // add value of i-2 to the count as it already have count for i-1
    } 
    return count[n]; 
}
