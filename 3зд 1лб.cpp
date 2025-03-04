#include <iostream>

char* strrchr(char* s, int c) {
    char* lastOccurrence = nullptr; 
    while (*s != '0') { 
        if (*s == static_cast<char>(c)) { 
            lastOccurrence = s; 
        }
        s++; 
    }
    return lastOccurrence; 
}

int main() {
    char str[] = "Hello, world! Welcome to the world of C++.";
    char ch = 'o';

    char* result = strrchr(str, ch);

    if (result != nullptr) {
        std::cout << "Последнее вхождение символа '" << ch << "' найдено: "
                  << result << std::endl; 
    } else {
        std::cout << "Символ '" << ch << "' не найден." << std::endl;
    }

    return 0;
}