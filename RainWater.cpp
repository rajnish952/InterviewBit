/* Rain Water Trapped
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 
Input Format
The only argument given is integer array A.
Output Format
Return the total water it is able to trap after raining..
For Example
Input 1:
    A = [0,1,0,2,1,0,1,3,2,1,2,1]
Output 1:
    6
Explaination 1:

    In this case, 6 units of rain water (blue section) are being trapped. */

int min(int a, int b){
    return a<b ? a:b;
}

int max(int a, int b){
    return a>b ? a:b;
}

int Solution::trap(const vector<int> &A) {
    int len=A.size();
    int res=0;
    int prefix_max[len];
    int suffex_max[len];
    
    prefix_max[0]=A[0];
    suffex_max[len-1]=A[len-1];
    for(int i=1;i<len;i++){
        prefix_max[i] = max(prefix_max[i-1],A[i]);
    }
    
    for(int i=len-2;i>=0;i--){
        suffex_max[i] = max(suffex_max[i+1],A[i]);
    }
    
    for(int i=0;i<len;i++){
        int water_ati = 0;
        if(A[i] >= min(prefix_max[i], suffex_max[i]))
            water_ati=0;
        else
            water_ati = min(prefix_max[i], suffex_max[i]) - A[i];
        
        res+=water_ati;
    }
    
    return res;
    
}