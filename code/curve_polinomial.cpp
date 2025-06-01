#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Solves system of equations using Gaussian elimination
vector<double> gaussianElimination(vector<vector<double>> matrix, int degree) {
    int n = degree;
    vector<double> result(n, 0);

    // Forward Elimination
    for (int i = 0; i < n; i++) {
        // Make diagonal 1 and eliminate below
        for (int j = i + 1; j < n; j++) {
            double ratio = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= n; k++) {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }

    // Back Substitution
    for (int i = n - 1; i >= 0; i--) {
        result[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            result[i] -= matrix[i][j] * result[j];
        }
        result[i] /= matrix[i][i];
    }

    return result;
}

int main() {
    int n, degree;
    cout << "Enter number of data points: ";
    cin >> n;
    cout << "Enter degree of polynomial: ";
    cin >> degree;

    vector<double> x(n), y(n);
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++) cin >> x[i];
    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

    degree += 1; // number of coefficients = degree + 1
    vector<vector<double>> matrix(degree, vector<double>(degree + 1, 0));

    // Build the normal equation matrix
    for (int i = 0; i < degree; i++) {
        for (int j = 0; j < degree; j++) {
            double sum = 0;
            for (int k = 0; k < n; k++) {
                sum += pow(x[k], i + j);
            }
            matrix[i][j] = sum;
        }

        // Right-hand side
        double rhs = 0;
        for (int k = 0; k < n; k++) {
            rhs += y[k] * pow(x[k], i);
        }
        matrix[i][degree] = rhs;
    }
    // Solve
    vector<double> coeffs = gaussianElimination(matrix, degree);
    // Output the polynomial
    cout << "\nFitted Polynomial Coefficients:\n";
    for (int i = 0; i < coeffs.size(); i++) {
        cout << "a" << i << " = " << fixed << setprecision(4) << coeffs[i] << endl;
    }

    return 0;
}
