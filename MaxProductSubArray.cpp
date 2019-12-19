/*
Max Product Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest product. Return an integer corresponding to the maximum product possible. Example :
Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]

*/

// The intution behind is to track max and min value so far, in case current value is < 0, swap max and min(as product of two -ve no would give max value)

int Solution::maxProduct(const vector<int> &A) {
    
    int maxi=A[0];
    int mini=A[0];
    int max_pro=A[0];
    int n=A.size();
    for(int i=1;i<n;i++){
        if(A[i]<0)
            std:swap(maxi, mini);
            
        maxi=max(maxi*A[i], A[i]);
        mini=min(mini*A[i], A[i]);
        
        max_pro=max(maxi, max_pro);
    }
    
    return max_pro;
}
