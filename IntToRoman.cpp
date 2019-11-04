/*
Integer To Roman
Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version
 Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using "See Expected Output" For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. 

Input Format
The only argument given is integer A.
Output Format
Return a string denoting roman numeral version of A.
Constraints
1 <= A <= 3999
For Example
Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"
*/

// Create string matrix storing roman values, now for number/k add corresponding string
string Solution::intToRoman(int A)
{

    string ret = "";
    if (A <= 0)
        return ret;
    string roman[4][10] = {{"0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                           {"0", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                           {"0", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                           {"0", "M", "MM", "MMM"}};
    int k = 1000;

    for (int i = 3; i >= 0; --i)
    {
        if (A / k != 0)
            ret += roman[i][A / k];
        A %= k;
        k /= 10;
    }

    return ret;
}
