#include <iostream>
#include <vector>
using namespace std;

// 
vector<int> sol(int n, vector<int>& A) {
    // you have to implement the sol function only
    vector<int> even, odd;

    for(auto& val : A){
        if(val % 2 == 0) {
            even.push_back(val);
        } else {
            odd.push_back(val);
        }
    }

    vector<int> result;
    result.reserve(A.size());
    for(auto& e : even){
        result.push_back(e);
    }

    for(auto& o : odd){
        result.push_back(o);
    }

    return result;
}
int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    // please don't modify the main function
    vector<int> result = sol(n, A);
    for (int i = 0; i < n; i++) {
        if (i == result.size() - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }
    return 0;
}
