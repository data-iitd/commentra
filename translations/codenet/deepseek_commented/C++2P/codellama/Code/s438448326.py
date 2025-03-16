#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    # Step 1: Reading Input
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    # Step 2: Initializing Variables
    m1 = 0
    m2 = 0
    maxD = 0.0

    # Step 3: Nested Loops to Iterate Over Possible Combinations
    for i in range(0, 100*A):
        mA = 100 * A*i
        for j in range(0, 100*B):
            mB = 100 * B*j
            for k in range(0, C):
                mC = C*k
                for l in range(0, D):
                    mD = D*l
                    # Step 4: Calculating Density and Updating Results
                    if (mA + mB)*E / 100 < mD + mC:
                        break
                    d = (mD + mC) / (mA + mB + mC + mD)
                    if d > maxD:
                        m1 = mA + mB + mC + mD
                        m2 = mC + mD
                        maxD = d

    # Step 5: Handling Edge Cases
    if m1 == 0:
        m1 = 100 * A

    # Step 6: Output the Results
    print(m1, m2)
    return 0
}

