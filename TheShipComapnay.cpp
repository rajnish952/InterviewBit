/*
The ship company
The local ship renting service has a special rate plan:
1. It is up to a passenger to choose a ship.
2. If the chosen ship has X (X > 0) vacant places at the given moment, then the ticket for such a ship costs X.
The passengers buy tickets in turn, the first person in the queue goes first, then goes the second one, and so on up to A-th person. You need to tell the maximum and the minimum money that the ship company can earn if all A passengers buy tickets. Input format:
The first argument is a integer A  — the number of passengers in the queue 
The second arugument is a integer B  the number of ships.
The third argument is array of C integers C1,  C2,  ...,  Cm  — Ci stands for the number of empty seats in the i-th ship before the ticket office starts selling tickets.

It is guaranteed that there are at least A empty seats in total.
Output format:
Return a array of length 2 — the maximum and the minimum number of money that the ship company can earn, respectively.
Constraints:
1 ≤ A ≤ 3000
1 ≤ B ≤ 1000
1 ≤ Ci ≤ 1000
Input 1
4 3
2 1 1
Output 1
5 5
Input 2
4 3
2 2 2
Output 2
7 6
Explanation 1:
The sum is maximized if the 1-st person in the queue buys a ticket to the 1-st ship, 
the 2-nd person — to the 2-nd ship, the 3-rd person — to the 3-rd ship, the 4-th person — to the 1-st ship. 
The sum is minimized if the 1-st person in the queue buys a ticket to the 1-st ship, 
the 2-nd person — to the 1-st ship, the 3-rd person — to the 2-nd ship, the 4-th person — to the 2-nd ship.
*/

// Create a max heap for max val and min heap for min val, with each pop add to max and min, and push back top-1 if its greater than 0

vector<int> Solution::solve(int A, int B, vector<int> &C) {
    
    int max_val=0, min_val=0;
    
    priority_queue<int, vector<int>, greater<int>> mi;
    priority_queue<int> mx;
    
    for(auto c : C){
        mi.push(c);
        mx.push(c);
    }
    int temp_min=0, temp_max=0, temp1, temp2;
    while(A--){
        temp1=mx.top();
        mx.pop();
        max_val+=temp1;
        //if(temp_max>max_val)
        //    max_val=temp_max;
        if(temp1-1)
            mx.push(temp1-1);
        
        temp2=mi.top();
        mi.pop();
        min_val+=temp2;
        //if(temp_min<min_val)
        //    min_val=temp_min;
        if(temp2-1)
            mi.push(temp2-1);
    }
    
    vector<int> res;
    res.emplace_back(max_val);
    res.emplace_back(min_val);
    
    return res;
}
