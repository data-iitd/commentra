
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iomanip>
#include <bitset>
#include <fstream>
using namespace std;

int main() {
    // Declare static members for output stream and print writer
    static FILE *outputStream = stdout;
    static FILE *out = fopen("output.txt", "w");

    // Read the number of test cases
    int t;
    scanf("%d", &t);

    // Initialize priority queues for max and min values
    priority_queue<int, vector<int>, greater<int> > pqmax;
    priority_queue<int> pqmin;

    // Initialize variables to keep track of sums and the minimum value
    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    // Process each test case
    while (t-- > 0) {
        // Read the input for the current test case
        char cmd[2];
        scanf("%s", cmd);

        // If the command is '2', calculate and print the result
        if (cmd[0] == '2') {
            long long ans = min;
            ans *= pqmin.size();
            ans -= sumMin;
            long long ans1 = min;
            ans1 *= pqmax.size();
            ans1 = sumMax - ans1;
            fprintf(out, "%lld %lld\n", min, ans + ans1 + sumb);
        } 
        // If the command is '1', add the new value to the appropriate priority queue
        else {
            int in;
            long long val;
            scanf("%d%lld", &in, &val);
            sumb += val;

            if (in > min) {
                pqmax.push(in);
                sumMax += in;
            } else {
                pqmin.push(in);
                sumMin += in;
            }

            // Balance the priority queues
            if (pqmin.size() > pqmax.size()) {
                sumMax += pqmin.top();
                sumMin -= pqmin.top();
                pqmax.push(pqmin.top());
                pqmin.pop();
            }

            if (pqmin.size() < pqmax.size()) {
                sumMax -= pqmax.top();
                sumMin += pqmax.top();
                pqmin.push(pqmax.top());
                pqmax.pop();
            }

            // Update the minimum value
            min = pqmin.top();
        }
    }

    // Close the print writer to flush the output
    fclose(out);
    return 0;
}

Translate the above C code to Python and end with comment "