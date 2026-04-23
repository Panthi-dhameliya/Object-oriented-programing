#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    string filename;
    ifstream file;

    // 🔹 Retry mechanism for file opening
    while (true) {
        cout << "Enter file name (or type exit): ";
        cin >> filename;

        if (filename == "exit") {
            cout << "Exiting program.\n";
            return 0;
        }

        file.open(filename);

        if (file.is_open()) {
            break;
        } else {
            cout << "Error: File not found! Try again.\n";
        }
    }

    string line;
    int lineNumber = 0;

    cout << "\nProcessing file...\n";

    // 🔹 Read file line-by-line
    while (getline(file, line)) {
        lineNumber++;

        stringstream ss(line);
        double num, sum = 0;
        int count = 0;
        bool valid = true;

        // 🔹 Validate each value in line
        while (ss >> num) {
            sum += num;
            count++;
        }

        // If parsing failed due to invalid data
        if (!ss.eof()) {
            valid = false;
        }

        // 🔹 Output result
        if (valid && count > 0) {
            cout << "Line " << lineNumber
                 << " → Sum = " << sum
                 << ", Avg = " << (sum / count) << endl;
        } else {
            cout << "Line " << lineNumber
                 << " → Invalid data detected (skipped)\n";
        }
    }

    file.close();

    return 0;
}
