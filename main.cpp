#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct complex_t{
    float real;
    float imag; 
};

complex_t add(complex_t ch1, complex_t ch2){
    complex_t ch;
    ch.real=ch1.real+ch2.real;
    ch.imag=ch1.imag+ch2.imag;
    return ch;
}

complex_t sub(complex_t ch1, complex_t ch2){
    complex_t ch;
    ch.real=ch1.real-ch2.real;
    ch.imag=ch1.imag-ch2.imag;
    return ch;
}

complex_t mul(complex_t ch1, complex_t ch2){
    complex_t ch;
    ch.real=ch1.real*ch2.real-ch1.imag*ch2.imag;
    ch.imag=ch1.imag*ch2.real+ch1.real*ch2.imag;
    return ch;
}

complex_t div(complex_t ch1, complex_t ch2){
    complex_t ch;
    ch.real=(ch1.real*ch2.real+ch1.imag*ch2.imag)/(ch2.real*ch2.real+ch2.imag*ch2.imag);
    ch.imag=(ch1.imag*ch2.real-ch1.real*ch2.imag)/(ch2.real*ch2.real+ch2.imag*ch2.imag);
    return ch;
}

bool read(istringstream & stream,complex_t & ch){
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

void write(complex_t ch){
    cout<<endl<<"("<<ch.real<<","<<ch.imag<<")"<<endl;
}

int main(){
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
    complex_t ch1; complex_t ch2; complex_t ch;
    char op;
    if(read(stream,ch1)){
        stream>>op;
        if((op!='+')&&(op!='-')&&(op!='*')&&(op!='/')){
            cout<<"An error has occured while reading input data"<<endl;
            return -2;
        }
    }
    else{
        cout<<"An error has occured while reading input data"<<endl;
        return -1;
    }
    if(read(stream,ch2)){
        if(op=='+'){
            ch=add(ch1, ch2);
        }
        if(op=='-'){
            ch=sub(ch1, ch2);;
        }
        if(op=='*'){
            ch=mul(ch1, ch2);;
        }
        if(op=='/'){
            ch=div(ch1, ch2);;
        }
    }
    else{
        cout<<"An error has occured while reading input data"<<endl;
        return -3;
    }
    write(ch);
    return 0;
}
