#include <iostream>
#include <vector>
using namespace std;

// you have to implement the mostInfluentialUser() only
int mostInfluentialUser(const vector<int> &influenceScore) {
    int maxScore = -1;
    int userIndex = -1;

    for (int i = 0; i < influenceScore.size(); i++) {
        if (influenceScore[i] > maxScore) {
            maxScore = influenceScore[i];
            userIndex = i;
        } else if (influenceScore[i] == maxScore && i < userIndex) {
            userIndex = i; // Tie-breaking by smaller index
        }
    }

    return userIndex;
}

int main() {
    // Read input
    int n, m;
    cin >> n >> m;
    vector<int> influenceScore(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u != v) { 
            influenceScore[v]++;
        }
    }
    // please don't change the main function
    cout << mostInfluentialUser(influenceScore);
    return 0;
}       
