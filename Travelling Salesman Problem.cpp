#include <iostream>
#include <climits>
using namespace std;

int n;
int dist[10][10];
int dp[1 << 10][10];

// Function to solve TSP using DP + Bitmasking
int tsp(int mask, int pos) {
    if(mask == (1 << n) - 1)  // If all cities visited
        return dist[pos][0]; // Return to starting city

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] +
                         tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter distance matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Initialize DP table
    for(int i = 0; i < (1 << n); i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;

    cout << "Minimum travelling cost: " << tsp(1, 0);

    return 0;
}