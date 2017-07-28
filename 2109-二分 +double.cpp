#include <iostream>
#include <math.h>
#define eps 1e-8
using namespace std;

double n,p,res;
int len;

void inputsize(){
    int i=0;
    double p0;
    p0=p;
    //int m = n;

    while (p0 - 1.0> eps){
        i++;
        p0 = p0/10;
    }
    len = int ((i/n)+0.99);//��������λ�� ���ٶ��������ķ�Χ
    //cout << len << endl;
}

double work(){//���ַ� �Ƚ�
    double _left,_right;
    _left=pow(10.0,(len-1)*1.0);
    _right=pow(10.0,len*1.0)-1;
    //cout << _left <<":"<<_right<<endl;
    double  _mid=0;
    while (_left + eps < _right){
            //cout << _left<<' '<<_right<<endl;
        _mid = (_left+_right)/2;
        if ( pow(_mid,n) - p < 0){
            _left =_mid+eps;
            }
        else{
                if (pow(_mid,n) -p > 0)
                    _right = _mid-eps;
            }
        }
        return _mid;

}

int main(){

    while (cin >> n >> p){
        inputsize();
        res = work();
        cout<<res<< endl;
        //int re = (int)res;
        //cout << re <<endl;
    }
}
