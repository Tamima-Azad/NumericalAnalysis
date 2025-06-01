#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
float seidel(){

}
int main(){
    
    int n; cin >> n;
    vector<float>v[n];
    for (int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++){
            float x; cin >> x;
            v[i].push_back(x);
        }
    }
    map<int,float>mp;
    for(int i = 0; i < n; i++){
        mp[i] = 0;
    }
    float temp;
    bool recieved = true;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < n; j++){
            float line_sum = 0, total = 0;
            for(int k = 0; k <= n; k++){
                if(k != j and k < n){
                    line_sum += mp[k] * v[j][k];
                    total += mp[k];
                    cout << mp[k] << " " << v[j][k] << endl;
                }
                else if(k==n){
                    line_sum += v[j][k];
                }
            }
            // temp = total;
        //cout << endl;

            mp[j] = -(line_sum/v[j][j]);
        }
    }
    cout << "Roots Are: ";;
    for (int i = 0; i < n; i++) {
        cout << -mp[i] << " ";
    }
    
return 0;
}