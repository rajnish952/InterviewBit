/*
Single Number II
Given an array of integers, every element appears thrice except for one which occurs once. Find that element which does not appear thrice. Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? Example :
Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4
*/

// Logic is to check all the numbers bit wise, if the bit is set increment cnt1 else increment cnt0,
// now one of the counts would not be a multiple of 3 i.e. it would represent the bit of unique number so
// form the number by pow(2, i) * 0 or pow(2, i) * 1 where i is the ith bit value.

int Solution::singleNumber(const vector<int> &A) {
    int res=0;
    int nb = sizeof(int) * 8;
    for(int i=0; i<nb; i++){
        int cnt0=0, cnt1=0;
        for(int j=0;j<A.size();j++){
            int temp = A[j] & (1<<i);
            if(temp){
                cnt1++;
            }else{
                cnt0++;
            }
        }
        if(cnt0%3 !=0 ){
            res = res + (std::pow(2, i)*0);
        }else{
            res = res + (std::pow(2, i)*1);
        }
    }
    return res;
}
