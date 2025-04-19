
#include <iostream>
#include <vector>
#include <chrono>


//Move Semantics
// PART 1: Introduction to copy vs Move
//Task 1.1: Reading and Discussion

//Read the following code snippet:

//#include <iostream>
//#include <vector>

//int main() {
    //std::vector<int> v1 = {1, 2, 3, 4};
    //std::vector<int> v2 = v1;        // Copy
    //std::vector<int> v3 = std::move(v1); // Move

    //std::cout << "v1 size: " << v1.size() << std::endl;
    //std::cout << "v2 size: " << v2.size() << std::endl;
    //std::cout << "v3 size: " << v3.size() << std::endl;

    //return 0;
//}
//Questions:

//• What is the output of this program?
//• Why does v1.size() return 0 after the move?
//• What does std::move do?
//• Why is v1 still in a valid but unspecified state?

// PART 2: Implementing Move Semantics
//Task 2.1: Define a Simple Resource-Managing Class

class Buffer {
    private:
        int* data;
        size_t size;
    
    public:
        // Constructor
        Buffer(size_t s) : size(s), data(new int[s]) {
            std::cout << "Constructor called\n";
        }
    
        // Destructor
        ~Buffer() {
            delete[] data;
            std::cout << "Destructor called\n";
        }

// Task 2.2: Add copy constructor and assgnment

// Copy constructor
Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) { // Se corrigió la asignación de memoria
    std::copy(other.data, other.data + other.size, data);
    std::cout << "Copy constructor called\n";
}

// Assignment operator
Buffer& operator=(const Buffer& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        std::copy(other.data, other.data + other.size, data);
        std::cout << "Copy assignment called\n";
    }
    return *this;
}

// Task 2.3: Add move constructor and assignment

// move constructor
Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
    std::cout << "Move constructor called\n";
}

// assignment operator
Buffer& operator=(Buffer&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;
        std::cout << "Move assignment called\n";
    }
    return *this;
}
};


// PART 3: Using your class

// Task 3.1: Create instances and observe behavior

int main(){

    Buffer b1(100);
    Buffer b2 = b1;
    Buffer b3 = std::move(b1);

    Buffer b4(50);
    b4 = b2;
    b4 = std::move(b2);
    

    return 0;
}

// PART 4: Measure Perfomance

auto start = std::chrono::high_resolution_clock::now();

Buffer b1(1000000);  // Operación costosa
Buffer b2 = std::move(b1);  // Medir movimiento

auto end = std::chrono::high_resolution_clock::now();
std::cout << "Duration: "<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";



// PART 5: SUMMARY

//Questions

//• What did you learn about move semantics?
//• In what kinds of projects do you think this would matter?
//• What are some risks of using std::move incorrectly?