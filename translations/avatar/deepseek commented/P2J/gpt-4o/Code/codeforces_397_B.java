import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class CodeforcesTask397BSolution {
    private String result;
    private int t;
    private List<int[]> queries;

    // Constructor
    public CodeforcesTask397BSolution() {
        this.result = "";
        this.t = 0;
        this.queries = new ArrayList<>();
    }

    // Reads the number of test cases and the queries from input
    public void readInput() {
        Scanner scanner = new Scanner(System.in);
        this.t = Integer.parseInt(scanner.nextLine()); // Read the number of test cases
        for (int i = 0; i < this.t; i++) {
            String[] input = scanner.nextLine().split(" ");
            int[] query = new int[3];
            for (int j = 0; j < 3; j++) {
                query[j] = Integer.parseInt(input[j]); // Read each query and store it in the list
            }
            this.queries.add(query);
        }
        scanner.close();
    }

    // Processes each query to determine if the condition is met
    public void processTask() {
        StringBuilder res = new StringBuilder();
        for (int[] query : this.queries) {
            int k = query[0] / query[1]; // Calculate k as the integer division of query[0] by query[1]
            res.append(k * query[2] >= query[0] ? "Yes" : "No").append("\n"); // Append "Yes" or "No" based on the condition
        }
        this.result = res.toString().trim(); // Join the results into a single string with newline characters
    }

    // Returns the final result
    public String getResult() {
        return this.result;
    }

    public static void main(String[] args) {
        CodeforcesTask397BSolution solution = new CodeforcesTask397BSolution();
        solution.readInput();
        solution.processTask();
        System.out.println(solution.getResult()); // Print the final result
    }
}

// <END-OF-CODE>
