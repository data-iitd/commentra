
import java.util.Scanner;

public class s984784526{
    public static void main(String[] args) {
        // Declare an array 'a' of size 3 to hold integer inputs
        int[] a = new int[3];

        // Read three integers from standard input into the array 'a'
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize counters for occurrences of the numbers 5 and 7
        int five = 0;
        int seven = 0;

        // Iterate over the array to count occurrences of 5 and 7
        for (int i = 0; i < 3; i++) {
            // Increment the 'five' counter if the current element is 5
            if (a[i] == 5) {
                five++;
            }
            // Increment the'seven' counter if the current element is 7
            if (a[i] == 7) {
                seven++;
            }
        }

        // Check if there are exactly two occurrences of 5 and one occurrence of 7
        if (five == 2 && seven == 1) {
            // Print "YES" if the condition is met
            System.out.println("YES");
        } else {
            // Print "NO" if the condition is not met
            System.out.println("NO");
        }
    }
}
