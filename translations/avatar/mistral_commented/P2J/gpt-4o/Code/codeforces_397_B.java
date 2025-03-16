import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CodeforcesTask397BSolution {

    private String result;                // Initialize an empty string to store the result
    private int t;                        // Initialize the number of queries to 0
    private List<int[]> queries;         // Initialize a list to store the queries

    // Constructor method with initializations
    public CodeforcesTask397BSolution() {
        this.result = "";                 // Initialize an empty string to store the result
        this.t = 0;                       // Initialize the number of queries to 0
        this.queries = new ArrayList<>(); // Initialize an empty list to store the queries
    }

    // Method to read input
    public void readInput() {
        Scanner scanner = new Scanner(System.in);
        this.t = Integer.parseInt(scanner.nextLine()); // Read the number of queries from the input
        for (int i = 0; i < t; i++) {
            String[] input = scanner.nextLine().split(" ");
            int[] query = new int[3];
            for (int j = 0; j < 3; j++) {
                query[j] = Integer.parseInt(input[j]); // Read the queries and store them in an array
            }
            queries.add(query); // Add the query array to the list of queries
        }
        scanner.close();
    }

    // Method to process the task
    public void processTask() {
        List<String> res = new ArrayList<>(); // Initialize an empty list to store the results of each query
        for (int[] query : queries) { // Iterate through each query in the queries list
            int k = query[0] / query[1]; // Calculate the value of k for the current query
            res.add(k * query[2] >= query[0] ? "Yes" : "No"); // Append the result (Yes or No) for the current query to the results list
        }
        this.result = String.join("\n", res); // Join the results list with newline character and store it in the result string
    }

    // Method to get the result
    public String getResult() {
        return this.result; // Return the result string
    }

    // Main method to run the code
    public static void main(String[] args) {
        CodeforcesTask397BSolution solution = new CodeforcesTask397BSolution(); // Create an instance of the CodeforcesTask397BSolution class
        solution.readInput(); // Read the input
        solution.processTask(); // Process the task
        System.out.println(solution.getResult()); // Print the result
    }
}

// <END-OF-CODE>
