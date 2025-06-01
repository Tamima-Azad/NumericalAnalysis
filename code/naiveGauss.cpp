#include<bits/stdc++.h>
using namespace std;
int N;
int a[10000][10000];
int b[10000][10000];
int c[10000][10000];
void equation(int n){
    N=n;
    a[N][N];
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin>>a[i][j];
        }
    }
}
void guass(){
    double r1=a[1][0]/a[0][0];
    for(int i=0;i<=N;i++){
        a[1][i]=a[1][i]-r1*a[0][i];
    }
    double r2=a[2][0]/a[0][0];
    for(int i=0;i<=N;i++){
        a[2][i]=a[2][i]-r2*a[0][i];
    }
    double r3=a[2][1]/a[1][1];
    for(int i=1;i<=N;i++){
        a[2][i]=a[2][i]-r3*a[1][i];
    }
    float z = -a[1][3]/ a[1][2];
    double y=(a[1][3]-a[1][2]*z)/a[1][1];
    float x=-(-a[0][3]+a[0][1]*y+a[0][2]*(z))/a[0][0];
    cout<<"x= "<<x<<endl;
    cout<<"Y= "<<y<<endl;
    cout<<"z= "<<z<<endl;
}
int main(){
    int n;cin>>n;
    N=n;
    equation(n);
    guass();

}