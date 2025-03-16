import java.util.Scanner;

class CodeforcesTask397BSolution {
    public static void main(String[] args) {
        // Create a Scanner object for reading input from stdin
        Scanner scanner = new Scanner(System.in);
        // Read the number of queries from input
        int t = scanner.nextInt();
        // Read each query and store it as a list of integers in the queries list
        int[][] queries = new int[t][3];
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < 3; j++) {
                queries[i][j] = scanner.nextInt();
            }
        }
        // Initialize a list to hold the results for each query
        String[] res = new String[t];
        // Process each query to determine if the condition is met
        for (int i = 0; i < t; i++) {
            // Calculate how many complete sets of queries[i][1] fit into queries[i][0]
            int k = queries[i][0] / queries[i][1];
            // Check if k multiplied by queries[i][2] is at least queries[i][0]
            res[i] = (k * queries[i][2] >= queries[i][0]) ? "Yes" : "No";
        }
        // Join the results into a single string separated by newlines
        String result = String.join("\n", res);
        // Print the final results
        System.out.println(result);
    }
}
