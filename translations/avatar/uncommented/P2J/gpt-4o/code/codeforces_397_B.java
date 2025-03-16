import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CodeforcesTask397BSolution {
    private String result;
    private int t;
    private List<int[]> queries;

    public CodeforcesTask397BSolution() {
        this.result = "";
        this.t = 0;
        this.queries = new ArrayList<>();
    }

    public void readInput() {
        Scanner scanner = new Scanner(System.in);
        this.t = Integer.parseInt(scanner.nextLine());
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
        StringBuilder res = new StringBuilder();
        for (int[] query : queries) {
            int k = query[0] / query[1];
            res.append(k * query[2] >= query[0] ? "Yes" : "No").append("\n");
        }
        this.result = res.toString().trim();
    }

    public String getResult() {
        return this.result;
    }

    public static void main(String[] args) {
        CodeforcesTask397BSolution solution = new CodeforcesTask397BSolution();
        solution.readInput();
        solution.processTask();
        System.out.println(solution.getResult());
    }
}

// <END-OF-CODE>
