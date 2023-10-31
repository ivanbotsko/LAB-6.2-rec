#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Функція для генерації масиву
std::vector<int> generateArray(int size, int min, int max, int currentIndex = 0) {
    if (currentIndex == size) {
        return std::vector<int>();
    }

    int randomValue = rand() % (max - min + 1) + min;
    std::vector<int> array = generateArray(size, min, max, currentIndex + 1);
    array.insert(array.begin(), randomValue);
    return array;
}

// Функція для знаходження мінімального значення і його індексу
std::pair<int, int> findMin(const std::vector<int>& array, int currentIndex = 0, int min = INT_MAX, int indexOfMin = 0) {
    if (currentIndex == array.size()) {
        return std::make_pair(min, indexOfMin);
    }

    if (array[currentIndex] < min) {
        min = array[currentIndex];
        indexOfMin = currentIndex;
    }

    return findMin(array, currentIndex + 1, min, indexOfMin);
}

// Функція для знаходження максимального значення і його індексу
std::pair<int, int> findMax(const std::vector<int>& array, int currentIndex = 0, int max = INT_MIN, int indexOfMax = 0) {
    if (currentIndex == array.size()) {
        return std::make_pair(max, indexOfMax);
    }

    if (array[currentIndex] > max) {
        max = array[currentIndex];
        indexOfMax = currentIndex;
    }

    return findMax(array, currentIndex + 1, max, indexOfMax);
}

// Функція для обчислення середнього арифметичного індексів
double calcArithmetic(int a, int b) {
    return (a + b) / 2.0;
}

int main() {
    srand(static_cast<unsigned>(time(0)));  // Ініціалізувати генератор випадкових чисел

    int size = 20;
    int min = 1;
    int max = 100;

    std::vector<int> array = generateArray(size, min, max);

    std::cout << "Formed array:";
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::pair<int, int> minInfo = findMin(array);
    std::cout << "Minimum value of the array: " << minInfo.first << ", its index in the array: " << minInfo.second << std::endl;

    std::pair<int, int> maxInfo = findMax(array);
    std::cout << "The maximum value of the array: " << maxInfo.first << ", its index in the array:" << maxInfo.second << std::endl;

    double result = calcArithmetic(minInfo.second, maxInfo.second);
    std::cout << "The arithmetic mean of the indices of the minimum and maximum values: " << result << std::endl;

    return 0;
}
