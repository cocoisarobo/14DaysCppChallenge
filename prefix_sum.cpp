#include <iostream>
#include <vector>
using namespace std;

// complete this function please
vector<int> sol(int n, vector<int>& A, int q, vector<pair<int, int>>& queries) {
    // your code here
    // Create a prefix sum array
    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }

    // Process each query
    vector<int> results(q);
    for (int i = 0; i < q; i++) {
        int l = queries[i].first;
        int r = queries[i].second;
        results[i] = prefixSum[r] - prefixSum[l - 1];
    }

    return results;
}

int main() {
    int n, q;
    cin >> n;

    vector<int> A(n + 1, 0);  // 1-based index, so size is n+1
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r};
    }

    // Call the sol function to process the queries
    vector<int> result = sol(n, A, q, queries);

    // Output the results
    for (int i = 0; i < result.size(); i++) {
        if (i == result.size() - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }

    return 0;
}
 
