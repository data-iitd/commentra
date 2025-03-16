#include <stdio.h>

<<<<<<< HEAD
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    char *ans;
=======
void solve() {
    // Function is defined but not used in this translation
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    char* ans;
>>>>>>> 98c87cb78a (data updated)

    if (a == 1 || b == 1) {
        if (a == 1 && b == 1) {
            ans = "Draw";
        } else if (a == 1) {
            ans = "Alice";
        } else {
            ans = "Bob";
        }
    } else {
        if (a == b) {
            ans = "Draw";
        } else if (a > b) {
            ans = "Alice";
        } else {
            ans = "Bob";
        }
    }
    printf("%s\n", ans);

    return 0;
}

// <END-OF-CODE>
