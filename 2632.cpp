#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int Orien[4]={0,1,2,3};//分别对应N,E,S,W
int EW_Len,NS_Len;
int NumOfCases;
int NumOfRobots,NumOfOrders;
int Flag=0;

int Maps[101][101];
int x_des[4]={0,1,0,-1};
int y_des[4]={1,0,-1,0};

struct {
    int EW_LOCATION;
    int NS_LOCATION;
    int OR;//方位
}Rob[101];

void Fun_Forward(int n,int Step){
    int m;
    int x,y;
    int d;
    x = Rob[n].EW_LOCATION;
    y = Rob[n].NS_LOCATION;
    d = Rob[n].OR;
    Maps[x][y]=0;
    //cout <<"robot: "<<n<<"x:"<<x <<"y:"<<y <<" "<<d<<endl;
    for(m = 1 ;m <=Step ;m++){
        x += x_des[d];
        y += y_des[d];
        //cout << m <<" count " << x<<" "<<y <<endl;
        if ((x >EW_Len )||(y > NS_Len)||(x<1)||(y<1)){
            Flag = 1;
            cout << "Robot "<< n << " crashes into the wall"<<endl;
            break;
        }
        else if ((Maps[x][y] != 0)&&(Maps[x][y] != n)){
            //cout <<"maps  "<<Maps[x][y]<<"x: "<<x<<" y: "<<y<<endl;
            Flag = 1;
            cout << "Robot "<< n << " crashes into robot "<<Maps[x][y]<<endl;
            break;
        }
    }
    if (Flag == 0){
        Rob[n].EW_LOCATION = x;
        Rob[n].NS_LOCATION = y;
        Maps[x][y]= n;
        //cout << "New Map location x:"<<x<<" y:"<<y<<" the robot:"<<n<<endl;
        /*cout <<"68+46: "<<Maps[68][46]<<endl;
        cout <<"14+46: "<<Maps[14][46]<<endl;
        cout <<"16+46: "<<Maps[16][46]<<endl;
    */
    }


}


void Rob_Move(int n,char ac,int len){
    switch(ac){
        case('R'):{
            Rob[n].OR = ( Rob[n].OR+len)%4;
            //cout << "OK turn Right!" <<endl;
            break;
        }
        case('L'):{
            Rob[n].OR = ((Rob[n].OR + 4)-len%4)%4;
            //cout << "OK turn Left!!" <<endl;
            break;
        }
        case('F'):{
            Fun_Forward(n,len);
            break;
        }
    }
}



int main(){

    int i,j,k;
    char des;
    int Robot_Move;
    char Action;
    int Repeat;
    int x,y;
    cin >> NumOfCases;
    while(NumOfCases--){
        memset(Maps,0,sizeof(int)*101*101);
        cin >> EW_Len >> NS_Len;
        cin >>NumOfRobots >>NumOfOrders;
        for(i=0;i<NumOfRobots;i++){
            cin >> x >> y>>des;
            Maps[x][y]=i+1;
            //cout << Maps[x][y]<<" location robot "<<endl;
            Rob[i+1].EW_LOCATION = x;
            Rob[i+1].NS_LOCATION = y;
            switch(des){
                case('N'):{
                    Rob[i+1].OR=0;
                    break;
                }
                case('E'):{
                    Rob[i+1].OR=1;
                    break;
                }
                case('S'):{
                    Rob[i+1].OR=2;
                    break;
                }
                case('W'):{
                    Rob[i+1].OR=3;
                    break;
                }
                default:{
                    Rob[i+1].OR = -1;
                }
            }
            //cout << Rob[i+1].EW_LOCATION<<" + "<<Rob[i+1].NS_LOCATION<<" + "<<Rob[i+1].OR<<endl;
        }
        Flag =0 ;
        for(j=0;j<NumOfOrders;j++){
            cin >> Robot_Move >> Action >> Repeat;
            if(Flag == 0){
            Rob_Move(Robot_Move,Action,Repeat);
            }
        }
        if(Flag == 0){
            cout << "OK"<<endl;
        }
    }
}
