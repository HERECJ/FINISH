#include <stdio.h>
#include <string.h>

#define wq 999999
char s[6];
char map[6][6];
int result = 999999;
int ansx[wq],ansy[wq],zx[wq],zy[wq];


int judge(){

    int i,j;
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            if(map[i][j] != 0)
            return 0;
        }
    }
    return 1;
}

int flip(int x,int y){
    int a;
    map[x][y] = !map[x][y];
    for (a = 0 ; a < 4 ; a++){
        map[x][a]= !map[x][a];
        map[a][y]= !map[a][y];
    };
}

int dfs(int x,int y,int t){//x 和 y表示点的位置 t表示变换的次数
    int m;

    if( judge())
    {
        if (result > t){
            result = t ;
            for (m = 0 ; m <result;m++){
                ansx[m]=zx[m];
                ansy[m]=zy[m];
            }
        }
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

    zx[t] =x+1;
    zy[t] = y+1;

    dfs(nx,ny,t+1);
    flip(x,y);

    return 0;
}



int main(){

    int i,j,n;
    for (i=0;i<4;i++){
        scanf("%s",s);

        for(j=0;j<4;j++){
            if (s[j]== '+')
                map[i][j]=1;//关是1
            else map[i][j]=0;
        }
    }//地图初始化 读进服务台

    dfs(0,0,0);
    printf("%d\n",result);
    for (n = 0;n<result;n++)
        printf("%d %d\n",ansx[n],ansy[n]);


    return 0;
}
