#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {
    int t, m, n, x, y, z;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &m);
        int *memory = new int[m];
        memset(memory, 0, sizeof(int) * m);
        int allocIdx = 0;
        while (true) {
            char op[10];
            scanf("%s", op);
            if (strcmp(op, "alloc") == 0) {
                scanf("%d", &n);
                int len = 0;
                bool canAlloc = false;
                for (int i = 0; i < m; i++) {
                    if (memory[i] == 0) len++;
                    else len = 0;
                    if (len == n) {
                        canAlloc = true;
                        len = i - n + 1;
                        break;
                    }
                }
                if (canAlloc) {
                    allocIdx++;
                    for (int i = len; i < len + n; i++) memory[i] = allocIdx;
                    printf("%d\n", allocIdx);
                } else printf("NULL\n");
            } else if (strcmp(op, "erase") == 0) {
                scanf("%d", &x);
                if (x <= 0) {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                    break;
                }
                bool hasErased = false;
                for (int i = 0; i < m; i++) {
                    if (memory[i] == x) {
                        memory[i] = 0;
                        hasErased = true;
                    }
                }
                if (!hasErased) printf("ILLEGAL_ERASE_ARGUMENT\n");
            } else if (strcmp(op, "defragment") == 0) {
                int d = 0;
                for (int i = 0; i < m; i++) {
                    if (memory[i] == 0) d++;
                    else memory[i - d] = memory[i];
                }
                for (int i = m - d; i < m; i++) memory[i] = 0;
            } else {
                printf("h\n");
            }
        }
        delete[] memory;
    }
    return 0;
}
