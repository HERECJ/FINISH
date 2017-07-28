//===2602
#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX 1000000
using namespace std;

//const int  MAX = 1000000;
char ss1[MAX],ss2[MAX];
char temp;
char Result[MAX];
int main(){

    int N;
    int i;
    int cc;//进位

    cin >> N;
    getchar ();
    for(i= N-1;i>=0;i--){
        ss1[i]= getchar();
        getchar();
        ss2[i]=getchar();
        getchar();
        ss1[i] -= '0';
        ss2[i] -= '0';
    }
    cc =0;
    memset(Result,0,sizeof(char)*MAX );
    for(i=0;i<N;i++){
        temp = ss1[i]+ss2[i]+cc;
        cc = temp / 10;
        Result[i] = (temp %10);
    }
    if(cc != 0){
        Result[i] += cc;
    }
    i = N-1;

    for(i;i>=0;i--){
            temp = Result[i]+'0';
            cout<<temp;
    }
}
