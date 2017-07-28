//1062
/*
注意点
1.有向图，以及如何构图。这个题中谁是节点谁是边谁是边的权重研究了很久，需要好好理解
2.等级的问题。是交易的等级之差，需要穷举。（酋长的等级也不一定是最高的  可以考虑用最短路算法中标记的方法
3.回溯，起点不一定是1物品，是最后要接近1物品
4.最短路算法可能会存在环？

中文题真是题意要理解很久啊。。
*/
#include <iostream>
#include <string.h>

#define MAX 101
#define MAXMAX 111111111111111
using namespace std;

int M,N;//等级差和商品数量

struct{
    int Level;//等级
    int Price;//价格
}Node[MAX];

int weight[MAX][MAX];
bool visit[MAX];//记录第i个节点是否已经被访问
int dist[MAX];//记录最短距离

int dijkstra(){
    int MaxPrice;
    int tmpnode;
    int i,j;

    for(i = 1;i<=N;i++) dist[i] =Node[i].Price;

    for(i =1;i<=N;i++){
        tmpnode = 0;
        MaxPrice = MAXMAX;
        for(j=1;j<=N;j++){
            if(!visit[j] && MaxPrice >dist[j]){
                tmpnode = j;
                MaxPrice = dist[j];
            }
        }

        if (tmpnode ==0) break;
        //cout <<"MAX price : "<< MaxPrice <<endl;

        visit[tmpnode] =true;
        for(j = 1;j <=N ;j++){
            if(!visit[j] && weight[tmpnode][j]){
                if(dist[j]> dist[tmpnode]+weight[tmpnode][j])
                    dist[j]=dist[tmpnode]+weight[tmpnode][j];
            }
        }
    }
    return dist[1];
}

int main(){
    int i,j;
    int Replace;
    int bianhao,jiage;

    memset(Node,0,sizeof(Node));
    memset(weight,0,sizeof(weight));
    memset(visit,false,sizeof(visit));
    memset(dist,MAXMAX,sizeof(dist));

    cin >> M >>N;
    for (i = 0;i<=N;i++){
        weight[i][i] = 0;
    }

    for(i = 1;i<= N;i++){
        cin >> Node[i].Price >> Node[i].Level>>Replace;
        weight[0][i]=Node[i].Price;
        for(j = 0;j<Replace;j++){
            cin >> bianhao>> jiage;
            weight[bianhao][i] = jiage;
        }
    }

    int tmplevel;
    int tmpprice;
    int miniprice = MAXMAX;

    for(i = 1;i<=N;i++){
        tmplevel = Node[i].Level;
        for(j = 1;j<=N;j++){
            if(Node[j].Level>tmplevel || (tmplevel-Node[j].Level)>M)//这个枚举 非常精彩！
                visit[j] = true;
            else visit[j] = false;
        }

        tmpprice = dijkstra();

        if(miniprice > tmpprice) miniprice = tmpprice;

    }
    cout << miniprice<<endl;

}
