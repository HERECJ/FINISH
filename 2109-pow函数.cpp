#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double n,p,ret;//float���Ա�ʾ�ķ�Χ��10^��-307��-10^��308�����Է�����Ŀ�е���
    while (cin >>n >> p){
        ret=pow(p,1.0/n);//��ѧ����
        cout<< ret<<endl;
    }
}
