#include <iostream>
using namespace std;

int main() {
    // Static Array (Fixed Size)
    int staticArray[5]; // Declare a static array with 5 elements

    cout << "Static Array Initialization:" << endl;
    for (int i = 0; i < 5; ++i) {
        staticArray[i] = i + 1; // Assign values to the array
        cout << staticArray[i] << " "; // Print the static array values
    }
    cout << "\n";

    // Dynamic Array (Size determined at runtime)
    int size;
    cout << "\nEnter size of dynamic array: ";
    cin >> size;

    int* dynamicArray = new int[size]; // Allocate memory for dynamic array

    cout << "Dynamic Array Initialization:" << endl;
    for (int i = 0; i < size; ++i) {
        dynamicArray[i] = i + 10; // Assign values to the array
        cout << dynamicArray[i] << " "; // Print the dynamic array values
    }
    cout << "\n";

    // Clean up the dynamically allocated memory
    delete[] dynamicArray;

    return 0;
}

