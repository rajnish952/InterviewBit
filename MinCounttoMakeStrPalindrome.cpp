/*
Minimum Characters required to make a String Palindromic
Given an string A. The only operation allowed is to insert characters in the beginning of the string. Find how many minimum characters are needed to be inserted to make the string a palindrome string. 
Input Format
The only argument given is string A.
Output Format
Return the minimum characters that are needed to be inserted to make the string a palindrome string.
For Example
Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".

Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".
*/

// The logic is to check if a string is palindrome, else remove last elemnt of string and inc cound unless string is palindrome or exhausted

int Solution::solve(string A) {
    int count=0, flag=0;
    while(A.length()){
        string a(A); // make copy of string
        reverse(a.begin(), a.end());
        if(a == A){ //check if a string is palindrome
            flag=1;
            break;
        }else{
            count++; //Increment count
        }
        
        A.erase(A.begin()+A.length()-1); // remove last element of current string
        
    }
    if(flag)
        return count;
}
