//===2389
#include <iostream>
#include <string.h>

#define MAX 100
using namespace std;

char ss1[40],ss2[40];
char Result[MAX];
string Out;
int main(){
    string s1,s2;
    int len1,len2;
    int i,j=0;
    int cc=0;//进位

    memset(Result,0,sizeof(char)*MAX);
    cin >> s1>>s2;
    if((s1.compare("0")==0)||(s2.compare("0")==0)) {
        cout << "0";
    }
    else{
    len1 = s1.size();
    len2 = s2.size();
    for(i=len1-1;i>=0;i--){
        ss1[j]=s1[i]-'0';
        //cout << ss1[j]+'0';
        j++;
    }
    j = 0;
    for(i=len2-1;i>=0;i--){
        ss2[j]=s2[i]-'0';
        //cout <<ss2[j]+'0';
        j++;
    }

    for(i=0;i<len2;i++){//低位开始的
        cc=0;
        for(j=0;j<=len1;j++){
            Result[i+j] += (ss1[j]*ss2[i]+cc);
            cc = Result[i+j]/10;
            Result[i+j]=Result[i+j]%10;
        }
    }
    i = MAX-1;
    j=0;
    while(Result[i]==0) i--;
    for(i;i>=0;i--){
        Out[j]= Result[i]+'0';
        cout << Out[j];
        j++;
    }
    }
}
