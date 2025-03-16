import java.util.Scanner;

public class Main {
    static int[] f1 = new int[100];
    static int[] f2 = new int[100];

    static void calc(int n) { // Process the number n
        int k = n % 10; // Get the last digit of n
        while (n >= 10) { // Divide n by 10 while it is greater than or equal to 10
            n /= 10;
        }
        f1[10 * k + n]++; // Increment the count at f1[10*k+n]
        f2[n * 10 + k]++; // Increment the count at f2[n*10+k]
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the input number
        while (N > 0) { // While N is not zero
            calc(N); // Call the calc function
            N--; // Decrement N by 1
        }

        int ans = 0; // Initialize the answer
        for (int i = 0; i < 100; i++) { // Loop through f1 and f2 arrays to calculate the answer
            ans += f1[i] * f2[i];
        }
        System.out.println(ans); // Output the answer
        scanner.close();
    }
}

// <END-OF-CODE>
