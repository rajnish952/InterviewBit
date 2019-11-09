/*
N integers containing only 1,2 and 3
Given an integer A. Find and Return first positive A integers in ascending order containing only digits 1,2 and 3. NOTE: all the A integers will fit in 32 bit integer. 
Input Format
The only argument given is integer A.
Output Format
Find and Return first positive A integers in ascending order containing only digits 1,2 and 3.
Constraints
1 <= A <= 29500
For Example
Input 1:
    A = 3
Output 1:
    [1, 2, 3]

Input 2:
    A = 7
Output 2:
    [1, 2, 3, 11, 12, 13, 21]
*/

// Push everything to a queue, and deque element to form new elemnts and enque back them to queue
// Corner cases wouldbe to push 1,2,3 to vector first then form other elements with them to maintain order

vector<int> Solution::solve(int A) {
    
    vector<int> res;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    
    
    res.emplace_back(1);
    res.emplace_back(2);
    res.emplace_back(3);
    
    if(A<=3){
        vector<int > temp;
        for(int i=0;i<A;i++){
            temp.emplace_back(res[i]);
        }
        return temp;
    }
    
    while(true){
        int t=q.front();
        q.pop();
        string str=to_string(t);
        
        res.emplace_back(stoi(str+"1"));
        if(res.size()==A)
            break;
        q.push(stoi(str+"1"));
        
        res.emplace_back(stoi(str+"2"));
        if(res.size()==A)
            break;
        q.push(stoi(str+"2"));
        
        res.emplace_back(stoi(str+"3"));
        if(res.size()==A)
            break;
        q.push(stoi(str+"3"));
    }
    sort(res.begin(), res.end());
    return res;
}
