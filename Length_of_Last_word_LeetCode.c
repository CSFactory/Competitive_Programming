https://leetcode.com/problems/length-of-last-word/


Approach: start from last word (in reverse fashion)

int lengthOfLastWord(char * s){
    int count = 0;
    int len = strlen(s);
    for(int i=len-1;i>=0;i--){
        if(s[i]!=' '){
            count++;
        }
       else if((s[i]==' ') && (s[i+1]!=' ') && (i!=len-1)){
           break;
       }
    }
    return count;
}
