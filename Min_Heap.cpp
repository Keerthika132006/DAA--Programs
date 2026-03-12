#include <iostream>
using namespace std;

struct MinHeap {
    int arr[50];
    int size = 0;

    // Insert node
    void insert(int value) {
        size++;
        int i = size;

        // Move up to maintain min heap
        while (i > 1 && arr[i / 2] > value) {
            arr[i] = arr[i / 2];
            i = i / 2;
        }
        arr[i] = value;
    }

    // Display heap
    void display() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);

    cout << "Min Heap elements: ";
    h.display();

    return 0;
}