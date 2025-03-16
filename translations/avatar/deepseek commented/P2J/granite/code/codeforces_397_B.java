

import java.util.Scanner;

public class codeforces_397_B{
    private String result;
    private int t;
    private int[][] queries;

    public CodeforcesTask397BSolution() {
        this.result = "";
        this.t = 0;
        this.queries = new int[1000][3];
    }

    public void readInput() {
        Scanner scanner = new Scanner(System.in);
        this.t = scanner.nextInt();  // Read the number of test cases
        for (int i = 0; i < this.t; i++) {
            for (int j = 0; j < 3; j++) {
                this.queries[i][j] = scanner.nextInt();  // Read each query and store it in the 2D array
            }
        }
    }

    public void processTask() {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < this.t; i++) {
            int k = this.queries[i][0] / this.queries[i][1];  // Calculate k as the integer division of query[0] by query[1]
            res.append(k * this.queries[i][2] >= this.queries[i][0]? "Yes\n" : "No\n");  // Append "Yes" or "No" based on the condition
        }
        this.result = res.toString();  // Set the final result as the string representation of the StringBuilder
    }

    public String getResult() {
        return this.result;
    }

    public static void main(String[] args) {
        CodeforcesTask397BSolution solution = new CodeforcesTask397BSolution();
        solution.readInput();
        solution.processTask();
        System.out.println(solution.getResult());  // Print the final result
    }
}

Translate the above Java code to C++ and end with comment "