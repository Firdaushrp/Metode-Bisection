#include <iostream>
#include <cmath> 

using namespace std;

double f(double x) {
    return x * x * x - 7 * x + 1;
}

double bisection(double a, double b) {
    double eps = 0.1;
    double c;
    
    while (std::abs(a - b) >= 0.0001) {
        c = (a + b) / 2.0;
        if (f(c) * f(a) > 0.0) {
            a = c;
        } else {
            b = c;
        }
        eps = std::abs(a - b);
    }
    
    return c;
}

double a, b;

int main() {
    cout <<"Masukkan nilai a : ";
    cin >> a;
    cout << "\n";
    
    cout << "Masukkan nilai b : ";
    cin >> b;
    
    double result = bisection(a, b);
    std::cout << "Root: " << result << std::endl;
    return 0;
}

