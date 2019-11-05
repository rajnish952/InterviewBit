/*
Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations. Questions to ask the interviewer :
Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor. 
*/

// To get min value push the elements in another stack, if elm(s)<=elm(min) Push

stack<int> s, mins;
MinStack::MinStack()
{ //Constructor to empty stacks
    while (!s.empty())
        s.pop();
    while (!mins.empty())
        mins.pop();
}

void MinStack::push(int x)
{                                        //Push values to stacks
    if (mins.empty() || x <= mins.top()) //if x<=min push
        mins.push(x);
    s.push(x);
}

void MinStack::pop()
{
    if (s.empty())
        return;
    if (s.top() == mins.top())
    { // if element is removed from s remove from min too
        s.pop();
        mins.pop();
    }
    else
        s.pop();
}

int MinStack::top()
{
    if (s.empty())
        return -1;
    return s.top();
}

int MinStack::getMin()
{ //top returns the min
    if (mins.empty())
        return -1;
    return mins.top();
}
