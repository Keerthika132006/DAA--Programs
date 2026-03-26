#include <iostream>
using namespace std;

int w[20], x[20], n, target;

void subset(int sum, int k) {
    if (sum == target) {
        cout << "Subset: ";
        for (int i = 0; i < k; i++)
            if (x[i] == 1)
                cout << w[i] << " ";
        cout << endl;
        return;
    }

    if (k >= n || sum > target)
        return;

    // include element
    x[k] = 1;
    subset(sum + w[k], k + 1);

    // exclude element
    x[k] = 0;
    subset(sum, k + 1);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> w[i];

    cout << "Enter target sum: ";
    cin >> target;

    subset(0, 0);

    return 0;
}