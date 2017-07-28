#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

#define M 1001
using namespace std;

int in_number;
int d;

struct Location
{//岛屿坐标
    int islx;
    int isly;
}isl[M];

struct rader{
    double Right;
    double Left;
}Rader[M],temp;

bool com(rader a,rader b){
    return a.Left < b.Left;
}


int work(){
    int n;
    n = 1 ;
    temp = Rader[0];
    int q;
    for(q=1;q<in_number;q++){
        if (temp.Right > Rader[q].Right){
            temp = Rader[q];
        }
        else if (temp.Right < Rader[q].Left){//用右边的更新
            n++;
            temp = Rader[q];

        }
    }
    return n ;
}

int main(){
        int ca = 0;
        int a ;
        double len;

        cin >> in_number >> d;
        while(in_number || d){

            bool flag =false;
            for(a = 0 ; a < in_number;a++){
                cin >> isl[a].islx >> isl[a].isly;
                if ((d<0)||(isl[a].isly>d)||(isl[a].isly < 0)){
                    flag = true;
                }
            }
            cout << "Case "<< ++ca <<": ";
            if (flag)
                cout << -1 << endl;
            else{
                int p ;
                for(p = 0 ;p<in_number;p++){

                    len = sqrt(d*d-isl[p].isly*isl[p].isly);
                    Rader[p].Right= isl[p].islx + len;
                    Rader[p].Left = isl[p].islx - len;
                }

                sort(Rader,Rader+in_number-1,com);
                /*for(p = 0;p<in_number;p++){
                    cout << Rader[p].Left << " ";
                }
                //IslSort();//从左到右排序
                */
                int W;
                W= work();
                cout << W << endl;
            }
            cin >> in_number >> d;
        }



}
