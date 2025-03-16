import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        String s = scanner.nextLine();
        
        List<int[]> problems = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            String[] parts = scanner.nextLine().split(" ");
            problems.add(new int[]{Integer.parseInt(parts[0]), Integer.parseInt(parts[1])});
        }
        
        List<Integer> cumsum = new ArrayList<>();
        cumsum.add(0);
        for (int i = 1; i < n; i++) {
            cumsum.add(cumsum.get(i - 1) + (s.substring(i - 1, i + 1).equals("AC") ? 1 : 0));
        }
        
        for (int[] problem : problems) {
            int l = problem[0];
            int r = problem[1];
            System.out.println(cumsum.get(r - 1) - cumsum.get(l - 1));
        }
    }
}
