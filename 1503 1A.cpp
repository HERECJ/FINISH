//===1503
#include <iostream>
#include <string.h>
using namespace std;

char Input[100];
char Result[105];

int main(){
    string s;
    string Out;
    int len,c;//c是进位
    int i,j;
    memset(Result,0,sizeof(char)*105);

    while(cin >> s){
        memset(Input,0,sizeof(char)*100);
        c = 0;
        if(s.compare("0")==0)break;
        else{
            j=0;
            len = s.size();
            for(i=len-1;i>=0;i--){
                Input[j] = s[i]-'0';
                //cout <<s[i]<<"输入"<< Input[j]<<" "<<endl;
                j++;
            }
            //plus
            for(i=0;i<105;i++){
                Result[i] =Result[i] + Input[i]+c;
                c = Result[i]/10;
                Result[i]=Result[i]%10;
                //cout << Result[i]<< ":";
            }

        }
    }
    i = 104;
    j = 0 ;
    while(Result[i]==0){
            //cout <<"loop"<<endl;
        i--;
    }
    for(i;i>=0;i--){
        Out[j]=Result[i]+'0';
        cout << Out[j];
        j++;
    }
   // cout <<endl<<"next sum"<<endl;
    //Out[j]= '\0';
    //cout << Out ;

}
