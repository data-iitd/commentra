import java.util.Collections; // Importing the utility class for reversing the order of a collection
import java.util.PriorityQueue; // Importing the priority queue implementation
import java.util.Queue; // Importing the queue interface
import java.util.Scanner; // Importing the scanner class for reading input

class Job implements Comparable<Job> { // Defining a class named Job that implements the Comparable interface
    int a; // Declaring an integer variable named a
    int b; // Declaring an integer variable named b

    Job(int a, int b) { // Constructor of the Job class
        this.a = a; // Initializing the variable a with the argument passed to the constructor
        this.b = b; // Initializing the variable b with the argument passed to the constructor
    }

    @Override // Annotation to indicate that the following method is an override of a method in the superclass
    public int compareTo(Job otherJob) { // Defining the compareTo method for implementing the Comparable interface
        if (otherJob.a == this.a) { // Comparing the a values of the current and other Job objects
            return this.b - otherJob.b; // If the a values are equal, comparing the b values
        } else {
            return this.a - otherJob.a; // If the a values are not equal, comparing the a values
        }
    }
}

public class Main { // Defining the main class
    public static void main(String[] args) { // Defining the main method
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object for reading input from the standard input

        String[] line; // Declaring an array of strings named line
        int N; // Declaring an integer variable named N
        int M; // Declaring an integer variable named M

        line = sc.nextLine().split("\\u2581"); // Reading the first line of input and splitting it into an array of strings using the delimiter "\u2581"
        N = Integer.parseInt(line[0]); // Parsing the first element of the array as an integer and assigning it to the variable N
        M = Integer.parseInt(line[1]); // Parsing the second element of the array as an integer and assigning it to the variable M

        Queue<Job> q = new PriorityQueue<>(); // Creating a new priority queue named q

        for (int i = 0; i < N; i++) { // Iterating through the number of jobs
            line = sc.nextLine().split("\\u2581"); // Reading the next line of input and splitting it into an array of strings using the delimiter "\u2581"
            q.add(new Job(Integer.parseInt(line[0]), Integer.parseInt(line[1]))); // Adding a new Job object to the priority queue
        }

        int cnt = 0; // Initializing the counter variable to 0
        Queue<Integer> jobQ = new PriorityQueue<>(Collections.reverseOrder()); // Creating a new priority queue named jobQ with the reverse order

        for (int i = 1; i <= M; i++) { // Iterating through the number of machines
            while (!q.isEmpty()) { // While the priority queue is not empty
                Job job = q.peek(); // Getting the Job object at the head of the priority queue
                if (job.a <= i) { // If the machine number is greater than or equal to the job a
                    jobQ.add(job.b); // Adding the benefit of the job to the jobQ
                    q.poll(); // Removing the Job object from the priority queue
                } else { // If the machine number is less than the job a
                    break; // Exiting the while loop
                }
            }

            if (!jobQ.isEmpty()) { // If the jobQ is not empty
                cnt += jobQ.poll(); // Adding the benefit of the job to the counter variable and removing it from the jobQ
            }
        }

        System.out.println(cnt); // Printing the value of the counter variable
    }
}
