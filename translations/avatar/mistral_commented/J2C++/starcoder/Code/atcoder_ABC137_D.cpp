#include <bits/stdc++.h> // Importing the standard library

using namespace std; // Using the standard namespace

class Job { // Defining a class named Job
    int a; // Declaring an integer variable named a
    int b; // Declaring an integer variable named b

    Job(int a, int b) { // Constructor of the Job class
        this->a = a; // Initializing the variable a with the argument passed to the constructor
        this->b = b; // Initializing the variable b with the argument passed to the constructor
    }
};

struct JobComp { // Defining a structure named JobComp
    bool operator()(Job a, Job b) { // Defining the operator method for implementing the comparison operator
        if (a.a == b.a) { // Comparing the a values of the current and other Job objects
            return a.b < b.b; // If the a values are equal, comparing the b values
        } else {
            return a.a < b.a; // If the a values are not equal, comparing the a values
        }
    }
};

int main() { // Defining the main function
    int N, M; // Declaring two integer variables named N and M
    cin >> N >> M; // Reading the first line of input from the standard input and storing it in the variables N and M

    priority_queue<Job, vector<Job>, JobComp> q; // Creating a new priority queue named q with the JobComp structure as the comparator

    for (int i = 0; i < N; i++) { // Iterating through the number of jobs
        int a, b; // Declaring two integer variables named a and b
        cin >> a >> b; // Reading the next line of input from the standard input and storing it in the variables a and b
        q.push(Job(a, b)); // Adding a new Job object to the priority queue
    }

    int cnt = 0; // Initializing the counter variable to 0
    priority_queue<int, vector<int>, greater<int>> jobQ; // Creating a new priority queue named jobQ with the greater<int> structure as the comparator

    for (int i = 1; i <= M; i++) { // Iterating through the number of machines
        while (!q.empty()) { // While the priority queue is not empty
            Job job = q.top(); // Getting the Job object at the head of the priority queue
            if (job.a <= i) { // If the machine number is greater than or equal to the job a
                jobQ.push(job.b); // Adding the benefit of the job to the jobQ
                q.pop(); // Removing the Job object from the priority queue
            } else { // If the machine number is less than the job a
                break; // Exiting the while loop
            }
        }

        if (!jobQ.empty()) { // If the jobQ is not empty
            cnt += jobQ.top(); // Adding the benefit of the job to the counter variable and removing it from the jobQ
        }
    }

    cout << cnt; // Printing the value of the counter variable
    return 0; // Returning 0 from the main function
}

