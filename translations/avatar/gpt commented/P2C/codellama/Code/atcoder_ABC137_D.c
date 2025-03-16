
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 100000

// A structure to represent a job
typedef struct {
    int day;
    int salary;
} Job;

// A structure to represent a heap
typedef struct {
    Job* jobs;
    int capacity;
    int size;
} Heap;

// A utility function to swap two jobs
void swap(Job* a, Job* b) {
    Job temp = *a;
    *a = *b;
    *b = temp;
}

// A utility function to get the parent index of a given index
int parent(int i) {
    return (i - 1) / 2;
}

// A utility function to get the left child index of a given index
int left(int i) {
    return 2 * i + 1;
}

// A utility function to get the right child index of a given index
int right(int i) {
    return 2 * i + 2;
}

// A utility function to heapify the job heap
void heapify(Heap* h, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < h->size && h->jobs[l].day < h->jobs[i].day) {
        largest = l;
    }

    if (r < h->size && h->jobs[r].day < h->jobs[largest].day) {
        largest = r;
    }

    if (largest != i) {
        swap(&h->jobs[i], &h->jobs[largest]);
        heapify(h, largest);
    }
}

// A utility function to insert a job into the job heap
void insert(Heap* h, Job job) {
    if (h->size == h->capacity) {
        return;
    }

    h->jobs[h->size] = job;
    int i = h->size;
    h->size++;

    while (i != 0 && h->jobs[parent(i)].day < h->jobs[i].day) {
        swap(&h->jobs[i], &h->jobs[parent(i)]);
        i = parent(i);
    }
}

// A utility function to remove the job with the highest day from the job heap
Job remove(Heap* h) {
    if (h->size == 0) {
        return (Job){0, 0};
    }

    Job root = h->jobs[0];
    h->jobs[0] = h->jobs[h->size - 1];
    h->size--;
    heapify(h, 0);

    return root;
}

// A utility function to get the job with the highest day from the job heap
Job peek(Heap* h) {
    if (h->size == 0) {
        return (Job){0, 0};
    }

    return h->jobs[0];
}

// A utility function to get the number of jobs in the job heap
int size(Heap* h) {
    return h->size;
}

// A utility function to get the capacity of the job heap
int capacity(Heap* h) {
    return h->capacity;
}

// A utility function to create a job heap
Heap* createHeap(int capacity) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->jobs = (Job*)malloc(capacity * sizeof(Job));
    h->capacity = capacity;
    h->size = 0;

    return h;
}

// A utility function to destroy a job heap
void destroyHeap(Heap* h) {
    free(h->jobs);
    free(h);
}

// A utility function to print the job heap
void printHeap(Heap* h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d %d\n", h->jobs[i].day, h->jobs[i].salary);
    }
}

// A utility function to print the selected salaries
void printSalaries(Heap* h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d\n", -h->jobs[i].salary);
    }
}

// A utility function to get the total sum of selected salaries
int getTotalSalaries(Heap* h) {
    int total = 0;

    for (int i = 0; i < h->size; i++) {
        total += -h->jobs[i].salary;
    }

    return total;
}

int main() {
    // Read the number of days (n) and the maximum number of jobs (m) from input
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize two heaps: one for jobs (x) and one for selected salaries (y)
    Heap* x = createHeap(n);
    Heap* y = createHeap(m);

    // Read the job details for n days
    for (int i = 0; i < n; i++) {
        // For each day, read the day number and salary
        int day, salary;
        scanf("%d %d", &day, &salary);
        // Push the negative of day and salary onto the heap to create a max-heap
        insert(x, (Job){-day, -salary});
    }

    // Process the jobs in the heap until it's empty
    while (size(x) > 0) {
        // Pop the job with the highest day and salary (due to negation)
        Job job = remove(x);

        // Calculate the remaining capacity for jobs
        int r = m - size(y);

        // If there is enough capacity to take the job
        if (r >= -job.day) {
            // Add the salary to the selected salaries heap
            insert(y, (Job){-job.salary, 0});
        } else {
            // If capacity is full, replace the lowest salary if the new salary is higher
            Job lowest = remove(y);
            insert(y, (Job){-job.salary, 0});
            insert(y, lowest);
        }
    }

    // Output the total sum of selected salaries
    printf("%d\n", getTotalSalaries(y));

    // Destroy the job heaps
    destroyHeap(x);
    destroyHeap(y);

    return 0;
}

