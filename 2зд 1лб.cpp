#include <iostream>
#include <iomanip>

int main() {
    const int size = 20; 
    const int rows = 5;  
    const int cols = 4;  

    int fib[size]; 


    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < size; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    std::cout << "Одномерный массив чисел Фибоначчи:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(7) << fib[i];
        if ((i + 1) % cols == 0) { 
        }
    }

    return 0;
}