import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Step 3: Input a string
        Scanner scanner = new Scanner(System.in);
        String N = scanner.next();

        // Step 4: Calculate the sum of digits
        int S = 0;
        for (int i = 0; i < N.length(); i++) {
            S += N.charAt(i) - '0';
        }

        // Step 5: Check if the number is divisible by the sum of its digits
        if (Integer.parseInt(N) % S == 0) 
            System.out.println("Yes");
        else 
            System.out.println("No");

        // Step 6: Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
