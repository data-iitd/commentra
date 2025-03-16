
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a Job with two attributes 'a' and 'b'
typedef struct Job {
    int a; // Represents the time or priority of the job
    int b; // Represents the value or weight of the job
} Job;

// Function to compare two Jobs based on their 'a' attribute
int compareJobs(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;

    // Compare based on 'a' first, and if equal, then by 'b'
    if (job1->a == job2->a)
        return job1->b - job2->b;
    else
        return job1->a - job2->a;
}

int main() {
    // Create a Scanner object to read input
    Scanner sc = new Scanner(System.in);

    // Read the first line of input and split it to get N and M
    String[] line = sc.nextLine().split(" \u2581 ");
    int N = Integer.parseInt(line[0]); // Number of jobs
    int M = Integer.parseInt(line[1]); // Maximum time or limit

    // Create an array to hold the jobs
    Job jobs[N];

    // Read the job details and store them in the array
    for (int i = 0; i < N; i++) {
        line = sc.nextLine().split(" \u2581 ");
        jobs[i].a = Integer.parseInt(line[0]);
        jobs[i].b = Integer.parseInt(line[1]);
    }

    // Sort the jobs based on their 'a' attribute using qsort
    qsort(jobs, N, sizeof(Job), compareJobs);

    int cnt = 0; // Counter to accumulate the total value of jobs processed
    int jobQ[N]; // Array to hold job values in descending order
    int jobQ_size = 0; // Size of the jobQ array

    // Process jobs for each time unit from 1 to M
    for (int i = 1; i <= M; i++) {
        // While there are jobs that can be processed at time i
        int j = 0;
        while (j < N && jobs[j].a <= i) {
            jobQ[jobQ_size++] = jobs[j++].b; // Add the value of the job to jobQ
        }

        // If there are jobs available to process, add the highest value job to the counter
        if (jobQ_size > 0) {
            qsort(jobQ, jobQ_size, sizeof(int), compareJobs); // Sort jobQ in descending order
            cnt += jobQ[--jobQ_size]; // Add the highest value job to cnt
        }
    }

    // Output the total value of jobs processed
    printf("%d\n", cnt);

    return 0;
}
