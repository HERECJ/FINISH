//3295  bellman ford
#include <iostream>
#include <string.h>


using namespace std;
int dist[1001];
int Max_Dist = 10000001;
int Index;
struct{
    int Start,End,Weight;
}Edge[5202];

bool BellmanFord(int Number){
    bool flag;
    int i,j;
    for(j = 0;j<Number -1;j++){
            flag = false;

    for(i = 0;i< Index;i++){
        if (dist[Edge[i].End]>dist[Edge[i].Start]+Edge[i].Weight){
            dist[Edge[i].End]=dist[Edge[i].Start]+Edge[i].Weight;
            flag = true;
        }
    }
        if (!flag) break;

    }

    for(i = 0;i<Index;i++){
        if (dist[Edge[i].End]>dist[Edge[i].Start]+Edge[i].Weight)
            return true;
    }
    return false;
}


int main(){
    int NumberOfFarm;
    int Nn,Mm,Ww;

    int i,j;

    cin >> NumberOfFarm;
    while(NumberOfFarm--){
        memset(dist,Max_Dist,sizeof(dist));
        cin >> Nn>>Mm>>Ww;
        Index = 0;
        for(i = 0;i<Mm;i++){
            cin >> Edge[Index].Start>>Edge[Index].End>>Edge[Index].Weight;
            Edge[Index+1].Start=Edge[Index].End;
            Edge[Index+1].End=Edge[Index].Start;
            Edge[Index+1].Weight=Edge[Index].Weight;
            Index += 2;
        }
        /*for(i = 0;i<Mm*2;i++){
            cout << Edge[i].Start <<" + "<<Edge[i].End<<" + "<<Edge[i].Weight<<endl;
        }*/
        for(j = 0;j<Ww;j++){
            cin >> Edge[Index].Start>>Edge[Index].End>>Edge[Index].Weight;
            Edge[Index].Weight = -Edge[Index].Weight;
            Index++;
        }

        if(BellmanFord(Nn))
            cout<< "YES"<<endl;
        else cout <<"NO"<<endl;
    }
}
