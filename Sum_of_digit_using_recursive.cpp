#include <iostream>
using namespace std;

// Recursive linear search function
int recursiveSearch(int arr[], int n, int key) {
    if (n == 0)              // Base case: not found
        return -1;

    if (arr[n - 1] == key)  // Base case: found
        return n - 1;

    return recursiveSearch(arr, n - 1, key); // Recursive call
}

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int result = recursiveSearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}