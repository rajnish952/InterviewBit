/*
All Unique Permutations
Given a collection of numbers that might contain duplicates, return all possible unique permutations. Example : [1,1,2] have the following unique permutations:
[1,1,2]
[1,2,1]
[2,1,1]
*/

//The logic is to fix one elemnt and swap the remainings recursively.
// Also check if the element is already picked continue to pick only disticnt elements

void permutation(vector<int> &A, int l, vector<vector<int> > &res){
    
    if(l==A.size()){
        res.push_back(A);
        return;
    }
    unordered_set<int> val;
    for(int i=l;i<A.size();i++){
        if(val.find(A[i]) != val.end())
            continue;
        val.insert(A[i]);
        swap(A[l], A[i]);
        permutation(A, l+1, res);
        swap(A[l], A[i]);
    }
    
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int l=0;
    vector<vector<int> > res;
    permutation(A, l, res);
    return res;
}
