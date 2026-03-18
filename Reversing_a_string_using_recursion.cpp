#include <iostream>
using namespace std;

// Recursive function to reverse string
void reverseString(string str) {
    if (str.length() == 0)  // Base case
        return;
    
    reverseString(str.substr(1));  // Recursive call
    cout << str[0];                // Print first character at last
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    cout << "Reversed string: ";
    reverseString(str);

    return 0;
}