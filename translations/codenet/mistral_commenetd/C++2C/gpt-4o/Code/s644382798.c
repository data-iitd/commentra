#include <stdio.h>
#include <string.h>
#define LEN 100005

typedef struct pp
{
    char name[100];
    int t; // time taken by each process
} P;

P Q[LEN]; // queue to store process information
int head, tail, n; // head and tail indices of the queue, and total number of processes

void enqueue(P x) // function to add a process to the queue
{
    Q[tail] = x;
    tail = (tail + 1) % LEN;
}

P dequeue() // function to remove a process from the queue
{
    P x = Q[head];
    head = (head + 1) % LEN;
    return x;
}

int min(int a, int b) // helper function to find the minimum of two integers
{
    return a < b ? a : b;
}

int main() // main function
{
    int elaps = 0, c; // elapsed time and the number of units processed in each iteration
    int i, q; // loop variables
    P u; // variable to store the process dequeued from the queue

    scanf("%d %d", &n, &q); // read the number of processes and the number of queries

    for (i = 1; i <= n; i++) // initialize the queue with process information
    {
        scanf("%s", Q[i].name);
        scanf("%d", &Q[i].t);
        enqueue(Q[i]); // enqueue each process
    }
    head = 1;
    tail = n + 1;

    while (head != tail) // processing loop
    {
        u = dequeue(); // dequeue a process
        c = min(q, u.t); // calculate the number of units to be processed in this iteration
        u.t -= c; // update the remaining time for the process
        elaps += c; // update the elapsed time
        if (u.t > 0) // if the process still has remaining time, enqueue it again
            enqueue(u);
        else // if the process has been fully processed, print the result
            printf("%s %d\n", u.name, elaps);
    }

    return 0;
}

// <END-OF-CODE>
