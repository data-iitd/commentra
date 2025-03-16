import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // 1. Reading the number of courses.
        int m = scanner.nextInt(); // 2. Reading the number of skills.
        int x = scanner.nextInt(); // 3. Reading the minimum required skill level.

        int[][] a = new int[n][m]; // 4. Initializing the 2D array for the cost of each course for each skill.
        int[] p = new int[n]; // 5. Initializing the array for the cost of each course.

        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt(); // 6. Reading the cost of each course.
            for (int j = 0; j < m; j++) {
                a[i][j] = scanner.nextInt(); // 7. Reading the skill levels for each course.
            }
        }

        int ans = Integer.MAX_VALUE; // 8. Initializing the answer with a large number.
        for (int bits = 0; bits < 1 << n; bits++) { // 9. Iterating through all possible combinations of courses.
            int tot = 0;
            boolean ok = true;
            int[] skill = new int[m]; // 10. Initializing an array to keep track of the total skill level.

            for (int i = 0; i < n; i++) {
                if ((bits & (1 << i)) != 0) { // 11. Checking if the i-th course is included in the current combination.
                    tot += p[i];
                    for (int j = 0; j < m; j++) {
                        skill[j] += a[i][j]; // 12. Updating the total skill level.
                    }
                }
            }

            for (int v : skill) { // 13. Checking if all skill levels are at least x.
                if (v < x) {
                    ok = false;
                    break;
                }
            }

            if (ok) { // 14. If the current combination meets the skill requirement, updating the answer.
                ans = Math.min(ans, tot);
            }
        }

        if (ans != Integer.MAX_VALUE) { // 15. Printing the result.
            System.out.println(ans);
        } else {
            System.out.println("-1");
        }
    }
}
