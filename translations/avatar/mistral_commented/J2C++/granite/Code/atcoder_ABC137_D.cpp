
#include <iostream> // Including the standard input/output stream objects
#include <queue> // Including the queue container
#include <algorithm> // Including the algorithm library
#include <vector> // Including the vector container
#include <string> // Including the string container
#include <sstream> // Including the string stream classes

using namespace std; // Using the standard namespace

struct Job { // Defining a struct named Job
    int a; // Declaring an integer variable named a
    int b; // Declaring an integer variable named b
};

bool compareJobs(Job j1, Job j2) { // Defining a function named compareJobs that compares two Job objects
    if (j1.a == j2.a) { // If the a values of the two Job objects are equal
        return j1.b > j2.b; // Comparing the b values in descending order
    } else {
        return j1.a < j2.a; // Comparing the a values in ascending order
    }
}

int main() { // Defining the main function
    string line; // Declaring a string variable named line
    int N; // Declaring an integer variable named N
    int M; // Declaring an integer variable named M

    getline(cin, line); // Reading the first line of input and storing it in the variable line
    stringstream ss(line); // Creating a new string stream object named ss and initializing it with the contents of the variable line
    ss >> N >> M; // Parsing the contents of the variable line as integers and assigning them to the variables N and M

    priority_queue<Job, vector<Job>, function<bool(Job, Job)>> q(compareJobs); // Creating a new priority queue named q with the custom comparison function compareJobs

    for (int i = 0; i < N; i++) { // Iterating through the number of jobs
        getline(cin, line); // Reading the next line of input and storing it in the variable line
        stringstream ss(line); // Creating a new string stream object named ss and initializing it with the contents of the variable line
        int a, b; // Declaring integer variables named a and b
        ss >> a >> b; // Parsing the contents of the variable line as integers and assigning them to the variables a and b
        q.push({a, b}); // Adding a new Job object to the priority queue
    }

    int cnt = 0; // Initializing the counter variable to 0
    priority_queue<int, vector<int>, greater<int>> jobQ; // Creating a new priority queue named jobQ with the reverse order

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
            jobQ.pop(); // Removing the top element from the jobQ
        }
    }

    cout << cnt << endl; // Printing the value of the counter variable

    return 0; // Returning 0 to indicate successful execution
}

