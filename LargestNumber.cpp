/*
Largest Number
Given a list of non negative integers, arrange them such that they form the largest number. 
For example: Given [3, 30, 34, 5, 9], the largest formed number is 9534330. Note: The result may be very large, so you need to return a string instead of an integer.
*/

// Conevrt number to string use comaprator to sort based on a+b > b+an

string Solution::largestNumber(const vector<int> &A)
{

    vector<string> res;

    for (auto a : A)
    {
        res.emplace_back(to_string(a));
    }
    sort(res.begin(), res.end(), [](string a, string b) { return (a + b) > (b + a); }); //Lambda comparator to return sorted string based on a+b
    string result = "";
    for (auto a : res)
    {
        result += a;
    }

    int i = 0;
    while (result[i] == '0') // if entire string is "0"
    {
        i++;
    }
    if (i == result.length())
        result = "0";

    return result;
}
