    /*
    Subset
Given a set of distinct integers, S, return all possible subsets.
 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example : If S = [1,2,3], a solution is:
[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
*/

// Using the principleof exclsuion or inclusion each element can either be excluded or included to take an aux array to either include or exclude
// current element and make recursive calls, in order for subsets to be lexicographically sorted use sorted array in begining and sort result as well

void subset_driver(vector<int > &A, int l, vector<int> &aux, vector<vector<int> > &res){
    
    if(l==A.size()){
        res.push_back(aux);
        //sort(res.begin(), res.end());
        return;
    }
    aux.push_back(A[l]);
    subset_driver(A, l+1, aux, res);
    aux.pop_back();
    subset_driver(A, l+1, aux, res);
    
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    int l=0;
    vector<vector<int> > res;
    vector<int> aux;
    sort(A.begin(), A.end()); 
    subset_driver(A, l, aux, res);
    sort(res.begin(), res.end());
    return res;
}
