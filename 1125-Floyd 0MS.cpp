//1125
//Floyd  最短路径
#include <iostream>
#include <string.h>

#define MAX 100
//#define INF 0x3f3f
#define INF 11111
using namespace std;

int Dist[MAX][MAX];
int PathMem[MAX][MAX];
int N;
void Floyd(){
    int k,i,j;
    for(k = 1;k<=N;k++)
        for(i = 1;i<=N;i++)
            for(j = 1;j<=N;j++){
                if(Dist[i][j] > Dist[i][k] + Dist[k][j]  && i != j)
                {
                    Dist[i][j] = Dist[i][k] +Dist[k][j];
                }
    }
}

int main(){
    int i,j,pp;
    int node,path;

    while(cin >> N && N !=0){
        //memset(Dist,INF,sizeof(Dist));
        for(i = 0;i<MAX;i++)
            for(j = 0;j<MAX;j++)
                Dist[i][j] = INF;
        for(i= 1;i<=N;i++){
            cin >> pp;
            for(j = 1;j<=pp;j++){
                cin >>node>> path;
                Dist[i][node] = path;
            }
            for(j = 1;j<=N;j++)
                if(i == j) Dist[i][i] = 0;
        }
        Floyd();
        /*for (i =1;i<=N;i++){
            for(j = 1;j<=N;j++){
                cout <<i<<" -> "<<j<<" : "<<Dist[i][j]<<endl;
            }
        }*/
        int pos,maxtime,Fatest;
        Fatest = INF;
        pos = 0;
        for(i = 1;i<=N;i++){
            maxtime = 0;
            for(j = 1;j<=N;j++){
                if ( i != j && maxtime < Dist[i][j])
                    maxtime = Dist[i][j];
            }
            //cout << i <<" + "<<maxtime<<" + fatest"<<Fatest<<endl;
            if(Fatest > maxtime){
                Fatest = maxtime;
                pos = i;
            }
            //cout <<"pos : "<<pos<<" i: "<<i <<endl;
        }
        if(pos){
            cout << pos<<" "<<Fatest<<endl;
        }
        else if (pos == 0){
            cout <<"disjoint"<<endl;
        }
    }
    return 0;
}
