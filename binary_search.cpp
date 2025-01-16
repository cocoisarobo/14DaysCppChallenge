// DAY 12 SOLUTION

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to check if the total time with a given speed is within the time limit
bool canCompleteWithinTime(const vector<int>& dist, double timeLimit, int speed) {
    double totalTime = 0.0;
    for (int d : dist) {
        totalTime += ceil((double)d / speed);
    }
    return totalTime <= timeLimit;
}

// Function to find the minimum speed required to complete the journey within timeLimit
int minSpeedOnTime(const vector<int>& dist, double timeLimit) {
    int left = 1, right = 1e7; // setting a large enough right boundary for the speed
    
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if it's possible to complete the journey with this speed
        if (canCompleteWithinTime(dist, timeLimit, mid)) {
            result = mid;  // this speed works, try to find a smaller one
            right = mid - 1;
        } else {
            left = mid + 1;  // this speed doesn't work, try a larger speed
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    double t;
    cin >> t;
    vector<int> dist(n);
    for (int i = 0; i < n; i++) {
        cin >> dist[i];
    }

    cout << minSpeedOnTime(dist, t);
    return 0;
}
