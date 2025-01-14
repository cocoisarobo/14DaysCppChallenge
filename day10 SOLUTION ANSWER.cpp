// SOLUTION ANSWER

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// you just need to implement the function
vector<int> maximizeAdRevenue(const vector<int> &viewer_retention, const vector<int> &ad_value, int k)
{

    int n = (int)viewer_retention.size();
    if(n == 0 || k == 0) return {};

    //precompute score for each second: score[i] = viewer_retention[i] * ad_value[i]
    vector<long long> score(n);
    for(int i = 0; i < n; i++) {
        score[i] = 1LL * viewer_retention[i] * ad_value[i]; //1LL (?)
    }

    //dp[i][j] = max total score using first i seconds (1-based indexing)
    //          placing exactly j ads with no two consecutive ads
    // create (n+1) * (k+1) table and initialize to 0
    static const long long NEG_INF = -1e15;
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0LL)); //0LL (?)

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            //option 1: do not place an ad at second i
            long long best = dp[i-1][j];

            //option 2: place an ad at second i (then i-1 must not have an ad)
            // i => index (i-1) in the score array.
            if(i >= 2){
                best = max(best, dp[i-2][j-1] + score[i-1]);
            } else {
                // i == 1
                // if we have j >= 1, we can place an ad in the 1st second
                best = max(best, score[i-1]);
            }

            dp[i][j] = best;
        }
    }

    // value dp[n][k] holds the maximum possible score, but we want the indices too
    // backtrack to find which indices were choosen
    vector<int> chosen;
    int i = n, j = k;
    while(i > 0 && j > 0){
        // if dp[i][j] came from dp[i-1][j], then we did NOT place an ad at i
        if(dp[i][j] == dp[i-1][j]){
            i -= 1;
        } else {
            // otherwise we placed an ad at second i
            chosen.push_back(i-1); // record the (0 based) index
            i -= 2; //skip the adjacent second
            j -= 1;
        }
    }

    // the chosen indices are in reverse order, so we reverse them
    reverse(chosen.begin(), chosen.end());
    return chosen;
}


int main() {
    vector<int> viewer_retention;
    vector<int> ad_value;
    int k;
    int n;

    cin >> n; 
    cin >> k;
    // please don't change the main function
    for (int i = 0; i < n; ++i) {
        int retention;
        cin >> retention;
        viewer_retention.push_back(retention);
    }
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        ad_value.push_back(value);
    }

    vector<int> result = maximizeAdRevenue(viewer_retention, ad_value, k);
    for (int i = 0; i < result.size(); ++i) {
        if (i == result.size() - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }
    return 0;
}
