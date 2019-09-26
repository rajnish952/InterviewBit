/*
Reverse integer
Reverse digits of an integer. Example1: x = 123, return 321 Example2: x = -123, 
return -321 Return 0 if the result overflows and does not fit in a 32 bit signed integer
*/

int Solution::reverse(int A) {
    
    long int res=0;
    while(A){
        res=res*10+(A%10);
        A/=10;
    }
    if(res>INT_MAX || res<INT_MIN) //Check Overflow
        return 0;
    else
        {
            //res=int(res); //take int of result
            return (A<0)?-res:res; //if number was -ve return -ve res
        }
        
    
}
