#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double n,p,ret;//float可以表示的范围是10^（-307）-10^（308）可以放下题目中的数
    while (cin >>n >> p){
        ret=pow(p,1.0/n);//数学化简
        cout<< ret<<endl;
    }
}
