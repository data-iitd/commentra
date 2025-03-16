import java.util.Scanner;

public class PrimeFinder {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        boolean[] prime = new boolean[100010];
        
        // Initialize the prime array
        for (int i = 0; i < prime.length; i++) {
            prime[i] = true;
        }
        prime[0] = false;
        prime[1] = false;

        // Mark even numbers as non-prime
        for (int i = 4; i < 100010; i += 2) {
            prime[i] = false;
        }

        // Sieve of Eratosthenes
        for (int i = 3; i * i <= 100008; i += 2) {
            if (prime[i]) {
                for (int j = i + i; j < 100008; j += i) {
                    prime[j] = false;
                }
            }
        }

        // Find the first prime number greater than or equal to X
        for (int i = X; i < 100008; i++) {
            if (prime[i]) {
                System.out.println(i);
                break;
            }
        }

        scanner.close();
    }
}
// <END-OF-CODE>
