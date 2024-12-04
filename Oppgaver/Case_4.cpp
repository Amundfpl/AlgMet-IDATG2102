//
// Created by amund on 06.11.2024.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if any number is a prefix of another
bool prefix(vector<string> &numbers) {
    // Sort the array lexicographically
    sort(numbers.begin(), numbers.end());

    // Iterate through the sorted array and check adjacent pairs
    for (size_t i = 0; i < numbers.size() - 1; ++i) {
        if (numbers[i + 1].substr(0, numbers[i].size()) == numbers[i]) {
            // Print the pair involved in the prefix case
            cout << "Prefix found: " << numbers[i] << " is a prefix of " << numbers[i + 1] << endl;
            return true;
        }
    }

    // If no prefixes are found
    return false;
}

int main() {
    vector<string> phoneNumbers = {"113", "911", "1135", "81549300", "815"};

    if (!prefix(phoneNumbers)) {
        cout << "No prefixes found in the list." << endl;
    }

    return 0;
}
