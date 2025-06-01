#include<bits/stdc++.h>
using namespace std;
int main(){
    int x1,y1,z1,c1;
    cin>>x1>>y1>>z1>>c1;
   // x1=(c1-y1-z1)/x1;
    int x2,y2,z2,c2;
    cin>>x2>>y2>>z2>>c2;
    //y2=(c2-x2-z2)/y2;
    int x3,y3,z3,c3;
    cin>>x3>>y3>>z3>>c3;
    //z3=(c3-x3-y3)/z3;
    float x=0,y=0,z=0;
    float p,q,r;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        p=x;
        x=(c1-y1*y-z1*z)/x1;
        q=y;
        y=(c2-x2*x-z2*z)/y2;
        r=z;
        z=(c3-x3*x-y3*y)/z3;
        
        if(p==x && q==y && r==z){
            break;
        }
       }
       cout<<"x= "<<x<<" y= "<<y<<" z= "<<z<<endl;

}