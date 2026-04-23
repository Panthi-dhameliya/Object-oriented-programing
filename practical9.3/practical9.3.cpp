#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    set<int> s;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        s.insert(value);  // duplicates automatically ignored
    }

    // 🔹 Display using iterators
    cout << "\nUnique elements (sorted using set): ";
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }

    // 🔹 Convert set to vector
    vector<int> v(s.begin(), s.end());

    cout << "\n\nConverted to vector: ";
    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}
