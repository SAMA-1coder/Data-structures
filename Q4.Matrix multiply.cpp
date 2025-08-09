#include <iostream>
using namespace std;

int main() {
    int m, n, p, r;

    // Input sizes
    cout << "Enter rows and columns of first matrix (m n): ";
    cin >> m >> n;

    cout << "Enter rows columns of second matrix (r p): ";
    cin >>r >> p;

    int A[10][10], B[10][10], C[10][10] = {0};

    // Input first matrix
    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
         cout<<"First matrix"<<endl;
		    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout<<endl<<" ";
}
    // Input second matrix elements
    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];

   cout<<"Second matrix"<<endl;
		    for (int i = 0; i < r; i++) {
        for (int j = 0; j < p; j++) {
            cout << B[i][j] << " ";
        }
        cout<<endl<<" ";
}

    // Performing matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Output 
    cout << "Result after multiplication of matrices:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

