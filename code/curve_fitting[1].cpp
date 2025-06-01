#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int coeficient; cin >> coeficient;
    vector<double> x(n), y(n);
    vector<double>mat[n], a(coeficient);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    mat[0].push_back(n);
    for (int i = 0; i < n; i++) {
        if(i==0){
            for(int j = 1; j <= 2 * (coeficient - 1); j++){
                double s = 0;
                for (int k = 0; k < n; k++) {
                    s += pow(x[k],j);
                }
                mat[i].push_back(s);
            }
        }
        else{
            for(int j = 1; j <= 2 * (coeficient - 1); j++){
                mat[i].push_back(mat[i-1][j]);
            } 
        }
    }
    for(int i = 0; i < coeficient; i++){
        double sum = 0;
        while(mat[i].size()> coeficient){
            mat[i].pop_back();
        }
        for(int k = 0; k < n; k++){
            sum += y[k] * pow(x[k],i);
        }
        //cout << sum << endl;
        mat[i].push_back(sum);
    }
    for(int i = 0; i < coeficient; i++){
        for(int j = 0; j <= coeficient; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < coeficient; i++){
        for(int j = i + 1; j < coeficient; j++){
            float r = mat[j][i] / mat[i][i];
            for(int k = 0; k <= coeficient; k++){
                mat[j][k] -= r * mat[i][k];
            }
        }
    }
    // cout << "Upper Triangular Matrix:\n";
    // for(int i = 0; i < coeficient; i++){
    //     for (int j = 0; j <= coeficient; j++) {
    //         cout << fixed << setprecision(2) << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // Back Substitution
    vector<float> ar(coeficient, 0);
    for(int i = coeficient - 1; i >= 0; i--){
        float sum = 0;
        for(int j = i + 1; j < coeficient; j++){
            sum += mat[i][j] * ar[j];
        }
        ar[i] = (mat[i][coeficient] - sum) / mat[i][i];
    }
    cout << "\nRoots Are:\n";
    for(float x : ar){
        cout << fixed << setprecision(2) << x << endl;
    }
}
int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}