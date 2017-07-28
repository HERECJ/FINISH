#include <iostream>

using namespace std;
int s,d;
int res;
int main(){

    int i,m,t;
    while(cin >> s >> d){
    i = 0;
    m = s * 5;
    t = s+d;
    while(m>0 && i<= 5){
        m = m -t;
        i++;
        //cout << m<<endl;
    }
    if ( i <= 3){
        res = 2*m + 2*s;
    }
    if ( i == 4){
        res = 2*m + s -d ;
    }
    if ( i == 5){
        res = -5;
    }
    if (res > 0) cout << res <<endl;
    else cout << "Deficit"<<endl;
}
}


