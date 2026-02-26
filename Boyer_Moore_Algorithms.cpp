#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define NO_OF_CHARS 256

// Preprocess for Bad Character Heuristic
void badCharHeuristic(const string &pat, vector<int> &badChar) {
    int m = pat.size();
    for (int i = 0; i < NO_OF_CHARS; i++) 
        badChar[i] = -1;
    for (int i = 0; i < m; i++) 
        badChar[(int)pat[i]] = i;
}

// Boyer-Moore Search (Bad Character Heuristic)
void BoyerMooreSearch(const string &txt, const string &pat) {
    int n = txt.size();
    int m = pat.size();
    vector<int> badChar(NO_OF_CHARS);

    badCharHeuristic(pat, badChar);

    int s = 0; // shift of the pattern with respect to text
    while (s <= (n - m)) {
        int j = m - 1;

        // Compare from end of pattern
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0) {
            cout << "Pattern found at index " << s << endl;

            // Shift pattern so next character in text aligns with last occurrence in pattern
            s += (s + m < n) ? m - badChar[txt[s + m]] : 1;
        } else {
            s += max(1, j - badChar[txt[s + j]]);
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    BoyerMooreSearch(text, pattern);
    return 0;
}