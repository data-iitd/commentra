
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    // Scanner sc = new Scanner(System.in);
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        // int a = sc.nextInt();
        // int b = sc.nextInt();
        // int c = sc.nextInt();
        // int k = sc.nextInt();
        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());

        // Generate all possible patterns of length k where each element is one of 0, 1, 2, or 3.
        List<List<Integer>> patterns = duplicatePatterns(new ArrayList<Integer>(), new ArrayList<Integer>(){{add(0); add(1); add(2); add(3);}}, k);

        // Iterate through each pattern to check the condition.
        for (List<Integer> P : patterns) {
            int r = a, g = b, b_ = c; // Initialize r, g, and b with a, b, and c respectively.
            for (int i = 0; i < P.size(); i++) {
                if (P.get(i) == 0) {
                    continue; // If the operation is 0, do nothing.
                } else if (P.get(i) == 1) {
                    r *= 2; // Double the value of r.
                } else if (P.get(i) == 2) {
                    g *= 2; // Double the value of g.
                } else if (P.get(i) == 3) {
                    b_ *= 2; // Double the value of b.
                }
            }

            // Check if the condition b > a and c > b is met.
            if (g > r && b_ > g) {
                System.out.println("Yes"); // Print "Yes" if the condition is met.
                return;
            }
        }
        System.out.println("No"); // Print "No" if no pattern meets the condition.
    }

    // DuplicatePatterns generates all patterns of n^k of elems(List<Integer>).
    public static List<List<Integer>> duplicatePatterns(List<Integer> pattern, List<Integer> elems, int k) {
        if (pattern.size() == k) {
            return new ArrayList<List<Integer>>(){{add(pattern);}}; // Return the pattern if its length equals k.
        }

        List<List<Integer>> res = new ArrayList<List<Integer>>();
        for (int e : elems) {
            List<Integer> newPattern = new ArrayList<Integer>(pattern);
            newPattern.add(e); // Add the current element to the pattern.

            res.addAll(duplicatePatterns(newPattern, elems, k)); // Recursively generate patterns.
        }

        return res;
    }

    // 