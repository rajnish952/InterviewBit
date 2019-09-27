/*
Excel Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet. For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
*/

string Solution::convertToTitle(int A) {

    string str="";
    while(A){
        int x=A%26; //give the last character of string, keep on getting the character
        A/=26;
        if(x==0){ // if mod is 0 it means last element is Z and 1 should be subtracted from A/26
            str+='Z';
            A-=1;
        }else{
            str+=char(x+64); //Keep concatenating the character in string
        }
    }

    int i=0, j=str.length()-1; //Reverse String
	while(i<j){
	    char t=str[j];
	    str[j]=str[i];
	    str[i]=t;
	    i++;
	    j--;
	}
	return str;

}
