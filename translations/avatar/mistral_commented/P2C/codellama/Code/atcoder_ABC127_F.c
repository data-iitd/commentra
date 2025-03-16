#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the input size and initialize an empty list for answers
int q = 0;
int ans[2] = {0, 0};

// Import heapq module for priority queue implementation
#include "heapq.h"

// Initialize empty priority queues for piles p1 and p2
int *p1 = NULL;
int *p2 = NULL;

// Initialize variables for sums of balls and priority queues
int sum_b = 0;
int sum_p1 = 0;
int sum_p2 = 0;

// Iterate through each query
for (int i = 0; i < q; i++) {
    // Check if the current query is to find the answer
    if (ans[i] == 2) {
        // Check if both piles have equal number of balls
        if (p1[0] == p2[0]) {
            // Calculate the answer and print it
            printf("%d %d\n", -p2[0], sum_p1 - p1[0] * -p2[0] + p2[0] * -p2[0] - sum_p2 + sum_b);
        } else {
            // Calculate the answer and print it
            printf("%d %d\n", p1[0], sum_p1 - p1[0] * p1[0] + p2[0] * p1[0] - sum_p2 + sum_b);
        }
    }

    // Else, the current query is to add balls to a pile
    else {
        // Add the number of balls to the total sum
        sum_b += ans[i];

        // If pile p1 is empty, add the ball to it
        if (p1[0] == 0) {
            heapq_push(p1, ans[i]);
            sum_p1 += ans[i];
        }

        // Else, check if the ball can be added to pile p1
        else if (p1[0] <= ans[i]) {
            heapq_push(p1, ans[i]);
            sum_p1 += ans[i];
        }

        // Else, add the ball to pile p2 and adjust the sums accordingly
        else {
            heapq_push(p2, -ans[i]);
            sum_p2 += ans[i];
            sum_p1 -= ans[i];
            sum_p2 -= ans[i];
        }

        // Adjust the priority queues if necessary
        if (p1[0] < p2[0]) {
            int k = heapq_pop(p2);
            heapq_push(p1, -k);
            sum_p2 += k;
            sum_p1 -= k;
        }

        if (p1[0] - 1 > p2[0]) {
            int k = heapq_pop(p1);
            heapq_push(p2, -k);
            sum_p1 -= k;
            sum_p2 += k;
        }
    }
}

// End of code
