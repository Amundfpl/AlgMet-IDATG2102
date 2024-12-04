#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

const std::array<char, 5> allowedDigits = {'0', '1', '6', '8', '9'};

// Check if the number contains only rotatable digits
bool containsOnlyRotatableDigits(const string &numStr) {
    for (char digit : numStr) {
        if (std::find(allowedDigits.begin(), allowedDigits.end(), digit) == allowedDigits.end()) {
            return false; // Non-rotatable digit found
        }
    }
    return true;
}

// Rotate the number and check if it’s equal to its rotated form
int snuOppNed(const int n) {
    string numStr = to_string(n);

    // Check if it contains only rotatable digits
    if (!containsOnlyRotatableDigits(numStr)) {
        return 0;
    }

    // Map digits to their rotated equivalents
    string rotatedStr = "";
    for (int i = numStr.size() - 1; i >= 0; --i) {
        if (numStr[i] == '0') rotatedStr += '0';
        else if (numStr[i] == '1') rotatedStr += '1';
        else if (numStr[i] == '6') rotatedStr += '9';
        else if (numStr[i] == '8') rotatedStr += '8';
        else if (numStr[i] == '9') rotatedStr += '6';
    }

    // Convert rotatedStr back to an integer and return it
    int rotatedNumber = stoi(rotatedStr);
    return rotatedNumber;
}

int main() {
    int count = 0;

    // Go through numbers from 1 to 100,000 and find "rotatable" numbers
    for (int i = 1; i <= 100000; ++i) {
        if (i == snuOppNed(i)) {
            cout << i << " is rotatable." << endl;
            ++count;
        }
    }

    cout << "Total rotatable numbers between 1 and 100000: " << count << endl;
    return 0;
}
