//day 5 - INCOMPLETE !!!

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// you just need to implement the function
vector<int> maxInRollingWindow(vector<int>& prices, int k) {
    // you need to write the code here
    deque<int> dq; // Deque to store indices of array elements
    vector<int> max_prices; // Stores the maximum of each window

    for (int i = 0; i < prices.size(); i++) {
        // Remove elements from the front of the deque that are out of the current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove elements from the back of the deque that are smaller than the current element
        while (!dq.empty() && prices[i] >= prices[dq.back()]) {
            dq.pop_back();
        }

        // Add the current element index to the deque
        dq.push_back(i);

        // Add the maximum element of the current window to the result
        if (i >= k - 1) {
            max_prices.push_back(prices[dq.front()]);
        }
    }

    return max_prices;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

   // please do not remove the following code
    vector<int> result = maxInRollingWindow(prices, k);
    for(int i = 0; i < result.size(); i++) {
        if(i == result.size() - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }

    return 0;
}
