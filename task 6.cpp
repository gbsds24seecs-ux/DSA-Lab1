#include <iostream>
#include <cstdlib>
using namespace std;

// findMode: most frequent element (modeValue), whether the array has a mode (hasMode),
// and whether there are multiple modes (multiple).
void findMode(int arr[], int n, int &modeValue, bool &hasMode, bool &multiple) {
    if (n == 0) {
        hasMode = false;
        multiple = false;
        return;
    }

    hasMode = true;
    multiple = false;
    int bestCount = 0;
    modeValue = arr[0];
    
    // Loop to check the frequency of each element
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j] == arr[i]) ++count;
        }
        
        // If this element has a higher count, update mode and reset multiple flag
        if (count > bestCount) {
            bestCount = count;
            modeValue = arr[i];
            multiple = false;
        } else if (count == bestCount && arr[i] != modeValue) {
            // If another element has the same highest frequency
            multiple = true;
        }
    }
}

// Simple equality check for tests (we can directly compare the values in main)
bool equalInt(int a, int b) { return a == b; }

int main() {
    cout << "Task 6 tests:\n";

    // Test 1: unique mode
    int a1[] = {1, 2, 1, 3};
    int mode; bool hasMode, multiple;
    findMode(a1, 4, mode, hasMode, multiple);
    cout << "Unique mode: " << (hasMode && mode == 1 && !multiple ? "PASS" : "FAIL") << "\n";

    // Test 2: multiple modes (tie)
    int a2[] = {4, 5, 4, 5};
    findMode(a2, 4, mode, hasMode, multiple);
    // mode may be 4 or 5, but multiple should be true
    cout << "Multiple modes: " << (hasMode && multiple ? "PASS" : "FAIL") << "\n";

    // Test 3: empty array
    int a3[] = {};
    findMode(a3, 0, mode, hasMode, multiple);
    cout << "Empty array: " << (!hasMode ? "PASS" : "FAIL") << "\n";

    return 0;
}