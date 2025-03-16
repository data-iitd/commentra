
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the user
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize two queues: one for the values and one for their original indices
    int *q1 = (int*)malloc(n * sizeof(int));
    int *q2 = (int*)malloc(n * sizeof(int));

    // Populate the queues with input values and their corresponding indices
    for (int i = 0; i < n; i++) {
        scanf("%d", &q1[i]);
        q2[i] = i + 1;
    }

    // Variable to store the final answer (the index of the last processed element)
    int ans = 0;

    // Process the elements in the queue until it is empty
    int front1, front2;
    while (1) {
        front1 = q1[0];
        front2 = q2[0];

        if (front1 <= m) {
            // If yes, remove it from q1 and update the answer with the corresponding index from q2
            ans = front2;
            for (int i = 0; i < n - 1; i++) {
                q1[i] = q1[i + 1];
                q2[i] = q2[i + 1];
            }
            n--;
        } else if (front1 > m) {
            // Remove the element, reduce it by m, and add it back to q1
            q1[0] = front1 - m;
            for (int i = 0; i < n - 1; i++) {
                q1[i + 1] = q1[i];
                q2[i + 1] = q2[i];
            }
            n--;
        } else {
            break;
        }
    }

    // Output the final answer
    printf("%d\n", ans);

    // Free the memory allocated for the queues
    free(q1);
    free(q2);

    return 0;
}
