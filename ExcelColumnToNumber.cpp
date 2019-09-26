/*Excel Column Number
Given a column title as appears in an Excel sheet, return its corresponding column number. Example:
    A -> 1

    B -> 2

    C -> 3

    ...

    Z -> 26

    AA -> 27

    AB -> 28

*/

int Solution::titleToNumber(string A) {

    int r=0;
    for(int i=0;i<A.length();i++){ //Loop through string
        r=r*26+A[i]-64; // Ascii of A is 65 so form integer by r*26+str-64 for A it gives 1
    }

    return r;
}
