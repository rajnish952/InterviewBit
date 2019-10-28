/*
Largest Continuous Sequence Zero Sum
Find the largest continuous sequence in a array which sums to zero. Example:
Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}
*/

vector<int> Solution::lszero(vector<int> &A) {
    
    int n=A.size();
    unordered_map<int,int>m;
    int sum=0;
    int s=-1,e=-1,len=0;
    for(int i=0;i<n;i++){ // For prefix sum check if element is either zero or equla to elemnt already seen
        sum+=A[i];
        if(sum==0){ // if element is 0, return array from 0 to i+1
            s=-1;
            e=i;
            len=e-s;
        }
        else if(m.find(sum)!=m.end()){ // if element already exist len=(current_index)-(index where sum found)
            if((i-m[sum])>len){
            s=m[sum];
            e=i;
            len=e-s;
            } 
            
        }
        else m[sum]=i; // with each sum store index of the sum too
        
        
    }
    vector<int>v;
    s=s+1;
    for(;s<=e;s++)v.push_back(A[s]); // loop through s+1 to end
    return v;
}
