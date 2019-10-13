/*
Combination Sum II
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. Each number in C may only be used once in the combination.
 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example : Given candidate set 10,1,2,7,6,1,5 and target 8, A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

// Same logic as combination 1

void combination_driver(vector<int> &A, int l, vector<int> &aux, vector<vector<int> > &res, int B){
    if(B == 0)
        {
            res.emplace_back(aux);
            return;
        }
        
        if(l == A.size() || B - A[l] < 0)
            return;
            
        for(int i=l;i<A.size();i++){
            if(i-1>=l && A[i]==A[i-1]) // Check Duplicate elements
                continue; 
            
            aux.emplace_back(A[i]);
            combination_driver(A, i+1, aux, res, B-A[i]);
            aux.pop_back();
        }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    int l=0;
    vector<int> aux;
    vector<vector<int> > res;
    sort(A.begin(), A.end());
    combination_driver(A, l, aux, res, B);
    return res;
    
}

