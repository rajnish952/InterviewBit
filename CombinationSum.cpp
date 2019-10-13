/*
Combination Sum
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. The same repeated number may be chosen from C unlimited number of times.
 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR ... (a1 = b1 AND a2 = b2 AND ... ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, Given candidate set 2,3,6,7 and target 7, A solution set is:
[2, 2, 3]
[7]
*/

// The logic is to either select a element or not select it, if element is selected we don't increase the current index but tht k value is decreased.

void combination_driver(vector<int> &A, int l, vector<int> &aux, vector<vector<int> > &res, int B){
    if(B == 0) // if sum becomes zero push aux array to res
        {
            res.emplace_back(aux);
            return;
        }
        
        if(l == A.size() || B - A[l] < 0) // if current index is at size or sum become negative return
            return;
            
    aux.push_back(A[l]);
    combination_driver(A, l, aux, res, B-A[l]); // Consider the emlement
    aux.pop_back();
    combination_driver(A, l+1, aux, res, B); // Do not consider the element
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    int l=0;
    vector<int> aux;
    vector<vector<int> > res;
    vector<int > a;
    
    sort(A.begin(), A.end());
    a.emplace_back(A[0]);
    for (auto i = 1; i<A.size(); ++i)
        if (A[i-1] != A[i])
            a.emplace_back(A[i]);

    combination_driver(a, l, aux, res, B); // Get only distinct elements 
    //res.erase(std::unique(res.begin(), res.end()), res.end());
    return res;
    
}

