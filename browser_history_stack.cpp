#include <iostream>
#include <string>
#include <vector>
using namespace std;

// you just need to implement the BrowserHistory class below
class BrowserHistory {
private:
    vector<string> history;  // To store the URLs
    int current;             // Points to the current page in the history

public:
    // Constructor initializes the browser with the homepage
    BrowserHistory(string homepage) {
        history.push_back(homepage); // Add the homepage to history
        current = 0;                 // Start at the homepage
    }

    // Visit a new URL and invalidate all forward history
    void visit(string url) {
        // Remove forward history if any exists
        history.resize(current + 1);
        // Add the new URL and move the pointer to it
        history.push_back(url);
        current++;
    }

    // Move back by `steps` steps, but not beyond the first URL
    string back(int steps) {
        current = max(0, current - steps); // Ensure we don't go out of bounds
        return history[current];          // Return the current page
    }

    // Move forward by `steps` steps, but not beyond the last visited URL
    string forward(int steps) {
        current = min((int)history.size() - 1, current + steps); // Ensure we don't exceed bounds
        return history[current];                                // Return the current page
    }
};

int main() {
    int n;
    cin >> n; 
    string operation, url;
    int steps;

    // please do not change below code
    BrowserHistory browserHistory("chaicode.com");
    
    string result = "chaicode.com ";
    for (int i = 0; i < n; i++) {
        cin >> operation;

        if (operation == "visit") {
            cin >> url;
            browserHistory.visit(url);
            result += url + " ";
        } else if (operation == "back") {
            cin >> steps;
            result += browserHistory.back(steps) + " ";
        } else if (operation == "forward") {
            cin >> steps;
            result += browserHistory.forward(steps) + " ";
        }
    }
    
    cout << result.substr(0, result.size() - 1);

    return 0;
}
