// ============================================================
//  Factorial Program - Clean Explanation
//  Example input: factoriel = 5  →  Output: 120
// ============================================================

#include <iostream>   // cin, cout, endl
#include <cmath>      // ⚠️ NOT USED - can be removed
#include <iomanip>    // ⚠️ NOT USED - can be removed

using namespace std;  // Lets us write cout instead of std::cout

int main()
{
    // Two integer variables created in memory (stack)
    // ⚠️ 'factoriel' has NO value yet — dangerous until cin fills it
    // ✅ 'result' starts at 1 (neutral value for multiplication)
    int factoriel, result = 1;

    // Print a message asking the user for input
    cout << " Please enter the number of you want to factoriel " << endl;

    // Program PAUSES here, waits for user to type a number
    // User types 5 → stored into factoriel
    cin >> factoriel;

    // ── FOR LOOP ──────────────────────────────────────────────
    // Start: i = 5
    // Condition: keep looping while i >= 1
    // Update: i-- means i = i - 1 after each pass
    //
    // Pass 1: result = 1   × 5 = 5    → prints 5
    // Pass 2: result = 5   × 4 = 20   → prints 4
    // Pass 3: result = 20  × 3 = 60   → prints 3
    // Pass 4: result = 60  × 2 = 120  → prints 2
    // Pass 5: result = 120 × 1 = 120  → prints 1
    // i becomes 0 → (0 >= 1) is FALSE → loop stops
    for (int i = factoriel; i >= 1; i--)
    {
        result = result * i;  // Multiply running total by i
        cout << "    " << i;  // Print current i (all on same line)
    }

    // Print the final answer
    // Output: "The factoriel of the number 5 is 120"
    cout << " The factoriel of the number " << factoriel << " is " << result << endl;

    return 0; // Tell the OS: program finished successfully
}

// ============================================================
//  ⚠️  KNOWN BUGS:
//
//  1. int OVERFLOW  → 13! is too big for int. Use 'long long result = 1'
//  2. NEGATIVE INPUT → loop never runs, result stays 1. Wrong answer.
//  3. TYPO          → 'factoriel' should be 'factorial'
// ============================================================
