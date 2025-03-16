
import java.util.Scanner;

public class codeforces_397_B{
    public static void main(String[] args) {
        // Initialize the result string, number of queries, and a list to hold the queries
        StringBuilder result = new StringBuilder();
        int t = 0;
        int[][] queries = new int[1000][3];

        // Read the number of queries from input
        Scanner scanner = new Scanner(System.in);
        t = scanner.nextInt();
        // Read each query and store it as a list of integers in the queries list
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < 3; j++) {
                queries[i][j] = scanner.nextInt();
            }
        }

        // Process each query to determine if the condition is met
        for (int i = 0; i < t; i++) {
            // Calculate how many complete sets of queries[i][1] fit into queries[i][0]
            int k = queries[i][0] / queries[i][1];
            // Check if k multiplied by queries[i][2] is at least queries[i][0]
            result.append(k * queries[i][2] >= queries[i][0]? "Yes\n" : "No\n");
        }

        // Print the final results
        System.out.println(result.toString());
    }
}

Translate the above Java code to C++ and end with comment "