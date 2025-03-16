import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CodeforcesTask397BSolution {
    private String result;
    private int t;
    private List<int[]> queries;

    public CodeforcesTask397BSolution() {
        // Initialize the result string, number of queries, and a list to hold the queries
        this.result = "";
        this.t = 0;
        this.queries = new ArrayList<>();
    }

    public void readInput() {
        // Read the number of queries from input
        Scanner scanner = new Scanner(System.in);
        this.t = Integer.parseInt(scanner.nextLine());
        // Read each query and store it as an array of integers in the queries list
        for (int i = 0; i < t; i++) {
            String[] input = scanner.nextLine().split(" ");
            int[] query = new int[3];
            for (int j = 0; j < 3; j++) {
                query[j] = Integer.parseInt(input[j]);
            }
            queries.add(query);
        }
        scanner.close();
    }

    public void processTask() {
        // Initialize a StringBuilder to hold the results for each query
        StringBuilder res = new StringBuilder();
        // Process each query to determine if the condition is met
        for (int[] query : queries) {
            // Calculate how many complete sets of query[1] fit into query[0]
            int k = query[0] / query[1];
            // Check if k multiplied by query[2] is at least query[0]
            res.append(k * query[2] >= query[0] ? "Yes" : "No").append("\n");
        }
        // Convert StringBuilder to String
        this.result = res.toString().trim(); // Remove the last newline
    }

    public String getResult() {
        // Return the final result string
        return this.result;
    }

    public static void main(String[] args) {
        // Create an instance of the solution class
        CodeforcesTask397BSolution solution = new CodeforcesTask397BSolution();
        // Read input data
        solution.readInput();
        // Process the task based on the input data
        solution.processTask();
        // Print the final results
        System.out.println(solution.getResult());
    }
}

// <END-OF-CODE>
