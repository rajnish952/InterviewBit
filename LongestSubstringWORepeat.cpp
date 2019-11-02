/*
Longest Substring Without Repeat
Given a string, find the length of the longest substring without repeating characters. Example: 
The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

// Logic is to store everything in a map, unless a repeat is found is repeat is found clear the map and start checking from the next position where repeat was found

int Solution::lengthOfLongestSubstring(string A) {
    
    int max_length=INT_MIN;
    int s=0, e=A.length(), count=0;
    map<int, int> um;
    while(s<e){ //traverse entire string
        
        if(um.find(A[s]) == um.end()){ // if eleemnt not seen previously, push in map with its index
            um[A[s]]=s;
            count++;
            s++;
            if(count>max_length){
                max_length=count;
            }
        }else{ // if repeat, start checking from index where repeat found+1, and clear the map to store seen elemnts again
            s=um.find(A[s])->second+1;
            count=0;
            um.clear();
        }
    }
    return max_length;
}
