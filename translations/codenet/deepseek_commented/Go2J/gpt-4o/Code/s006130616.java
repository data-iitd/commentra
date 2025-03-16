import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // 1. Reading the number of courses
        int m = scanner.nextInt(); // 1. Reading the number of skills
        int x = scanner.nextInt(); // 1. Reading the minimum required skill level
        
        int[][] a = new int[n][m]; // 2. Dynamically allocating memory for the 2D array representing the cost of each course for each skill
        int[] p = new int[n]; // 3. Allocating memory for the array representing the cost of each course
        
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt(); // 4. Reading the cost of each course
            for (int j = 0; j < m; j++) {
                a[i][j] = scanner.nextInt(); // 6. Reading the skill levels for each course
            }
        }

        int ans = 1200001; // 7. Initializing the answer with a large number
        int tot; // 8. A variable to keep track of the total cost of the current combination of courses
        boolean ok; // 9. A flag to check if the current combination meets the skill requirement
        
        for (int bits = 0; bits < (1 << n); bits++) { // 10. Iterating through all possible combinations of courses
            tot = 0;
            ok = true;
            int[] skill = new int[m]; // 11. Initializing an array to keep track of the total skill level for the current combination
            
            for (int i = 0; i < n; i++) {
                if ((bits >> i) & 1 == 1) { // 12. Checking if the i-th course is included in the current combination
                    tot += p[i];
                    for (int j = 0; j < m; j++) {
                        skill[j] += a[i][j]; // 13. Updating the total skill level for each skill
                    }
                }
            }

            for (int v : skill) { // 14. Checking if all skill levels are at least x
                if (v < x) {
                    ok = false;
                    break;
                }
            }

            if (ok) { // 15. If the current combination meets the skill requirement
                if (ans > tot) {
                    ans = tot; // Updating the answer if the cost is lower
                }
            }
        }

        if (ans != 1200001) { // 16. Printing the result
            System.out.println(ans);
        } else {
            System.out.println("-1");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
