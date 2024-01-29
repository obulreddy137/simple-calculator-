#include <iostream>
#include <cmath>

double result = 0;

double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

int main() {
    char operation;
    double number;

    std::cout << "Calculator Program\n";

    for (int i = 1; i <= 10; ++i) {
        std::cout << "\nTrail " << i << ":\n";
        std::cout << "Current Result: " << result << "\n";

        std::cout << "Select operation (+, -, *, /, ^, l for logarithm, s for sine, c for cosine, t for tangent): ";
        std::cin >> operation;

        if (operation == 'l' || operation == 's' || operation == 'c' || operation == 't') {
            std::cout << "Enter angle in degrees: ";
            std::cin >> number;
            number = operation == 'l' ? log(result) / log(number) : degreesToRadians(number);
        } else {
            std::cout << "Enter number: ";
            std::cin >> number;
        }

        switch (operation) {
            case '+':
                result += number;
                break;
            case '-':
                result -= number;
                break;
            case '*':
                result *= number;
                break;
            case '/':
                if (number != 0) {
                    result /= number;
                } else {
                    std::cout << "Error: Division by zero\n";
                    i--;  // Repeat the same trial
                }
                break;
            case '^':
                result = pow(result, number);
                break;
            case 'l':
                result = log(number) / log(result);
                break;
            case 's':
                result = sin(number);
                break;
            case 'c':
                result = cos(number);
                break;
            case 't':
                result = tan(number);
                break;
            default:
                std::cout << "Invalid operation\n";
                i--;  // Repeat the same trial
        }
    }

    std::cout << "\nFinal Result: " << result << "\n";

    return 0;
}
