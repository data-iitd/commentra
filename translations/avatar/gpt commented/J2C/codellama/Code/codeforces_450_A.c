#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h> 
#include <math.h> 
#include <stdint.h> 

#define MAX_QUEUE_SIZE 100000 

typedef struct { 
    int *arr; 
    int front; 
    int rear; 
    int size; 
} Queue; 

Queue *createQueue(int size) { 
    Queue *q = (Queue *)malloc(sizeof(Queue)); 
    q->arr = (int *)malloc(size * sizeof(int)); 
    q->front = q->rear = -1; 
    q->size = size; 
    return q; 
} 

bool isEmpty(Queue *q) { 
    return (q->front == -1 && q->rear == -1); 
} 

bool isFull(Queue *q) { 
    return (q->rear == q->size - 1); 
} 

void enqueue(Queue *q, int val) { 
    if (isFull(q)) { 
        printf("Queue is full\n"); 
        return; 
    } 
    if (isEmpty(q)) { 
        q->front = q->rear = 0; 
    } 
    else { 
        q->rear = (q->rear + 1) % q->size; 
    } 
    q->arr[q->rear] = val; 
} 

int dequeue(Queue *q) { 
    if (isEmpty(q)) { 
        printf("Queue is empty\n"); 
        return -1; 
    } 
    int val = q->arr[q->front]; 
    if (q->front == q->rear) { 
        q->front = q->rear = -1; 
    } 
    else { 
        q->front = (q->front + 1) % q->size; 
    } 
    return val; 
} 

int main() { 
    // Create a Scanner object to read input from the user
    // Scanner sc = new Scanner(System.in); 
    // Read the number of elements (n) and the threshold value (m)
    int n, m; 
    scanf("%d %d", &n, &m); 
    
    // Initialize two queues: one for the values and one for their original indices
    Queue *q1 = createQueue(MAX_QUEUE_SIZE); 
    Queue *q2 = createQueue(MAX_QUEUE_SIZE); 
    
    // Populate the queues with input values and their corresponding indices
    for (int i = 1; i <= n; i++) { 
        int val; 
        scanf("%d", &val); 
        enqueue(q1, val); 
        enqueue(q2, i); 
    } 
    
    // Variable to store the final answer (the index of the last processed element)
    int ans = 0; 
    
    // Process the elements in the queue until it is empty
    while (!isEmpty(q1)) { 
        // Check if the front element of q1 is less than or equal to m
        if (q1->arr[q1->front] <= m) { 
            // If yes, remove it from q1 and update the answer with the corresponding index from q2
            dequeue(q1); 
            ans = dequeue(q2); 
        } 
        // If the front element is greater than m
        else if (q1->arr[q1->front] > m) { 
            // Remove the element, reduce it by m, and add it back to q1
            int x = dequeue(q1); 
            int val = x - m; 
            enqueue(q1, val); 
            
            // Remove the index from q2 and add it back to maintain the order
            int val2 = dequeue(q2); 
            enqueue(q2, val2); 
        } 
    } 
    
    // Output the final answer
    printf("%d\n", ans); 
    return 0; 
} 

