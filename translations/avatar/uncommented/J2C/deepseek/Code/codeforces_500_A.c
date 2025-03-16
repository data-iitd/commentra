#include <stdio.h>
#include <stdbool.h>

bool dfs(int currpos, int arr[], int target, int n) {
    if (currpos == target) return true;
    if (currpos > n) return false;
    return dfs(currpos + arr[currpos - 1], arr, target, n);
}

int main() {
    int n, goal;
    scanf("%d %d", &n, &goal);
    int arr[n - 1];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }
    bool isFound = dfs(1, arr, goal, n);
    if (isFound) printf("YES\n");
    else printf("NO\n");
    return 0;
}
