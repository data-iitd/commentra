
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Taking the number of elements N and the number of queries K as input
    int N, K;
    scanf("%d %d", &N, &K);

    // Creating an empty list to store positive numbers and another empty list to store negative numbers
    int lst[N], lst_p[N], lst_m[N];
    int lst_p_len = 0, lst_m_len = 0;

    // Iterating through the list to find positive and negative numbers
    for (int i = 0; i < N; i++) {
        scanf("%d", &lst[i]);
        if (lst[i] == 0) {
            K--;
        } else if (lst[i] > 0) {
            lst_p[lst_p_len++] = lst[i];
        } else if (lst[i] < 0) {
            lst_m[lst_m_len++] = lst[i];
        }
    }

    // Initializing variables p and m to 0 and setting the initial values of x and y
    int p = 0, m = 0, x = 0, y = lst_m_len - 1;
    int lastx = lst_p_len, lasty = lst_m_len;

    // Function to check the minimum number of moves required to make the sum of the first k elements equal to or less than 0
    int check(int k) {
        // Initializing the answer as a large number
        int ans = 1000000000;

        // Iterating through all possible combinations of taking elements from positive and negative lists
        for (int j = 0; j <= k; j++) {
            // If the index j is greater than the length of the list of positive numbers or if the number of elements to be taken from negative list is greater than the number of negative elements, then skip this iteration
            if (j > lastx || k - j > lasty) {
                continue;
            }

            // If j is 0, then p is initialized to 0
            if (j == 0) {
                p = 0;
            } else {
                // If j is not 0, then p is the last element of the list of positive numbers
                p = lst_p[j - 1];
            }

            // If k - j is 0, then m is initialized to 0
            if (k - j == 0) {
                m = 0;
            } else {
                // If k - j is not 0, then m is the last element of the list of negative numbers
                m = lst_m[lasty - (k - j)];
            }

            // Updating the answer with the minimum of the current answer and the sum of the absolute difference of p and m and the sum of p and m
            ans = (ans < 2 * p + abs(m)? ans : 2 * p + abs(m));
            ans = (ans < p + 2 * abs(m)? ans : p + 2 * abs(m));
        }

        // Returning the answer
        return ans;
    }

    // Printing the minimum number of moves required to make the sum of the first K elements equal to or less than 0
    printf("%d\n", check(K));

    return 0;
}
