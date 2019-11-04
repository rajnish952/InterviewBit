/*
Roman To Integer
Given a string A representing a roman numeral. Convert A into integer. A is guaranteed to be within the range from 1 to 3999. NOTE: Read more details about roman numerals at Roman Numeric System 
Input Format
The only argument given is string A.
Output Format
Return an integer which is the integer verison of roman numeral string.
For Example
Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20
×*/

// Create jmap of character to int, if charat(i) >= charAt(i+1) add int val else subtract

int Solution::romanToInt(string A) {

    int res=0;
    map<char, int> mp = {{'I', 1}, {'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
    for(int i=0;i<A.length();i++){
        if(mp[A[i]]>=mp[A[i+1]])
            res+=mp[A[i]];
        else
            res-=mp[A[i]];
    }
    
    return res;
    
}
