/*
Evaluate Expression
Evaluate the value of an arithmetic expression in Reverse Polish Notation. Valid operators are +, -, *, /. Each operand may be an integer or another expression. 
Input Format
The only argument given is character array A.
Output Format
Return the value of arithmetic expression formed using reverse Polish Notation.
For Example
Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9

Input 2:
    A = ["4", "13", "5", "/", "+"]
Output 2:
    6
Explaination 2:
    +: ()+()
    /: ()+(() / ())
    5: ()+(() / (5))
    1: ()+((13) / (5))
    4: (4)+((13) / (5))
    (4)+((13) / (5)) = 6
*/

// To evaluate postfix expression, if element is operator pop top two elements and push back the result, else push the value

int Solution::evalRPN(vector<string> &A) {
    stack<int> nums;
    for(auto a: A){
        if(a == "+"){
            int x=int(nums.top());
            nums.pop();
            int y=int(nums.top());
            nums.pop();
            nums.push(x+y);
        }else if(a == "-"){
            int x=int(nums.top());
            nums.pop();
            int y=int(nums.top());
            nums.pop();
            nums.push(y-x);
        }else if(a== "*"){
            int x=int(nums.top());
            nums.pop();
            int y=int(nums.top());
            nums.pop();
            nums.push(x*y);
        }else if(a== "/"){
            int x=int(nums.top());
            nums.pop();
            int y=int(nums.top());
            nums.pop();
            nums.push(y/x);
        }else{
            nums.push(stoi(a));
        }
    }
    
    return nums.top();
}
