#include <iostream>
#include <cmath>
#include <utility> 

std::pair<double, double> resolverEcuacionCuadratica(double a, double b, double c) {
    if (a == 0) {
        return {nan(""), nan("")}; 
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return {nan(""), nan("")}; 
    }

    double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
    double x2 = (-b - std::sqrt(discriminant)) / (2 * a);

    return {x1, x2};
}

int main() {
    double a, b, c;
    std::cout << "Enter the coefficients a, b and c: ";
    std::cin >> a >> b >> c;

    std::pair<double, double> solutions = resolverEcuacionCuadratica(a, b, c);

    if (std::isnan(solutions.first) || std::isnan(solutions.second)) {
        std::cout << "There are no real solutions." << std::endl;
    } else if (solutions.first == solutions.second) {
        std::cout << "The only solution is: x = " << solutions.first << std::endl;
    } else {
        std::cout << "The solutions are: x1 = " << solutions.first << ", x2 = " << solutions.second << std::endl;
    }

    return 0;
}
