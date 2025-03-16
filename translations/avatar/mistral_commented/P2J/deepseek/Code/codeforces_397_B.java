public class CodeforcesTask397BSolution {

    private String result;                   // Initialize a string to store the result
    private int t;                          // Initialize the number of queries
    private int[][] queries;                // Initialize an array to store the queries

    public void readInput() {
        t = Integer.parseInt(System.in.readLine()); // Read the number of queries from the input
        queries = new int[t][3];              // Initialize the queries array
        for (int i = 0; i < t; i++) {
            String[] parts = System.in.readLine().split(" "); // Read each query and split it into parts
            queries[i][0] = Integer.parseInt(parts[0]); // Parse the first part as the first element of the query
            queries[i][1] = Integer.parseInt(parts[1]); // Parse the second part as the second element of the query
            queries[i][2] = Integer.parseInt(parts[2]); // Parse the third part as the third element of the query
        }
    }

    public void processTask() {
        StringBuilder res = new StringBuilder(); // Initialize a StringBuilder to store the results
        for (int[] query : queries) {
            int k = query[0] / query[1]; // Calculate the value of k for the current query
            if (k * query[2] >= query[0]) {
                res.append("Yes"); // Append "Yes" to the result if the condition is met
            } else {
                res.append("No"); // Append "No" to the result if the condition is not met
            }
            res.append("\n"); // Append a newline character to separate results
        }
        result = res.toString(); // Convert the StringBuilder to a string and store it in the result
    }

    public String getResult() {
        return result; // Return the result string
    }

    public static void main(String[] args) throws IOException {
        CodeforcesTask397BSolution solution = new CodeforcesTask397BSolution(); // Create an instance of the CodeforcesTask397BSolution class
        solution.readInput(); // Read the input
        solution.processTask(); // Process the task
        System.out.println(solution.getResult()); // Print the result
    }
}
