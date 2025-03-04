#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void processArray(std::vector<double>& arr, std::vector<bool>& boolArr, double& average) {
    double sum = 0.0;
    int n = arr.size();

  
    for (int i = 0; i < n; ++i) {
        arr[i] = (static_cast<double>(rand()) / RAND_MAX) * 30.0 - 15.0;
        sum += arr[i];
    }

 
    average = sum / n;


    for (int i = 0; i < n; ++i) {
        boolArr[i] = arr[i] > average;
    }
}

int main() {
    const int n = 20;
    std::vector<double> arr(n, 0.0); 
    std::vector<bool> boolArr(n);
    double average;

    std::srand(static_cast<unsigned int>(std::time(0)));

    processArray(arr, boolArr, average);

 
    std::cout << "Вход: [ ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "]\n";

    std::cout << "Выход: [ ";
    for (const auto& val : boolArr) {
        std::cout << (val ? "T" : "F") << " ";
    }
    std::cout << "]\n";

    std::cout << "average = " << average << "\n";

    return 0;
}