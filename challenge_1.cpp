#include <iostream>
#include <string>
#include <tuple>

// Definition of structure point: 
struct Point {
    int x, y, z;
};

int main() {
    // Part 1: Initialization of variables
    int a1 = 300;             // Direct initialization
    double b1{2.355};         // Uniform initialization
    std::string c1("It's the first part of the challenge"); // Struct Binding
    bool d1 = true;          // Direct initialization

    // Print initial values
    std::cout << "Initial values:" << std::endl;
    std::cout << "int: " << a1 << ", double: " << b1 << ", string: " << c1 << ", bool: " << d1 << std::endl;

    // Part 3: References
    int& refa2 = a1;
    double& refb2 = b1;
    std::string& refc2 = c1;
    bool& refd2 = d1;

    refa2 = 400;
    refb2 = 11.22;
    refc2 = "It's the second part of the challenge";
    refd2 = false;

    // Print modified values
    std::cout << "\nModified values:" << std::endl;
    std::cout << "int: " << a1 << ", double: " << b1 << ", string: " << c1 << ", bool: " << d1 << std::endl;


    // Part 4: Structured bindings
    Point p{12, 30, 25};
    auto [x, y, z] = p; 

    std::cout << "\nStructured Binding:" << std::endl;
    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;

    
    
    return 0;
}

// Part 5: Identifying l-values and r-values
    
//a = 42;  "a" is a l-value, "42" is a r-value
//int xVar = a + b;  "a" y "b" are l-values, (a + b) is a r-value
//&a; // "a"' is a l-value 
//std::string s = c + " World";  "c" is a l-value, "World" is a r-value, (c + " World") is a r-value
//int& refX = xVar;  "refX" is a reference to a l-value
//int&& rref = 100;  "100" is a r-value, "rref" is a reference to a r-value