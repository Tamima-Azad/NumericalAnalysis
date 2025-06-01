#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
  //  vector<vector<float>> v(n, vector<float>(n + 1));
   // vector<float>v[n+1];
    float v[n][n+1];
    // Input Augmented Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    // // Forward Elimination with Partial Pivoting
      for (int i = 0; i < n; i++) {
        // Pivoting: Find the maximum element in column i below or at row i
        // int maxRow = i;
        // for (int j = i + 1; j < n; j++) {
        //     if (abs(v[j][i]) > abs(v[maxRow][i])) {
        //         maxRow = j;
        //     }
        // }

        // // Swap the rows if a better pivot is found
        // if (maxRow != i) {
        //     swap(v[i], v[maxRow]);
        // }

        // Perform elimination on lower rows
        for (int j = i + 1; j < n; j++) {
            float r = v[j][i] / v[i][i];
            for (int k = 1; k <= n; k++) {
                v[j][k] -= r * v[i][k];
            }
        }
    }
    cout << "Upper Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << fixed << setprecision(2) << v[i][j] << " ";
        }
        cout << endl;
    }

    // Back Substitution
    vector<float> ar(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        float sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += v[i][j] * ar[j];
        }
        ar[i] = (v[i][n] - sum) / v[i][i];
    }

    cout << "\nRoots Are:\n";
    for (float x : ar) {
       // cout << fixed << setprecision(2) << x << endl;
        cout<<fixed<<setprecision(2)<<x<<endl;
    }
}

int main() {
    solve();
    return 0;
}
