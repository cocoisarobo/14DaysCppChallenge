//day 6

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// you need to implement this function only
bool canBePalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // Check if removing one character resolves the mismatch
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    string s;
    cin >> s; 
    // please don't modify the main function
    cout << (canBePalindrome(s) ? "YES" : "NO");
    return 0;
}
