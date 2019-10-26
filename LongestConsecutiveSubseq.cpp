/*
Longest Consecutive Sequence
Given an unsorted array of integers, 
find the length of the longest consecutive elements sequence. Example: Given [100, 4, 200, 1, 3, 2], 
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4. Your algorithm should run in O(n) complexity.
*/

// The logic is to count the streak, if elment-1 already exist in hashmap that means its not begining of streak
// so continue, else count unless you find next val

int Solution::longestConsecutive(const vector<int> &A) {
    
    int ans=0;
    int count=0;
    
    int n=A.size();
    unordered_set<int> s;
    
    for(auto a: A){
        s.insert(a);
    }
    
    for(int i=0;i<n;i++){
        if(s.find(A[i]-1) != s.end()) // Continue as not begining of streak
            continue;
            
        else{
            count=0;
            int x=A[i]; // from current element
            while(s.find(x) != s.end()){ // count till streak continues
                count++;
                x++;
            }
            ans=max(ans, count);
        }
    }
    return ans;
}
