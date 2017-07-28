#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;
int Maps[MAX][MAX];
int Maps_Robot[MAX][MAX];
int orien[4]={0,1,2,3};//N.E.S.W
int xx[4]={0,1,0,-1};
int yy[4]={-1,0,1,0};
int n=0;//robot¼ÆÊý

int row,column;

struct{
    int ID;
    int x;
    int y;
}Rob[MAX];



void move_rob(int Count){
    int x_des;
    int y_des;
    int d;
    int k=-1;
    x_des = Rob[Count].x;
    y_des = Rob[Count].y;
    d = Maps[x_des][y_des];
    //cout << x_des<<" "<<y_des<<endl;
    //cout << d <<" destination N0 E1 S2 W3"<<endl;
    x_des += xx[d];
    y_des += yy[d];
    //cout << "NEW: "<<x_des<<" "<<y_des<<endl;
    if((x_des == 0)||(x_des > column)||(y_des ==0)||(y_des >row)){
        n++;
        cout << n<<" step(s) to exit"<<endl;
    }
    else if(Maps_Robot[x_des][y_des] == -1){
        n++;
        Rob[n].ID=n;
        Rob[n].x = x_des;
        Rob[n].y = y_des;
        Maps_Robot[x_des][y_des] = n;
        move_rob(n);
    }
    else if(Maps_Robot[x_des][y_des] != -1){
        k = Maps_Robot[x_des][y_des];

        n++;
        cout << k << " step(s) before a loop of "<<n-k<< " step(s)"<<endl;
    }
}


int main(){

    int start;
    char m;
    int i,j;
    while ((cin >> row >> column >> start)&&(row)&&(column)&&(start)){
        n = 0;
        memset(Maps,-1,sizeof(int)*MAX*MAX);
        memset(Maps_Robot,-1,sizeof(int)*MAX*MAX);
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
                cin>>m;
                switch(m){
                    case('N'):Maps[j+1][i+1]=0;break;
                    case('E'):Maps[j+1][i+1]=1;break;
                    case('S'):Maps[j+1][i+1]=2;break;
                    case('W'):Maps[j+1][i+1]=3;break;
                    default:Maps[j+1][i+1]=-2;break;
                }
                //cout << Maps[j+1][i+1]<<" ";
            }
        }//cout <<endl;
        Rob[0].ID = 0;
        Rob[0].x=start;
        Rob[0].y=1;
        Maps_Robot[start][1] = 0;
        move_rob(0);

    }
}
