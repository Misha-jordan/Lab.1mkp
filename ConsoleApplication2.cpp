#include <iostream>
#include <cmath>

double calculate(double M, double e, double epsilon) {
    setlocale(LC_ALL, "Russian");
    double E = M; // Начальное значение Е равно М
    double diff; // Разность между Е(k + 1) и E(k)

    do {
        double E_prev = E;
        E = std::asin(E_prev - e * std::sin(E_prev)) + M;
        diff = std::abs(E_prev - E);
    } while (diff > epsilon);
    return E;
}

   int main() {
    double M, e, epsilon;
    setlocale(LC_ALL, "Russian");

    //ввод значений M, e, epsilon
    std::cout << "Введите значение М: ";
    std::cin >> M;

    std::cout << "Введите значение е: ";
    std::cin >> e;

    std::cout << "Введите значение epsilon: ";
    std::cin >> epsilon;

    double E = calculate(M, e, epsilon);
    std::cout << "Значение эксцентрической аномалии Е: " << E << std::endl;

    double M = 0.3;
    double e = 0.5;
    double epsilon = 0.0001;

    return 0;
}

double calculateEccentricAnomaly(double M, double e, double epsilon) {
    double a = -M; // Начальое значение левой границы интервала
    double b = M; // Начальное значение правлй границы интервала
    double c = 0; // Текущее значение

    while (fabs(b - a) > epsilon) {
        c = (a + b) / 2;   // Деление интервала пополам
        double f = c - e * sin(c) - M;
        if (f == 0) {
            break;
        }
        else if (f < 0) {
            a = c;
        }
        else {
            b = c;
        }
    }
    return c;
}

double goldenSectionMethod(double a, double b, double e, double M) {
    const double phi = (1 + sqrt(5)) / 2; // Золотое сечение
    double c = b - (b - a) / phi;
    double d = a + (b - a) / phi;
    double E_c = c;
    double E_d = d;

    double f_c = E_c - sin(E_c) - M;
    double f_d = E_d - sin(E_d) - M;

    while (abs(b - a) > 2 * e || abs(f_c) > e) {
        if (f_c * f_d > 0) {
            a = c;
            b = d;
        }
        else {
            if (f_c * f_d < 0) {
                a = d;
                b = c;
            }
        }

        c = b - (b - a) / phi;
        d = a + (b - a) / phi;

        E_c = c;
        E_d = d;

        f_c = E_c - sin(E_c) - M;
        f_d = E_d - sin(E_d) - M;
    }

    return (a + b) / 2;
}


double calculateEccentricAnomaly(double M, double e, double epsilon) {
    double E_prev = 0.0;
    double E = M; // Начальное приближение для E
    double diff = std::abs(E - E_prev);

    while (diff >= epsilon) {
        E_prev = E;
        E = E_prev - (E_prev - e * std::sin(E_prev) - M) / (1 - e * std::cos(E_prev));
        diff = std::abs(E - E_prev);
    }

    return E;
}

