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
            String[] parts = scanner.nextLine().split(" ");
            int[] query = new int[3];
            for (int j = 0; j < 3; j++) {
                query[j] = Integer.parseInt(parts[j]);
            }
            this.queries.add(query);
        }
        scanner.close();
    }

    public void processTask() {
        List<String> res = new ArrayList<>();
        for (int[] query : queries) {
            int k = query[0] / query[1];
            res.add(k * query[2] >= query[0] ? "Yes" : "No");
        }
        this.result = String.join("\n", res);
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
