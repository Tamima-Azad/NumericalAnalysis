#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    //vector<vector<float>> a(n, vector<float>(n + 1)); // Augmented matrix
    float a[n][n + 1]; // Augmented matrix
    vector<float> x(n, 0); // Initial guess: x1 = x2 = ... = 

    cout << "Enter coefficients of the augmented matrix (a1 a2 ... an b):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int iter = 0; iter < 100; iter++) {
        bool isConverged = true;
        for (int i = 0; i < n; i++) {
            float sum = a[i][n]; // Start with the constant term
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            float newX = sum / a[i][i];
            if (abs(newX - x[i]) > 0.001) {
                isConverged = false;
            x[i] = newX;
        }
        if (isConverged)
          break;
    }
    }
    cout << "Roots are:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
