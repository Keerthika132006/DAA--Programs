#include <iostream>
#include <vector>
using namespace std;

// Function to find the fake coin
int findFakeCoin(vector<int> &coins, int start, int end) {
    if (start == end) return start; // only one coin left

    int n = end - start + 1;
    int mid = n / 2;

    int sumLeft = 0, sumRight = 0;
    for (int i = start; i < start + mid; i++) sumLeft += coins[i];
    for (int i = start + mid; i < start + mid*2 && i <= end; i++) sumRight += coins[i];

    if (sumLeft < sumRight) 
        return findFakeCoin(coins, start, start + mid - 1);
    else if (sumRight < sumLeft) 
        return findFakeCoin(coins, start + mid, start + mid*2 - 1);
    else
        return findFakeCoin(coins, start + mid*2, end);
}

int main() {
    int n;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter weights of coins (fake coin lighter): ";
    for(int i = 0; i < n; i++) cin >> coins[i];

    int fakeIndex = findFakeCoin(coins, 0, n - 1);
    cout << "Fake coin is at position: " << fakeIndex + 1 << endl; // 1-indexed
    return 0;
}