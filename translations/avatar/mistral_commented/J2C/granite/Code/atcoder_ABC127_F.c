

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    char s[10];
    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;
    priority_queue<int, vector<int>, greater<int> > pqmax;
    priority_queue<int> pqmin;

    while (t--) {
        scanf("%s", s);
        if (s[0] == '2') {
            long long ans = min;
            ans *= pqmin.size();
            ans -= sumMin;
            long long ans1 = min;
            ans1 = sumMax - ans1;
            printf("%d %lld\n", min, ans + ans1 + sumb);
        } else {
            int in;
            scanf("%d", &in);
            sumb += atoll(strtok(NULL, " "));
            if (in > min) {
                pqmax.push(in);
                sumMax += in;
            } else {
                pqmin.push(in);
                sumMin += in;
            }
            if (pqmin.size() > pqmax.size()) {
                sumMax += pqmin.top();
                sumMin -= pqmin.top();
                pqmax.push(pqmin.top());
                pqmin.pop();
            } else if (pqmin.size() < pqmax.size()) {
                sumMax -= pqmax.top();
                sumMin += pqmax.top();
                pqmin.push(pqmax.top());
                pqmax.pop();
            }
            min = pqmin.top();
        }
    }
    return 0;
}

