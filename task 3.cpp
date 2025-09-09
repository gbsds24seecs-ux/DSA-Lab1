#include <iostream>
using namespace std;

// finds all indices of a given element in an array
// Input: Array and a key.
// Output: Array of indices.
int findAllIndices(int arr[], int n, int key, int out[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            out[count] = i;
            count++;
        }
    }
    return count;  // return how many found
}

// print the Output: Array of indices in simple form
void printArray(int out[], int count) {
    cout << "Indices: [";
    for (int i = 0; i < count; i++) {
        cout << out[i];
        if (i < count - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    cout << "Task 3 tests:\n";

    // Test 1: Multiple occurrences.
    int a1[6] = {1, 2, 3, 2, 4, 2};
    int out1[10];
    int count1 = findAllIndices(a1, 6, 2, out1);
    printArray(out1, count1);
    if (count1 == 3 && out1[0] == 1 && out1[1] == 3 && out1[2] == 5)
        cout << "Multiple occurrences: PASS\n";
    else
        cout << "Multiple occurrences: FAIL\n";

    // Test 2: Key not present.
    int a2[3] = {7, 8, 9};
    int out2[10];
    int count2 = findAllIndices(a2, 3, 2, out2);
    printArray(out2, count2);
    if (count2 == 0)
        cout << "Key not present: PASS\n";
    else
        cout << "Key not present: FAIL\n";

    // Test 3: Empty array.
    // pass n = 0 so function treats it as empty; array storage still declared
    int a3_dummy[1] = {0};
    int out3[10];
    int count3 = findAllIndices(a3_dummy, 0, 1, out3);
    printArray(out3, count3);
    if (count3 == 0)
        cout << "Empty array: PASS\n";
    else
        cout << "Empty array: FAIL\n";

    return 0;
}