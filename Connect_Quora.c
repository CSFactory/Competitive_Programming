/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char disp[7][8];
    int j;
    int loop;
    int t,l;
    int x,z;
    int matin(int k, int c){
       
        for(t=6; t>0; t--){
               
                if((c%2!=0) && (disp[t][k] != 'r') && (disp[t][k] != 'y')){
                    disp[t][k] = 'r';
               
                 //test
                 if(((disp[t][k-1]=='r')&&(disp[t][k-2]=='r')&&(disp[t][k-3]=='r')) || ((disp[t-1][k]=='r')&&(disp[t-2][k]=='r')&&(disp[t-3][k]=='r')) || ((disp[t-1][k-1]=='r')&&(disp[t-2][k+2]=='r')&&(disp[t-3][k-3]=='r')) || ((disp[t+1][k+1]=='r')&&(disp[t+2][k+2]=='r')&&(disp[t+3][k+3]=='r'))
                  || ((disp[t][k+1]=='r')&&(disp[t][k+2]=='r')&&(disp[t][k+3]=='r')) || ((disp[t+1][k]=='r')&&(disp[t+2][k]=='r')&&(disp[t+3][k]=='r'))){
                     printf("RED %d \n",c);
                     exit(0);
                     
                 }
                    break;
                }
                else if((c%2==0) && (disp[t][k] != 'r') && (disp[t][k] != 'y')){
                    disp[t][k] = 'y';
                  //  printf("yk=%d ,t=%d\n",k,t);
                    if(((disp[t][k-1]=='y')&&(disp[t][k-2]=='y')&&(disp[t][k-3]=='y')) || ((disp[t-1][k]=='y')&&(disp[t-2][k]=='y')&&(disp[t-3][k]=='y')) || ((disp[t-1][k-1]=='y')&&(disp[t-2][k+2]=='y')&&(disp[t-3][k-3]=='y')) || ((disp[t+1][k+1]=='y')&&(disp[t+2][k+2]=='y')&&(disp[t+3][k+3]=='y'))
                  || ((disp[t][k+1]=='y')&&(disp[t][k+2]=='y')&&(disp[t][k+3]=='y')) || ((disp[t+1][k]=='y')&&(disp[t+2][k]=='y')&&(disp[t+3][k]=='y'))){
                     printf("YELLOW %d \n",c);
                     exit(0);
                 }
                    break;
                }
        }
    }
    int count = 0;
    for(loop=0;loop<42;loop++){
        scanf("%d", &j);
        count++;
        matin(j,count);
    }

    return 0;
}
