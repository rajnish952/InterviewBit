/*
Smallest sequence with given Primes
Given three prime number(p1, p2, p3) and an integer k. Find the first(smallest) k integers which have only p1, p2, p3 or a combination of them as their prime factors. Example: Input :
Prime numbers : [2,3,5]
k : 5 If primes are given as p1=2, p2=3 and p3=5 and k is given as 5, then the sequence of first 5 integers will be:
 Output:
{2,3,4,5,6} Explanation :
4 = p1 * p1 ( 2 * 2 ) 6 = p1 * p2 ( 2 * 3 ) Note: The sequence should be sorted in ascending order
*/

// Using property os set as set is always internally sorted, insert first 3 value in set
// pick top value from set, erase it and take its product with A, B, C and push it to res set, do this D times
// Evantually we will get first D prime products

vector<int> Solution::solve(int A, int B, int C, int D) {
    
    set<int> s;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    
    vector<int> res;
    while(D--){
      int temp=*s.begin();
      s.erase(s.begin());
      
      res.emplace_back(temp);
      
      int p1=temp*A;
      int p2=temp*B;
      int p3=temp*C;
      
      s.insert(p1);
      s.insert(p2);
      s.insert(p3);
    }
    return res;
}
