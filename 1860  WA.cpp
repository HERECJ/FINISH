//===1860

#include <iostream>
#include <stdio.h>
using namespace std;

int N,M,S;
double V;
int point[222][2];
double x[111],c[222][2];
bool flag;
bool Bellman(){
    int i,j;
    x[S]=V;
    int f;
    for(i=1;i<N;i++){
         f = 0;
         for(j=0;j<2*M;j++){
                if(x[point[j][1]]<(x[point[j][0]]-c[j][1])*c[j][0]){
                    f = 1
                    x[point[j][1]]=(x[point[j][0]]-c[j][1])*c[i][0];
                }
        }
        if(!f) return false;
    }
    for(j=0;j<2*M;j++)
        if(x[point[j][1]]<(x[point[j][0]]-c[j][1])*c[j][0])
            return true;
    return false;
    /*for (i = 1; i < N; i++)
	{
		f = 0;
		for (j = 0; j < 2 * M; j++)
			if (x[point[j][1]] < (x[point[j][0]] - c[j][1])*c[j][0])
				f = 1, x[point[j][1]] = (x[point[j][0]] - c[j][1])*c[j][0];
		if (!f)   return 0;
	}
	for (j = 0; j < 2 * M; j++)
		if (x[point[j][1]] < (x[point[j][0]] - c[j][1])*c[j][0])
			return 1;
	return 0;*/
}


int main(){
    int i;
    int AStart,BEnd;
    double rAB,cAB,rBA,cBA;
    cin >> N>>M>>S>>V;
    cout << N <<" "<<M <<" "<<S<<" "<<V<<endl;
    for(i = 0;i<M;i++){
         cin >> AStart >>BEnd>>rAB>>cAB>>rBA>>cBA;
         point[2*i][0]=AStart;
         point[2*i][1]=BEnd;
         c[2*i][0]=rAB;
         c[2*i][1]=cAB;
         c[2*i+1][0]=rBA;
         c[2*i+1][1]=cBA;
         point[2*i+1][0]=BEnd;
         point[2*i+1][1]=AStart;
    }
    for(i=0;i<111;i++){
        //if(x[i])
            cout<<x[i]<<" ";
    }
    if(Bellman())cout <<"YES";
    else cout << "NO";
    cout << endl;
    for(i=0;i<111;i++){
        if(x[i])
            cout<<x[i]<<" ";
    }

}
