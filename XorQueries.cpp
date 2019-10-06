/*
Xor queries
You are given an array (containing only 0 and 1) as element of N length. Given L and R, you need to determine value of XOR of all elements from L to R (both inclusive) and number of unset bits (0's) in the given range of the array. Input
First argument contains the array of size N containing 0 and 1 only (1<=N<=100000). 

Second argument contains a 2D array with Q rows and 2 columns, each row represent a query with 2 columns representing L and R. 

(1<=Q<=100000), (1<=L<=R<=N).
Output
Return an 2D array of Q rows and 2 columns i.e the xor value and number of unset bits in that range respectively for each query.
Examples Input
1 0 0 0 1
2 4
1 5 
3 5
Output
0 3
0 3
1 2
Explanation Testcase 1-
In the given case the bit sequence is of length 5 and the sequence is 1 0 0 0 1. For query 1 the range is (2,4), and the answer is (array[2] xor array[3] xor array[4]) = 0, and number of zeroes are 3, so output is 0 3. Similarly for other queries.
*/

//Logic is to make prefix arrays for Xor and Zero and check the lower limit

vector<vector<int> > Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    
    vector<vector<int> > res;
    
    int n=A.size();
    int num_zero[n];
    num_zero[0]=(A[0]==0)?1:0;
    for(int i=1;i<n;i++){
        num_zero[i]=(A[i]==0)?num_zero[i-1]+1:num_zero[i-1];
    }
    /*for(auto a:num_zero){
        cout<<a<<" ";
    }*/
    int pre_xor[n];
    int Xor=0;
    for(int i=0;i<n;i++){
        pre_xor[i]=Xor^A[i];
        Xor=pre_xor[i];
    }
    for(int i=0;i<B.size();i++){
        int L=B[i][0]-1;
        int R=B[i][1]-1;
        vector<int> temp;
        if(L==0){
            temp.push_back(pre_xor[R]);
            temp.push_back(num_zero[R]);
        }else{
            temp.push_back(pre_xor[R]^pre_xor[L-1]);
            temp.push_back(num_zero[R]-num_zero[L-1]);   
        }
        
        res.push_back(temp);
    }
    return res;
}