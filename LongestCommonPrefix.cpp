/*
Longest Common Prefix
Given the array of strings A, you need to find the longest string S which is the prefix of ALL the strings in the array. Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2. For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc". 
Input Format
The only argument given is an array of strings A.
Output Format
Return longest common prefix of all strings in A.
For Example
Input 1:
    A = ["abcdefgh", "aefghijk", "abcefgh"]
Output 1:
    "a"
    Explanation 1:
        Longest common prefix of all the strings is "a".

Input 2:
    A = ["abab", "ab", "abcd"];
Output 2:
    "ab"
    Explanation 2:
        Longest common prefix of all the strings is "ab".
*/

//Sort string vector and then check common value in first and last string only that would give common prefix
string Solution::longestCommonPrefix(vector<string> &A) {
    
    sort(A.begin(), A.end()); // sort in alphabetic order and if order is same then on length 
    /*for(auto a: A){
        cout<<a<<" ";
    }*/
    int min_val=min(A[0].length(), A[A.size()-1].length()); // Min length of string, prefix to check for
    int i=0;
    
    string first=A[0], last=A[A.size()-1];
    while(i<=min_val && first[i]==last[i])
        i++;
    
    return first.substr(0,i);
    
}
