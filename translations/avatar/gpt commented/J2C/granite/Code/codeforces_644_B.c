
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    int n, b;
    scanf("%d %d", &n, &b);

    // Initialize an array to store the results
    long long ans[n];

    // Create a linked list to act as a queue for managing time values
    struct Node {
        long long time;
        struct Node *next;
    };
    struct Node *head = NULL, *tail = NULL;

    // Process each element based on the input
    for (int i = 0; i < n; i++) {
        // Read the time (t) and duration (d) for the current element
        int t, d;
        scanf("%d %d", &t, &d);

        // Remove elements from the front of the queue that are no longer valid (i.e., their time is less than or equal to t)
        struct Node *curr = head;
        while (curr!= NULL && curr->time <= t) {
            struct Node *next = curr->next;
            free(curr);
            curr = next;
        }
        head = curr;

        // Check if the size of the queue is within the allowed limit
        if (head == NULL || (tail!= NULL && tail->next == NULL)) {
            // If the queue is empty, set the answer to the current time (t) plus duration (d)
            // Otherwise, set it to the last element in the queue plus duration (d)
            ans[i] = (head == NULL? t : tail->time) + d;

            // Add the computed answer to the queue
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->time = ans[i];
            newNode->next = NULL;
            if (tail == NULL) {
                head = newNode;
            } else {
                tail->next = newNode;
            }
            tail = newNode;
        } else {
            // If the queue size exceeds the limit, set the answer to -1
            ans[i] = -1;
        }
    }

    // Print the results stored in the ans array
    for (int i = 0; i < n; ++i) {
        printf("%lld ", ans[i]);
    }

    return 0;
}
