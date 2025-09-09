#include <iostream>
#include <string>
using namespace std;

int Search(string text, string pattern) {
    if (pattern == "") return 0;

    int n = text.size();
    int m = pattern.size();

//pattern obvs wont exist if the [attern is longer than the text]
    if (m > n) return -1;

    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }
    return -1;
}

int main() {
    cout << "Task 4 tests:\n";

    // test 1: pattern at the beginning
    string t1 = "gulwarina muska";
    string p1 = "gul";
    int ans1 = Search(t1, p1);
    if (ans1 == 0)
        cout << "Pattern at start: PASS\n";
    else
        cout << "Pattern at start: FAIL\n";

    // test 2: pattern at the end
    string t2 = "gulwarina muska";
    string p2 = "muska";
    int ans2 = Search(t2, p2);
    if (ans2 == 10)
        cout << "Pattern at end: PASS\n";
    else
        cout << "Pattern at end: FAIL\n";

    // test 3: pattern not present
    string t3 = "gulwarina";
    string p3 = "meow";
    int ans3 = Search(t3, p3);
    if (ans3 == -1)
        cout << "Pattern not present: PASS\n";
    else
        cout << "Pattern not present: FAIL\n";

    // test 4: empty pattern
    string t4 = "anything";
    string p4 = "";
    int ans4 = Search(t4, p4);
    if (ans4 == 0)
        cout << "Empty pattern: PASS\n";
    else
        cout << "Empty pattern: FAIL\n";

    return 0;
}