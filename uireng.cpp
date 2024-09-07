#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Fungsi x
double f(double x) {
    return x * x * x  - 7 * x + 1;
}

// Fungsi metode bisection
void bisection(double a, double b, double tol, int maxIter) {
    double c;
    if (f(a) * f(b) >= 0) {
        cout << "Tidak ada akar di interval [" << a << ", " << b << "]" << endl;
        return;
    }
    
    cout << "Iterasi\t\ta\t\tb\t\tc\t\tf(c)\t\tError" << endl;
    for (int iter = 1; iter <= maxIter; iter++) {
        c = (a + b) / 2;
        double error = fabs(b - a) / 2;
        
        cout << fixed << setprecision(6);
        cout << iter << "\t\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << "\t" << error << endl;
        
        if (fabs(f(c)) < tol || error < tol) {
            cout << "Akar ditemukan pada x = " << c << " dengan toleransi " << tol << endl;
            return;
        }

        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    
    cout << "Iterasi maksimal tercapai, akar mendekati x = " << c << endl;
}

int main() {
	double a;
	double b;
    cout <<"Masukkan nilai a : ";
    cin >> a; 						//Titik awal
    cout <<"Masukkan nilai b : ";
    cin >> b; 						// Titik Akhir
    double tol = 5e-3;
    int maxIter = 100;
    
    bisection(a, b, tol, maxIter);
    
    return 0;
}

