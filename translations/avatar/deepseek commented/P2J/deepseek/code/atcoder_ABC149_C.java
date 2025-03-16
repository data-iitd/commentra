import java.util.Scanner;

public class PrimeFinder {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();  // Take an integer input from the user and store it in X
        boolean[] prime = new boolean[100010];  // Initialize a list 'prime' with 100010 elements, all set to true
        for (int i = 0; i < 100010; i++) {
            prime[i] = true;
        }
        prime[0] = false;  // 0 is not a prime number
        prime[1] = false;  // 1 is not a prime number

        // Mark all even numbers (except 2) as not prime
        for (int i = 4; i < 100010; i += 2) {
            prime[i] = false;
        }

        // Use a while loop to mark non-prime numbers using the Sieve of Eratosthenes algorithm
        int i = 3;
        while (i * i <= 100008) {
            if (prime[i]) {
                for (int j = i + i; j <= 100008; j += i) {
                    prime[j] = false;
                }
            }
            i += 2;
        }

        // Iterate through the range from X to 100008 and print the first prime number found
        for (int j = X; j <= 100008; j++) {
            if (prime[j]) {
                System.out.println(j);
                break;
            }
        }
    }
}
