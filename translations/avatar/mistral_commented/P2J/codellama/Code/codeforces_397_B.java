
import java.util.Scanner;

class CodeforcesTask397BSolution {

    private String result;
    private int t;
    private int[][] queries;

    public static void main(String[] args) {
        CodeforcesTask397BSolution solution = new CodeforcesTask397BSolution();
        solution.readInput();
        solution.processTask();
        System.out.println(solution.getResult());
    }

    private void readInput() {
        Scanner scanner = new Scanner(System.in);
        t = scanner.nextInt();
        queries = new int[t][3];
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < 3; j++) {
                queries[i][j] = scanner.nextInt();
            }
        }
    }

    private void processTask() {
        String[] res = new String[t];
        for (int i = 0; i < t; i++) {
            int k = queries[i][0] / queries[i][1];
            res[i] = k * queries[i][2] >= queries[i][0] ? "Yes" : "No";
        }
        result = String.join("\n", res);
    }

    private String getResult() {
        return result;
    }
}

