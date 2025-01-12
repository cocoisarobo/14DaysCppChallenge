#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Quality {
    string quality;
    int required;
};
// You need to implement the function below
string selectStreamQuality(int bandwidth, vector<Quality>& qualities) {
    // Your code here
    if(qualities.empty()) return "No Quality Available";

    sort(qualities.begin(), qualities.end(), [](const Quality& a, const Quality& b) {
        return a.required < b.required;
    });

    string bestQuality = "No Quality Available";

    for (const auto& q : qualities) {
        if (q.required <= bandwidth) {
            bestQuality = q.quality;
        } else {
            break;
        }
    }

    return bestQuality;
}

int main() {
    int bandwidth;
    cin >> bandwidth;

    int n;
    cin >> n;

    vector<Quality> qualities(n);
    for (int i = 0; i < n; ++i) {
        cin >> qualities[i].quality >> qualities[i].required;
    }

    cout << selectStreamQuality(bandwidth, qualities);
}
