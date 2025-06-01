#include<bits/stdc++.h>
using namespace std;
vector<double>guass(vector<vector<double>>matrix,int degree){
    int n=degree;

}
int main(){
    int n,degree;
    cin>>n>>degree;
    vector<double>x(n),y(n);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>y[i];

    degree+=1;
    vector<vector<double>>matrix(degree,vector<double>(degree+1,0));
    for(int i=0;i<degree;i++){
        for(int j=0;j<degree;j++){
            float sum=0;
            for(int k=0;k<n;k++){
                sum+=pow(x[k],i+j);
            }
            matrix[i][j]=sum;

        }
        double rhs=0;
        for(int j=0;j<degree;j++){
            rhs+=y[j]*pow(x[j],i);
        }
        matrix[i][degree]=rhs;

    }
     vector<double>coeff=guass(matrix,degree);


}