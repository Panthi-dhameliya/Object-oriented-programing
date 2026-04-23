#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse
using namespace std;

// Function to display vector
void display(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

// Manual reversal using iterators
void manualReverse(vector<int>& v) {
    vector<int>::iterator start = v.begin();
    vector<int>::iterator end = v.end() - 1;

    while (start < end) {
        // swap elements
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    vector<int> v;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        v.push_back(value);
    }

    cout << "\nOriginal Vector: ";
    display(v);

    // 🔹 Method 1: Using std::reverse
    vector<int> v1 = v; // copy
    reverse(v1.begin(), v1.end());

    cout << "Reversed using std::reverse(): ";
    display(v1);

    // 🔹 Method 2: Manual iterator reversal
    vector<int> v2 = v; // copy
    manualReverse(v2);

    cout << "Reversed using manual iterators: ";
    display(v2);

    return 0;
}
