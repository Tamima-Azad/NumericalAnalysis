#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<vector<float>>v(n,vector<float>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int maxrow=i;
        for(int j=i+1;j<n;j++){
            if(abs(v[j][i])>abs(v[maxrow][i])){
                maxrow=j;
            }

        }
        if(maxrow!=i){
            swap(v[i],v[maxrow]);
        }
        for(int j=i+1;j<n;j++){
            float r=v[j][i]/v[i][i];
            for(int k=0;k<n;k++){
                v[j][k]-=r*v[i][k];
            }
        }
    }
    // cout << "Upper Triangular Matrix:\n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << fixed << setprecision(2) << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<float>a(n,0);
    for(int i=n-1;i>=0;i--){
        float sum=0;
        for(int j=i+1;j<n;j++){
            sum+=v[i][j]*a[j];
        }
        a[i]=(v[i][n]-sum)/v[i][i];
    }
    for(auto i:a){
        cout<<fixed<<setprecision<<i<<" ";
    }
    cout<<endl;
}
int main(){
    solve();
}