#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int MAX = 10;

int main() {
    int n, degree;
    cout << "Enter number of data points: ";
    cin >> n;

    cout << "Enter degree of polynomial: ";
    cin >> degree;

    double x[100], y[100];
    double X[2 * MAX] = {0}; // sum of powers of x
    double Y[MAX] = {0};     // sum of x^i * y
    double mat[MAX][MAX + 1] = {0}; // augmented matrix [A|b]

    // Input x and y values
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

    // Compute sums of powers of x
    for (int k = 0; k <= 2 * degree; k++) {
        for (int i = 0; i < n; i++) {
            X[k] += pow(x[i], k);
        }
    }

    // Compute sums of x^i * y
    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j < n; j++) {
            Y[i] += pow(x[j], i) * y[j];
        }
    }

    // Form the normal equations matrix [A|b]
    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= degree; j++) {
            mat[i][j] = X[i + j];
        }
        mat[i][degree + 1] = Y[i];
    }

    // Display the normal equation matrix
    cout << "\nNormal Equation Matrix [A | b]:\n";
    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= degree; j++) {
            cout << setw(10) << fixed << setprecision(4) << mat[i][j] << " ";
        }
        cout << "| " << setw(10) << fixed << setprecision(4) << mat[i][degree + 1] << endl;
    }

    // Gaussian Elimination
    for (int i = 0; i <= degree; i++) {
        for (int j = i + 1; j <= degree; j++) {
            double ratio = mat[j][i] / mat[i][i];
            for (int k = 0; k <= degree + 1; k++) {
                mat[j][k] -= ratio * mat[i][k];
            }
        }
    }

    // Back Substitution
    double coeff[MAX] = {0};
    for (int i = degree; i >= 0; i--) {
        coeff[i] = mat[i][degree + 1];
        for (int j = i + 1; j <= degree; j++) {
            coeff[i] -= mat[i][j] * coeff[j];
        }
        coeff[i] /= mat[i][i];
    }

    // Display the fitted polynomial coefficients
    cout << "\nFitted Polynomial Coefficients:\n";
    for (int i = 0; i <= degree; i++) {
        cout << "a" << i << " = " << fixed << setprecision(6) << coeff[i] << endl;
    }

    // Display the polynomial equation
    cout << "\nFitted Polynomial:\n";
    cout << "y = ";
    for (int i = 0; i <= degree; i++) {
        if (i > 0) cout << " + ";
        cout << coeff[i] << "*x^" << i;
    }
    cout << endl;

    return 0;
}
