public class Main {
    public static void main(String[] args) {
        int X = Integer.parseInt(System.console().readLine());
        boolean[] prime = new boolean[100010];

        // Initialize the array 'prime' with all elements as True
        for (int i = 0; i < 100010; i++) {
            prime[i] = true;
        }

        // Set the first two elements of the array as False, as 0 and 1 are not prime numbers
        prime[0] = false;
        prime[1] = false;

        // Sieve of Eratosthenes algorithm to find prime numbers up to 100008
        for (int i = 4; i <= 100008; i += 2) {
            // If the number 'i' is prime
            if (prime[i]) {
                // Mark all multiples of 'i' as composite (non-prime)
                for (int j = i + i; j <= 100008; j += i) {
                    prime[j] = false;
                }
            }
        }

        // Find the prime number 'X' and print it
        for (int i = X; i <= 100008; i++) {
            // If the number 'i' is prime
            if (prime[i]) {
                System.out.println(i);
                // Exit the loop as we have found the prime number 'X'
                break;
            }
        }
    }
}
