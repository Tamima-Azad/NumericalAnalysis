#include<bits/stdc++.h>
using namespace std;
int arr[100000];
int N;
void Function(int n){
    arr[n];
    cout<<"Enter co-efficient of function: ";
    for(int i=n;i>=0;i--){
        cin>>arr[i];
    }

}
float fun(double a){
    double sum=0;
    for(int i=N;i>=0;i--){
       sum+= arr[i]*(pow(a,i));

    }
    return sum;
}
void regularfalsi(double a,double b){
    if(fun(a)*fun(b)>=0){
        cout<<"interval is not ok\n";
        return;
    }
    double temp=0.0;
    cout<<"interval is ok\n";
    //cout<<"a "<<"b Xr \n";
    while(true){
        cout<<a<<" "<<b<<" "<<temp<<endl;
        double xr=(fun(b)*a-fun(a)*b)/(fun(b)-fun(a));
        if(abs(temp-xr)<=0.00001){
            //cout<<a<<" "<<b;
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
    cout<<"Enter power: ";
    cin>>N;
    Function(N);
    cout<<"Enter Interval: ";
    double a,b; cin>>a>>b;
    regularfalsi(a,b);
    system("color 70");

    return 0;
}