#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    map<string, vector<string>> directory;
    int choice;
    string folder, file;

    do {
        cout << "\n--- Directory Menu ---\n";
        cout << "1. Add Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter folder name: ";
            cin >> folder;

            if (directory.find(folder) == directory.end()) {
                directory[folder] = vector<string>();
                cout << "Folder added successfully.\n";
            } else {
                cout << "Folder already exists.\n";
            }
            break;

        case 2:
            cout << "Enter folder name: ";
            cin >> folder;

            if (directory.find(folder) != directory.end()) {
                cout << "Enter file name: ";
                cin >> file;
                directory[folder].push_back(file);
                cout << "File added successfully.\n";
            } else {
                cout << "Folder not found!\n";
            }
            break;

        case 3:
            cout << "\n--- Directory Contents ---\n";

            // Map iterator (sorted order)
            for (auto it = directory.begin(); it != directory.end(); ++it) {
                cout << "Folder: " << it->first << endl;

                // Vector iterator
                for (auto fileIt = it->second.begin(); fileIt != it->second.end(); ++fileIt) {
                    cout << "  - " << *fileIt << endl;
                }
            }
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
