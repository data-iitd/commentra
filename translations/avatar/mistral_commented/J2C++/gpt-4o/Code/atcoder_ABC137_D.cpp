#include <iostream> // Including the iostream library for input and output
#include <queue> // Including the queue library for priority queue
#include <vector> // Including the vector library for dynamic arrays
#include <sstream> // Including the sstream library for string stream
#include <string> // Including the string library for string manipulation
#include <algorithm> // Including the algorithm library for sorting and other algorithms

using namespace std; // Using the standard namespace

class Job { // Defining a class named Job
public:
    int a; // Declaring an integer variable named a
    int b; // Declaring an integer variable named b

    Job(int a, int b) : a(a), b(b) {} // Constructor of the Job class
};

// Comparator for the priority queue to sort by 'a' and then by 'b'
struct JobComparator {
    bool operator()(const Job& j1, const Job& j2) {
        if (j1.a == j2.a) {
            return j1.b > j2.b; // If a values are equal, sort by b in ascending order
        }
        return j1.a > j2.a; // Sort by a in ascending order
    }
};

int main() { // Defining the main function
    string input; // Declaring a string variable for input
    getline(cin, input); // Reading the first line of input

    stringstream ss(input); // Creating a string stream from the input
    int N, M; // Declaring integer variables N and M
    char delimiter; // Declaring a character for the delimiter

    ss >> N >> delimiter >> M; // Parsing N and M from the input

    priority_queue<Job, vector<Job>, JobComparator> q; // Creating a priority queue for jobs

    for (int i = 0; i < N; i++) { // Iterating through the number of jobs
        getline(cin, input); // Reading the next line of input
        stringstream jobStream(input); // Creating a string stream for the job input
        int a, b; // Declaring integers for job a and b
        jobStream >> a >> delimiter >> b; // Parsing a and b from the input
        q.push(Job(a, b)); // Adding a new Job object to the priority queue
    }

    int cnt = 0; // Initializing the counter variable to 0
    priority_queue<int> jobQ; // Creating a new priority queue for job benefits

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
            cnt += jobQ.top(); // Adding the benefit of the job to the counter variable
            jobQ.pop(); // Removing it from the jobQ
        }
    }

    cout << cnt << endl; // Printing the value of the counter variable
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
