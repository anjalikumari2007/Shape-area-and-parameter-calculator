
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

double readNumber(const char* message) {
    double value;

    while (true) {
        cout << message;

        if (cin >> value) {
            return value;
        }

        cout << "Invalid input! Please enter a number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int readChoice() {
    int choice;

    while (true) {
        cout << "Enter your choice: ";

        if (cin >> choice) {
            return choice;
        }

        cout << "Invalid input! Please enter a number from 1 to 4.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() override {
        return 3.14159 * radius * radius;
    }

    double perimeter() override {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() override {
        return length * width;
    }

    double perimeter() override {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

    double area() override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() override {
        return a + b + c;
    }
};

int main() {
    int choice;
    double r, l, w, a, b, c;

    do {
        cout << "\n===== SHAPE CALCULATOR =====\n";
        cout << "1. Circle\n";
        cout << "2. Rectangle\n";
        cout << "3. Triangle\n";
        cout << "4. Exit\n";

        choice = readChoice();

        Shape* shape = NULL;

        switch (choice) {
        case 1:
            r = readNumber("Enter radius: ");

            if (r <= 0) {
                cout << "Radius must be positive.\n";
                break;
            }

            shape = new Circle(r);
            break;

        case 2:
            l = readNumber("Enter length: ");
            w = readNumber("Enter width: ");

            if (l <= 0 || w <= 0) {
                cout << "Length and width must be positive.\n";
                break;
            }

            shape = new Rectangle(l, w);
            break;

        case 3:
            a = readNumber("Enter first side: ");
            b = readNumber("Enter second side: ");
            c = readNumber("Enter third side: ");

            if (a <= 0 || b <= 0 || c <= 0 ||
                a + b <= c || a + c <= b ||
                b + c <= a) {
                cout << "Invalid triangle sides.\n";
                break;
            }

            shape = new Triangle(a, b, c);
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Please select 1 to 4.\n";
        }

        if (shape != NULL) {
            cout << "Area = " << shape->area() << endl;
            cout << "Perimeter = " << shape->perimeter() << endl;

            delete shape;
        }

    } while (choice != 4);

    return 0;
}

