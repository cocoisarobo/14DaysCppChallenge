#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string mostCommonWord(string document) {
  
    unordered_map<string, int> words;
    stringstream ss(document); // To split the document into words
    string word;
    int max_frequency = 0;
    string most_frequent_word;
   
    while (ss >> word) {
        words[word]++;
    }

    for (const auto &entry : words) {
        if (entry.second > max_frequency) {
            max_frequency = entry.second;
            most_frequent_word = entry.first;
        }
    }
  
    transform(most_frequent_word.begin(), most_frequent_word.end(), most_frequent_word.begin(), ::tolower);
    // cout << "Most frequent word: " << most_frequent_word << " (Frequency: " << max_frequency << ")" << endl;

    return most_frequent_word;
}

int main() {
    string document;
    cin >> document;

    // please do not change the below code
    cout << mostCommonWord(document);
    return 0;
}
