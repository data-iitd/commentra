import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long h = scanner.nextLong(); // Initialize variable h to store input integer
        long ans = 0, cnt = 1; // Initialize variables

        // Loop until h becomes 1
        while (h != 1) {
            // If h is odd, decrement it by 1
            if (h % 2 != 0) h--;

            // Divide h by 2 and multiply cnt by 2
            h /= 2;
            cnt *= 2;

            // Add the new value of cnt to the answer
            ans += cnt;
        }

        // Output the final answer plus 1
        System.out.println(ans + 1);
        
        scanner.close();
    }
}

// <END-OF-CODE>
