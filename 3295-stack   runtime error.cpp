#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string.h>
#define MAX 101

using namespace std;

int p,q,r,s,t;
char ss[MAX];
bool flag;
stack<int> sta;

void cal(char st){
    int temp;
    int fir,sec;
    switch(st){
        case('p'):
            {
                sta.push(p);
                int pp ;
                pp = sta.top();
                flag = true;
                break;
            }
        case('q'):
            {
                sta.push(q);
                flag = true;
                break;
            }
        case('r'):
            {
                sta.push(r);
                flag = true;
                break;
            }
        case('s'):
            {
                sta.push(s);
                flag = true;
                break;
            }
        case('t'):
            {
                sta.push(t);
                flag = true;
                break;
            }
        case('K'):
            {
                fir = sta.top();
                sta.pop();
                sec = sta.top();
                sta.pop();
                sta.push(fir && sec);
                break;
            }
        case('A'):
            {
                fir = sta.top();
                sta.pop();
                sec = sta.top();
                sta.pop();
                sta.push(fir || sec);
                break;
            }
        case('N'):
            {
                temp = sta.top();
                sta.pop();
                sta.push(!temp);
                break;
            }
        case('C'):
            {
                fir = sta.top();
                sta.pop();
                sec = sta.top();
                sta.pop();
                sta.push((!fir)|| sec);
                break;
            }
        case('E'):
            {
                fir = sta.top();
                sta.pop();
                sec = sta.top();
                sta.pop();
                sta.push(fir == sec);
                break;
            }
    }
    return ;
}

void work(){
    int len;
    len = strlen(ss);
    int i ;
    for (i = len-1 ; i>= 0 ;i--){
        cal(ss[i]);
    }
    int fin;
    fin = sta.top();
    sta.pop();
    if ((sta.empty())&&fin)
        flag = true;
    else flag = false;
}



int main(){
    while (cin >> ss){
        flag = true ;
        p,q,r,s,t = 0 ;
        for(p = 0;p<2;p++){
            for(q = 0;q<2;q++){
                for(r = 0;r<2;r++){
                    for(s = 0;s<2;s++){
                        for (t = 0 ;t<2;t++){
                            work();
                            if (flag == false)
                                break;
                        }
                        if (flag == false)
                            break;
                    }
                    if (flag == false)
                        break;
                }
                if (flag == false)
                    break;
            }
            if(flag == false)
                break;
        }

        if (flag == true) cout << "tautology" << endl;
        else cout << "not" << endl;
    }
}


