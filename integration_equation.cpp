#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// точное решение
double phi(double x) {
    return 0.5 * sinh(x) + 0.5 * sin(x);
}

double f(double x) {
    return sin(x);
}

int main() {
    double a; // левая граница
    double b; // правая граница
    double h; // шаг

    cout << "Enter a, b: ";
    cin >> a >> b; // считываем границы
    cout << "Enter h: ";
    cin >> h; // считываем шаг

    int n = (b - a) / h + 1; // получаем количество точек
    double *solve = new double[n]; // выделяем память под решение

    solve[0] = f(a); // phi(a)

    for (int i = 1; i < n; i++) {
        double xi = a + i * h;

        solve[i] = sin(xi);

        for (int j = 0; j < i; j++) {
            double tj = a + j * h;
            solve[i] += h * (xi - tj) * solve[j];
        }
    }

    cout << "+-----------------+------------------+-----------------+" << endl;
    cout << "|        x        | quadrature solve |       phi       |" << endl;
    cout << "+-----------------+------------------+-----------------+" << endl;

    for (int i = 0; i < n; i++) {
        double x = a + i * h;
        cout << "| " << setw(15) << x << " | " << setw(16) << solve[i] << " | " << setw(15) << phi(x) << " |" << endl;
    }

    cout << "+-----------------+------------------+-----------------+" << endl;
}