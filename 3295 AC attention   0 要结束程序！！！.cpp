#include <iostream>
#include <stack>
#include <string.h>
#define MAX 105

using namespace std;

int p,q,r,s,t;
int len;
char ss[MAX];
bool flag;
stack<int> sta;

void cal(char st){
    int temp;
    int fir,sec;
    switch(st){
        case('p'):
            {
                sta.push(p);
                flag = true;
                break;
            }
        case('q'):
            {
                sta.push(q);
                flag = true;
                break;
            }
        case('r'):
            {
                sta.push(r);
                flag = true;
                break;
            }
        case('s'):
            {
                sta.push(s);
                flag = true;
                break;
            }
        case('t'):
            {
                sta.push(t);
                flag = true;
                break;
            }
        case('K'):
            {
                fir = sta.top();
                sta.pop();
                sec = sta.top();
                sta.pop();
                sta.push(fir && sec);
                break;
            }
        case('A'):
            {
                fir = sta.top();
                sta.pop();
                sec = sta.top();
                sta.pop();
                sta.push(fir || sec);
                break;
            }
        case('N'):
            {
                temp = sta.top();
                sta.pop();
                sta.push(!temp);
                break;
            }
        case('C'):
            {
                fir = sta.top();
                sta.pop();
                sec = sta.top();
                sta.pop();
                sta.push((!fir)|| sec);
                break;
            }
        case('E'):
            {
                fir = sta.top();
                sta.pop();
                sec = sta.top();
                sta.pop();
                sta.push(fir == sec);
                break;
            }
        default: {flag = false; break;}
    }
    return ;
}

void work(){

    int i ;
    for (i = len-1 ; i>= 0 ;i--){
        cal(ss[i]);
    }
    int fin;
    fin = sta.top();
    sta.pop();
    if ((sta.empty())&&fin)
        flag = true;
    else flag = false;
}



int main(){
    while (cin >> ss && ss[0]!= '0'){
        len = strlen(ss);
        flag = true ;
        p,q,r,s,t = 0 ;
        for(p = 0;p<2;p++){
            for(q = 0;q<2;q++){
                for(r = 0;r<2;r++){
                    for(s = 0;s<2;s++){
                        for (t = 0 ;t<2;t++){
                            work();
                            if (flag == false)
                                break;
                        }
                        if (flag == false)
                            break;
                    }
                    if (flag == false)
                        break;
                }
                if (flag == false)
                    break;
            }
            if(flag == false)
                break;
        }

        if (flag == true) cout << "tautology" << endl;
        else cout << "not" << endl;
    }
}
/*²âÊÔÊý¾Ý
p
q
r
s
t
Cpp
App
Kpp
Epp
NNNNNNNNNNNNNNNNNNNAKKKEEKEEKppppppppppp
NNNNNNNNNNNNNCAKKEEEAACKKKKKCEEEACKKEKCCEKAppqqqppppqqpqppppqqppppqqqppppp
NNNNNNNNNNNACKCAKEAAEKCAKECEKKKACAAEAKAKCKKrqqqprpppprpqprqprrppqrqqrqrqppqp
NNNNNNNNCAEACACKEEEKKAEEEEAKKEECACKACECCCEKAECEECCCACrrrrprrqssrprrqpsssrrpsqssqprrqpprrpqrppqqsqqs
NNNNNNNNNNNKAEEACEKKCCCKKAAECACAECAEKKECKAAAECCCKEAACArqpsrstpqsspsppssrpsprstsqspsspptrqrprptstps
NNNNNNNNNNNNEAAECEAEAECKCEAAAEEACAACCKEAKtqptstpttssrptqrtsstpptqtssppp
NNNNNNNNNNNNNNNNNNNCAAAKEEAEACCCACECCCCCCEKCKCAKCpqpssqsppprttrqprspsssttsrprtqq
NNNNNNNNNNNNEEKKCCCACACECEACCKCCAEKKKKCEKCEKEppsrrpqtqrrspqrqrpprtpqpqqrqqqtprp
NNNNCAAEAECKKEKKEAACEAECAEEECCCCEKAKCKKAAEKrrtssrrppprrpstsrqqrrqprqrsprsspsrpsspsq
NNNNNNNNNECCKAAACAKAAECCKAECKEAEKEACCKErstrqpqrtrtrqstqpptprttprtrrqtq
NNAKAKEAKEAEAKACCEECCKKAACECAACACrrtrqtsttstspqrstqrpspqttrpspqsp
NNNEECEACEECKAAKKKCEKECKAKKAAAAAKsrtpprtrqqtpsssrrprtsqtsrpssspt
NNNNNNCEECAKAACEKECAKCCAEECCCAEAEKKKrpqqqsqprqqsqtqstsrpqsqsqsrqsqs
NNNAEAEKEACEECECKCAEAKCEEEKEKEKKCECEqtpssqrptpsqppqpprsqpttqrsqqrqqtrq
CNNNEECEEEKECAAEACAsppsrqpptpspppqqNNNEECEEEKECAAEACAsppsrqpptpspppqq
ANNNEECEEEKECAAEACAsppsrqpptpspppqqNNNEECEEEKECAAEACAsppsrqpptpspppqq
KNNNEECEEEKECAAEACAsppsrqpptpspppqqNNNEECEEEKECAAEACAsppsrqpptpspppqq
ENNNEECEEEKECAAEACAsppsrqpptpspppqqNNNEECEEEKECAAEACAsppsrqpptpspppqq
CNNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqssNNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqss
ANNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqssNNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqss
KNNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqssNNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqss
ENNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqssNNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqss
NCNNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqssNNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqss
NANNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqssNNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqss
NKNNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqssNNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqss
NENNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqssNNNEAKCEKCEAKACECKACCEKCqppppptrqqttptttqtpqss
NNNNEEEEEAAACKEKAAEEAqpptpsqsrqpprssptt
NNNKAKCEECACCEECACEKrtrrsstpqptpstsrsq
NNNNNNNNNCACCCEKEACEACpqrqpsststtpps
NNNNKKCACEACECCssqptqptrrtr
NNNAAAACKECCAKAKACprspqspspsttpttr
NNNECCCECCAAEpqstpspppss
NNNNNCEAECACCEKAEEEppsptpsppprpqrq
AEAAKKEEEKAEAKpqqtpppsssqrqsp
NNAKEKAAKprqrpqpt
NNNAKACAKEKCECKtqppqtpqsqspr
NCEKEEACCCppsstppprp
NNNAEKCEKAEEECEEKEtrqpppqqpppqstpp
NNNNCKEAACAKEKACECCEKstppprrptqqpqqpppp
NNEAKCECKACEEECKprrpqqsppppttqr
NNNNNCKAAAKKEKKKECKECppqrppttpsttrtqtq
NNEKKACCKKACEKErpprsptppppptq
NNNCKECCAEAECAEspqpqpprsptpr
NNNCKECKCEEECstrtppsrtrp
NNKCCKACKAACKprtttttpttpp
NNNNEACCKKEArqpptrppt
NKECKACAptrrrttt
NNAEEEKECAAptpspptqpp
NNNACKEEAAKAKKpsrttqtssrrt
NNKKAKAKEEECACEEtstqqrsptttrprp
CKAKECKKKtttppptptq
NNNCEEEKCECCtsptqqqptp
NAECCAKKCCttttpptpsr
NCEEKCCAErpptpsppt
NKKEEKtppttt
NCKCAECEpttqqttp
NNNNNEEKAAECqqpqpppt
NECAACAECCAACKtrpptpptqtpppp
NNKECKKACrttttrtp
AECAECrrtsptt
0*/


