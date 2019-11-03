/*
Reverse the String
Given a string A. Return the string A after reversing the string word by word. NOTE:
A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.

Input Format
The only argument given is string A.
Output Format
Return the string A after reversing the string word by word.
For Example
Input 1:
    A = "the sky is blue"
Output 1:
    "blue is sky the"

Input 2:
    A = "this is ib"
Output 2:
    "ib is this"
*/

// Split the string based on space and store in vector, rejoing vector elements in reverse order to form string

string Solution::solve(string A) {
    vector<string> res;
    string result="";
    string word="";
    int flag=0;
    for(auto a: A){
        if(a==' '){ // Traversed char is ' ' reset and push current word
            res.emplace_back(word);
            word="";
            flag=1;
        }else{
            word+=a; // else form word
        }
    }
    res.emplace_back(word); //Push the last word after space
    
    for(int i=res.size()-1; i>0; i--){
        result+=res[i];
        result+=" ";
    }
    result+=res[0]; //concate the first word of vector after space
    if(flag)
        return result;
    else
        return A;
}
