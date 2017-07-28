#include <stdio.h>
#include <string.h>

char s[6];
char map[6][6];
const int wq = 999999;
int result = 999999;

int judge(){
    int sta = map[0][0];
    int i,j;
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            if(map[i][j] != sta)
            return 0;
        }
    }
    return 1;
}

int flip(int x,int y){
    map[x][y] = !map[x][y];
    if(x-1 >= 0)
        map[x-1][y]= !map[x-1][y];
    if(x+1 < 4)
        map[x+1][y]= !map[x+1][y];
    if(y-1 >=0)
        map[x][y-1]= !map[x][y-1];
    if(y+1 < 4)
        map[x][y+1]= !map[x][y+1];

}

int dfs(int x,int y,int t){//x 和 y表示点的位置 t表示变换的次数

    if( judge())
    {
        if (result > t)
            result = t ;

        return 0 ;
    }

    if ((x >=4) || (y >= 4)){
        return 0;
    }

    int nx,ny;
    nx = (x+1)%4;
    ny = y + (x+1)/4;//nx ny 是下一个点

    dfs(nx,ny,t);
    flip(x,y);

    dfs(nx,ny,t+1);
    flip(x,y);

    return 0;
}



int main(){

    int i,j;
    for (i=0;i<4;i++){
        scanf("%s",s);

        for(j=0;j<4;j++){
            if (s[j]== 'b')
                map[i][j]=0;
            else map[i][j]=1;
        }
    }//地图初始化 读进服务台

    dfs(0,0,0);
    if (result < wq){
        printf("%d",result);
    }
    else printf("Impossible");

    return 0;
}
