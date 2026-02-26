#include <iostream>
using namespace std;

// Function to find Josephus position (0-indexed)
int josephus(int n, int k) {
    if (n == 1) return 0;          // base case
    return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;
    cout << "Enter number of people: ";
    cin >> n;
    cout << "Enter step k: ";
    cin >> k;

    int survivor = josephus(n, k) + 1; // +1 for 1-indexed position
    cout << "Survivor position: " << survivor << endl;

    return 0;
}