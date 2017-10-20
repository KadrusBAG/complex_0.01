#include <iostream>

using namespace std;

struct complex_t{
    float real;
    float imag; 
};

bool proverka(complex_t ch){
    char op1, op2, op3;
    bool f=1;
    if(stream>>op1){
        if(op1=='('){
            if(stream>>ch.real){
                if(stream>>op2){
                    if(op2==','){
                        if(stream>>ch.imag){
                            if(stream>>op3){
                                if(op3==')'){
                                }
                                else{
                                    f=0;
                                }
                            }
                            else{
                                f=0;
                            }
                        }
                        else{
                            f=0;
                        }
                    }
                    else{
                        f=0;
                    }
                }
                else{
                    f=0;
                }
            }
            else{
                f=0;
            }
        }
        else{
            f=0;
        }
    }
    else{
        f=0;
    }
    return f;
}

int main(){
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
