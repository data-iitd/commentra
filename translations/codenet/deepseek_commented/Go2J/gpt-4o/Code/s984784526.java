import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an array of 3 integers
        int[] a = new int[3];

        // Read three integers from standard input and store them in the array `a`
        Scanner scanner = new Scanner(System.in);
        a[0] = scanner.nextInt();
        a[1] = scanner.nextInt();
        a[2] = scanner.nextInt();

        // Initialize counters for the number of 5s and 7s
        int five = 0;
        int seven = 0;

        // Loop through the array to count the number of 5s and 7s
        for (int i = 0; i < 3; i++) {
            if (a[i] == 5) {
                five++;
            }
            if (a[i] == 7) {
                seven++;
            }
        }

        // Check if there are exactly 2 fives and 1 seven
        if (five == 2 && seven == 1) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

        scanner.close();
    }
}
// <END-OF-CODE>
