//------3078

#include <iostream>
#include <string.h>
#include  <list>
#define MAX 101

using namespace std;

int cases;
int c;
char s1[MAX],s2[MAX];
string result;
int n;
string ss;
list <string> S12;
bool Match(){
    if(ss.compare(result)==0){
        return 1;
    }
    else return 0;
}
bool No_Repeat(){
    list<string>::iterator it;
    for(it = S12.begin();it!=S12.end();it++){
        if (ss == *it)
            return false;
    }
    return true;
}

int work(){
    int i;
    //int len =0;
    ss = "";
    n++;
    //cout << "work "<<endl;
    for(i=0;i<c;i++){
        //cout<<"loop "<<i<<endl;
        ss += s2[i];
        ss += s1[i];
    }
    //cout << ss <<endl;
    if(Match()){
        return n;
    }
    else if(No_Repeat()){
    S12.push_back(ss);

    for(i=0;i<c;i++){
        s1[i]=ss[i];
        s2[i]=ss[i+c];
    }
    work();
    }
    else if(!No_Repeat()){
        return -1;
    }
}

int main(){

    int i;
    int thecase = 0;

    cin >> cases;
    while((cases--)&&(cases <1001)){
        thecase ++;
        memset(s1,0,sizeof(char)*MAX);
        memset(s2,0,sizeof(char)*MAX);
        S12.clear();
        n = 0;
        cin >>c;
        for(i=0;i<c;i++){
            cin >>s1[i];
            //cout << s1[i]<<" ";
        }
        for(i=0;i<c;i++){
            cin >> s2[i];
            //cout << s2[i]<<" ";
        }
        cin >> result;
        cout<<thecase<<" "<<work()<<endl;
    }
}
