#include <iostream>
using namespace std;

int  these[40]={0};//不超过20,最多包含40个字符
int  NumOfCases;
int  len,LEN;
int  those[40]={0};

int WInvert(){
   int s = 1;
   while(1){
        if(these[len]==0)
        {
            len++;
            s += WInvert();
        }
        else
        {
            those[LEN++]=s;
            len++;
            return s;
        }
   }
}


int main(){
    int Nu;//the number of right
    int i,j,pre;
    int Counts;
    int NumberOfArray;//数组中的计数

    cin >> NumOfCases;
    while(NumOfCases--){
        //cout << NumOfCases << " change "<<endl;
        cin >> Nu;
        //cout <<NumOfCases<<"  test  "<<endl ;
        Counts=0;
        //cout <<NumOfCases<<"  test1  "<<endl ;
        NumberOfArray=0;
        //cout <<NumOfCases<<"  test2  "<<endl ;
        //these[40]={0};
        //cout <<NumOfCases<<"  test3  "<<endl ;
        for(i = 0;i <Nu;i++){
            pre = Counts;
            cin >> Counts;
            pre = Counts - pre;
            for(j=0;j<pre;j++){
                these[NumberOfArray++]=0;
            }
            these[NumberOfArray++]=1;
        }

        //for(i=0;i< 2*Nu;i++)
          //cout << these[i];

          //cout<< endl;
          len =0;
          LEN=0;
        WInvert();
        for(i = 0;i<Nu;i++){
            cout << those[i]<<" ";
        }
        cout << endl;
    }

}

