/*
Rotated Sorted Array Search
Suppose a sorted array is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ). You are given a target value to search. If found in the array, return its index, otherwise return -1. You may assume no duplicate exists in the array.
Input : [4 5 6 7 0 1 2] and target = 4
Output : 0
*/

// Check he pivot element, element after which array is sorted, so if mid <= r -> rgiht subarray would be sorted
// else left subarray would be sorted, keep reducing the space and search element

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int low=0, high=A.size();
    
    while(low<=high){
         int mid = (low+high)/2;
        if(A[mid] == B)
            return mid;
            
        // Check which side of the array is sorted - left or right of mid
        bool flag = false;
        if(A[low] <= A[mid])
            flag = true;
        // If flag is true it means that the left side of the array is sorted
        if(flag){
            if(B >= A[low] && B < A[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else{
            if(B > A[mid] && B <= A[high])
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}
