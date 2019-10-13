/*
Subsets II
Given a collection of integers that might contain duplicates, S, return all possible subsets.
 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example : If S = [1,2,2], the solution is:
[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]
*/

// If duplicates areallowed check is the elemnt is already considered or not, can do either by using hasmap, count or simply sorting and checking next Elements

void subsetsWithDup_driver(vector<int> &A, int l, vector<int> &aux, vector<vector<int> > &res){
    res.emplace_back(aux);
    for (int i = l; i < A.size(); ++i)
		{
		    if (i == l || A[i] != A[i - 1]) { // Check if duplicate elements are present
				aux.emplace_back(A[i]);
				subsetsWithDup_driver(A, i+1, aux, res);
				aux.pop_back();
			}
		}
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    
    int l=0;
    vector<int> aux;
    vector<vector<int> > res;
    sort(A.begin(), A.end());
    vector<int> a;
    if(A.size()==0)
    {
        res.emplace_back(aux);
        return res;
    }
    subsetsWithDup_driver(A, l, aux, res);
    sort(res.begin(), res.end());
    return res;
}
