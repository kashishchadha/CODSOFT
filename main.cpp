#include <iomanip>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void displayMenu() {
    cout << "Scientific Calculator Menu:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Division" << endl;
    cout << "4. Multiplication" << endl;
    cout << "5. Tangent" << endl;
    cout << "6. Sine" << endl;
    cout << "7. Cosine" << endl;
    cout << "8. Logarithm (base e)" << endl;
    cout << "9. Logarithm (base 10)" << endl;
    cout << "10. Raise to the power of 2" << endl;
    cout << "11. Raise to a specified power" << endl;
    cout << "12. Square Root" << endl;
    cout << "13. Feet to Meters" << endl;
    cout << "14. Meters to Feet" << endl;
    cout << "15. Centimeters to Inches" << endl;
    cout << "16. Inches to Centimeters" << endl;
    cout << "17. Inches to Millimeters" << endl;
    cout << "18. Millimeters to Inches" << endl;
    cout << "19. Yards to Meters" << endl;
    cout << "20. Meters to Yards" << endl;
    cout << "21. Miles to Kilometers" << endl;
    cout << "22. Kilometers to Miles" << endl;
    cout << "23. Nautical Miles to Kilometers" << endl;
    cout << "24. Nautical Miles to Miles" << endl;
    cout << "0. Exit" << endl;
}

void addition() {
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
}

void subtraction() {
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
}

void division() {
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    if (num2 != 0) {
        cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
    } else {
        cout << "Error: Division by zero." << endl;
    }
}

void multiplication() {
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
}

void tangent() {
    double num1;
    cout << "Enter an angle in degrees: ";
    cin >> num1;
    cout << "tan(" << num1 << ") = " << tan(num1 * M_PI / 180) << endl;
}

void sine() {
    double num1;
    cout << "Enter an angle in degrees: ";
    cin >> num1;
    cout << "sin(" << num1 << ") = " << sin(num1 * M_PI / 180) << endl;
}

void cosine() {
    double num1;
    cout << "Enter an angle in degrees: ";
    cin >> num1;
    cout << "cos(" << num1 << ") = " << cos(num1 * M_PI / 180) << endl;
}

void logs() {
    double num1;
    cout << "Enter a number: ";
    cin >> num1;
    if (num1 > 0) {
        cout << "log(" << num1 << ") = " << log(num1) << endl;
    } else {
        cout << "Error: Logarithm of a non-positive number." << endl;
    }
}

void logsTen() {
    double num1;
    cout << "Enter a number: ";
    cin >> num1;
    if (num1 > 0) {
        cout << "log10(" << num1 << ") = " << log10(num1) << endl;
    } else {
        cout << "Error: Logarithm of a non-positive number." << endl;
    }
}

void raiseSecondPower() {
    double num1;
    cout << "Enter a number: ";
    cin >> num1;
    cout << num1 << "^2 = " << pow(num1, 2) << endl;
}

void raiseANumber() {
    double num1, num2;
    cout << "Enter the base and exponent: ";
    cin >> num1 >> num2;
    cout << num1 << "^" << num2 << " = " << pow(num1, num2) << endl;
}

void squareRoot() {
    double num1;
    cout << "Enter a number: ";
    cin >> num1;
    if (num1 >= 0) {
        cout << "sqrt(" << num1 << ") = " << sqrt(num1) << endl;
    } else {
        cout << "Error: Square root of a negative number." << endl;
    }
}

void feetToMeters() {
    double num1;
    cout << "Enter feet: ";
    cin >> num1;
    cout << num1 << " feet = " << num1 * 0.3048 << " meters" << endl;
}

void metersToFeet() {
    double num1;
    cout << "Enter meters: ";
    cin >> num1;
    cout << num1 << " meters = " << num1 * 3.281 << " feet" << endl;
}

void centimetersToInches() {
    double num1;
    cout << "Enter centimeters: ";
    cin >> num1;
    cout << num1 << " cm = " << num1 * 0.3937 << " inches" << endl;
}

void inchesToCentimeters() {
    double num1;
    cout << "Enter inches: ";
    cin >> num1;
    cout << num1 << " inches = " << num1 * 2.54 << " cm" << endl;
}

void inchesToMillimeters() {
    double num1;
    cout << "Enter inches: ";
    cin >> num1;
    cout << num1 << " inches = " << num1 * 25.4 << " mm" << endl;
}

void millimetersToInches() {
    double num1;
    cout << "Enter millimeters: ";
    cin >> num1;
    cout << num1 << " mm = " << num1 * 0.0394 << " inches" << endl;
}

void yardsToMeters() {
    double num1;
    cout << "Enter yards: ";
    cin >> num1;
    cout << num1 << " yards = " << num1 * 0.9144 << " meters" << endl;
}

void metersToYards() {
    double num1;
    cout << "Enter meters: ";
    cin >> num1;
    cout << num1 << " meters = " << num1 * 1.094 << " yards" << endl;
}

void milesToKilometers() {
    double num1;
    cout << "Enter miles: ";
    cin >> num1;
    cout << num1 << " miles = " << num1 * 1.609 << " km" << endl;
}

void kilometersToMiles() {
    double num1;
    cout << "Enter kilometers: ";
    cin >> num1;
    cout << num1 << " km = " << num1 * 0.6214 << " miles" << endl;
}

void nauticalmilesToKilometers() {
    double num1;
    cout << "Enter nautical miles: ";
    cin >> num1;
    cout << num1 << " nm = " << num1 * 1.852 << " km" << endl;
}

void nauticalmilesToMiles() {
    double num1;
    cout << "Enter nautical miles: ";
    cin >> num1;
    cout << num1 << " nm = " << num1 * 1.150779 << " miles" << endl;
}

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice (0 to exit): ";
        cin >> choice;

        switch (choice) {
            case 1: addition(); break;
            case 2: subtraction(); break;
            case 3: division(); break;
            case 4: multiplication(); break;
            case 5: tangent(); break;
            case 6: sine(); break;
            case 7: cosine(); break;
            case 8: logs(); break;
            case 9: logsTen(); break;
            case 10: raiseSecondPower(); break;
            case 11: raiseANumber(); break;
            case 12: squareRoot(); break;
            case 13: feetToMeters(); break;
            case 14: metersToFeet(); break;
            case 15: centimetersToInches(); break;
            case 16: inchesToCentimeters(); break;
            case 17: inchesToMillimeters(); break;
            case 18: millimetersToInches(); break;
            case 19: yardsToMeters(); break;
            case 20: metersToYards(); break;
            case 21: milesToKilometers(); break;
            case 22: kilometersToMiles(); break;
            case 23: nauticalmilesToKilometers(); break;
            case 24: nauticalmilesToMiles(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
