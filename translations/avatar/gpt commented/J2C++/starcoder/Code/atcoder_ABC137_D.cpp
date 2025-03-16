#include <bits/stdc++.h>
using namespace std;

// Class representing a Job with two attributes 'a' and 'b'
class Job { 
    int a; // Represents the time or priority of the job
    int b; // Represents the value or weight of the job

    // Constructor to initialize Job attributes
    Job(int a, int b) { 
        this->a = a; 
        this->b = b; 
    } 
};

// Comparator class to compare two Jobs
class JobComparator { 
    public:
    // Override operator() method to define the ordering of Jobs
    bool operator()(Job job1, Job job2) { 
        // Compare based on 'a' first, and if equal, then by 'b'
        if (job1.a == job2.a) 
            return job1.b > job2.b; 
        else 
            return job1.a < job2.a; 
    } 
};

int main() { 
    // Create a priority queue to hold the jobs
    priority_queue<Job, vector<Job>, JobComparator> q; 
    
    // Read the first line of input and split it to get N and M
    string line;
    getline(cin, line);
    stringstream ss(line);
    int N, M;
    ss >> N >> M;
    
    // Read the job details and add them to the priority queue
    for (int i = 0; i < N; i++) { 
        getline(cin, line);
        stringstream ss(line);
        int a, b;
        ss >> a >> b;
        q.push(Job(a, b));
    } 
    
    int cnt = 0; // Counter to accumulate the total value of jobs processed
    priority_queue<int, vector<int>, greater<int>> jobQ; // Queue to hold job values in descending order
    
    // Process jobs for each time unit from 1 to M
    for (int i = 1; i <= M; i++) { 
        // While there are jobs that can be processed at time i
        while (!q.empty()) { 
            Job job = q.top(); // Peek at the job with the highest priority
            if (job.a <= i) { // If the job can be processed at time i
                jobQ.push(q.top().b); // Remove the job from the queue and add its value to jobQ
                q.pop();
            } else 
                break; // Break if the job cannot be processed yet
        } 
        // If there are jobs available to process, add the highest value job to the counter
        if (!jobQ.empty()) 
            cnt += jobQ.top(); // Poll the highest value job from jobQ and add to cnt
        jobQ.pop();
    } 
    
    // Output the total value of jobs processed
    cout << cnt << endl; 
}

