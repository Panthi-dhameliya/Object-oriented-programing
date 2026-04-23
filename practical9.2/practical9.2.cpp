#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Convert to lowercase
string toLower(string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

// Remove punctuation
string cleanWord(string word) {
    string result = "";
    for (char c : word) {
        if (isalnum(c)) {  // keep only letters & digits
            result += c;
        }
    }
    return result;
}

int main() {
    string sentence;

    cout << "Enter a sentence:\n";
    getline(cin, sentence);

    map<string, int> wordCount;
    stringstream ss(sentence);
    string word;

    while (ss >> word) {
        word = toLower(word);
        word = cleanWord(word);

        if (!word.empty()) {  // avoid empty strings
            wordCount[word]++;
        }
    }

    cout << "\nWord Frequencies:\n";
    for (auto it : wordCount) {
        cout << it.first << " : " << it.second << endl;
    }

    return 0;
}
