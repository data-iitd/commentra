import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // 1. Read an integer `n` from the standard input
        
        int[] as = new int[n + 1]; // 2. Initialize array `as` with length `n + 1`
        int[] bs = new int[n];     // 3. Initialize array `bs` with length `n`
        
        for (int i = 0; i <= n; i++) { // 4. Read values into `as` from the standard input
            as[i] = scanner.nextInt();
        }
        
        for (int i = 0; i < n; i++) { // 5. Read values into `bs` from the standard input
            bs[i] = scanner.nextInt();
        }
        
        int sum = 0; // 6. Initialize a variable `sum` to store the result
        for (int i = 0; i < n; i++) { // 7. Iterate through the elements of `as` and `bs`
            int a = as[i];
            int b = bs[i];
            if (a <= b) { // 8. Check if `a` is less than or equal to `b`
                sum += a; // 9. Add `a` to `sum`
                b -= a;   // 10. Subtract `a` from `b`
                if (i + 1 < n) { // 11. Check if the next index is within bounds
                    int an = as[i + 1];
                    if (an <= b) { // 12. Check if the next element in `as` is less than or equal to the remaining `b`
                        sum += an; // 13. Add the next element in `as` to `sum`
                        as[i + 1] = 0; // 14. Set the next element in `as` to 0
                    } else {
                        sum += b; // 15. Add the remaining `b` to `sum`
                        as[i + 1] -= b; // 16. Subtract the remaining `b` from the next element in `as`
                    }
                }
            } else { // 17. If `a` is greater than `b`
                sum += b; // 18. Add `b` to `sum`
            }
        }
        System.out.println(sum); // 19. Print the value of `sum`
        
        scanner.close();
    }
}
// <END-OF-CODE>
