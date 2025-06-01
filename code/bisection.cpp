#include<bits/stdc++.h>
using namespace std;
float fun(double a){
    return (pow(a,3)-2*a-5);
}
void bisection(double a,double b){
    if(fun(a)*fun(b)>=0){
        cout<<"interval is not ok\n";
        return;
    }
    double temp=0.0;
    cout<<"interval is ok\n";
    //cout<<"a "<<"b Xr \n";
    while(1){
        cout<<a<<" "<<b<<" "<<temp<<endl;
        double xr=(a+b)/2;
        if(abs(temp-xr)<=0.00001){
            //cout<<a<<" "<<b;7
            cout << " Root = " << xr << endl;
            break;
        }
        if(fun(a)*fun(xr)<0){
            b=xr;
        }
        else if(fun(a)*fun(xr)>0){
            a=xr;
        }
       else if(fun(xr)==0.0){
            
            cout << "Root = " << xr << endl;
            break;
       }
       temp = xr;
    }
    
}
int main(){
    double a,b; cin>>a>>b;
    bisection(a,b);
    system("color 70");

    return 0;
}