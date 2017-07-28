//2253
//坐标
/*
1.给的是坐标
2.理解最短距离的含义
3.三位小数
4.双向图

最小生成树！！
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 201
#define MAXCOST 11111111
using namespace std;

struct {
    int x;
    int y;
}Stone[MAX];
double dist[MAX][MAX];
double lowcost[MAX];
bool addnew[MAX];

double Prim(int Nn){
    int i,j;
    double Mini_Dist;
    int Start = 1;
    int Node;
    double Mem_Max_Dist = 0.0;
    for(i = 1;i<= Nn;i++){
        lowcost[i] = dist[Start][i];
    }
    addnew[Start] = true;

    for(i = 2;i<=Nn;i++){
        Mini_Dist = MAXCOST;
        Node = -1;
        for(j = 2;j<=Nn;j++){
            if(!addnew[j]  && lowcost[j])
            if(Mini_Dist > lowcost[j]){
                Mini_Dist = lowcost[j];
                Node = j;
            }
        }
        if(Node != -1){
            addnew[Node] =true;

            if(Mem_Max_Dist < Mini_Dist) Mem_Max_Dist = Mini_Dist;
            if(Node == 2) return Mem_Max_Dist;

            for(j=2;j<=Nn;j++){
                if(lowcost[j] > dist[Node][j]  &&  !addnew[j])
                lowcost[j] = dist[Node][j];
            }
        }

    }
    return Mem_Max_Dist;
}

int main(){
    int N;//the counts of stones
    int i,j;
    int tmp;
    double frog;
    int Index =1;
    while(cin >> N){
        if(N!=0){
        memset(Stone,0,sizeof(Stone));
        memset(dist,MAXCOST,sizeof(dist));
        memset(lowcost,0,sizeof(lowcost));
        memset(addnew,false,sizeof(addnew));
        cin >> Stone[1].x>>Stone[1].y;
        cin >> Stone[2].x>>Stone[2].y;
        for(i = 3;i<N+1;i++){
            cin >> Stone[i].x >> Stone[i].y;
        }
        for(i=1;i<=N;i++){
            for(j = 1;j<=N;j++)
                if(i==j) dist[i][j]=0;
                else{
                    tmp = (Stone[j].y-Stone[i].y)*(Stone[j].y-Stone[i].y)+(Stone[j].x-Stone[i].x)*(Stone[j].x-Stone[i].x);
                    dist[i][j] = sqrt(tmp);
                    //cout <<"dist["<<i<<"]["<<j<<"] : "<<dist[i][j]<<endl;
                }
        }
        frog = Prim(N);
        printf("Scenario #%d\n",Index++);
        printf("Frog Distance = %.3f\n\n",frog);
        }
        else break;
    }
}
