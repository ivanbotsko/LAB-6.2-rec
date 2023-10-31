#include "pch.h"
#include "CppUnitTest.h"
#include "../PR 6.2 rec/PR 6.2 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(FindMinTests)
{
public:

    TEST_METHOD(FindMinWithPositiveValues)
    {
        std::vector<int> array = { 5, 3, 7, 1, 9 };
        std::pair<int, int> minInfo = findMin(array);
        Assert::AreEqual(minInfo.first, 1); // Очікуване мінімальне значення
        Assert::AreEqual(minInfo.second, 3); // Очікуваний індекс мінімального значення
    }

    TEST_METHOD(FindMinWithNegativeValues)
    {
        std::vector<int> array = { -5, -3, -7, -1, -9 };
        std::pair<int, int> minInfo = findMin(array);
        Assert::AreEqual(minInfo.first, -9); // Очікуване мінімальне значення
        Assert::AreEqual(minInfo.second, 4); // Очікуваний індекс мінімального значення
    }

    TEST_METHOD(FindMinWithMixedValues)
    {
        std::vector<int> array = { 5, 0, -7, 1, -9 };
        std::pair<int, int> minInfo = findMin(array);
        Assert::AreEqual(minInfo.first, -9); // Очікуване мінімальне значення
        Assert::AreEqual(minInfo.second, 4); // Очікуваний індекс мінімального значення
    }
};

