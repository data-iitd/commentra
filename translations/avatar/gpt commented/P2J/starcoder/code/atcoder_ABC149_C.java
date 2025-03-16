// Read an integer input from the user
Scanner sc = new Scanner(System.in);
int X = sc.nextInt();

// Initialize a list to track prime numbers up to 100010
// Start by assuming all numbers are prime (true)
boolean[] prime = new boolean[100010];
Arrays.fill(prime, true);

// Set 0 and 1 as non-prime (false)
prime[0] = false;
prime[1] = false;

// Eliminate all even numbers greater than 2 from the list of primes
for (int i = 4; i < 100010; i += 2) {
    prime[i] = false;
}

// Start checking for prime numbers from 3 onwards
int i = 3;
// Use the Sieve of Eratosthenes method to find all primes up to 100008
while (i * i <= 100008) {
    // If 'i' is still marked as prime
    if (prime[i]) {
        // Mark all multiples of 'i' as non-prime
        for (int j = i + i; j < 100008; j += i) {
            prime[j] = false;
        }
    }
    // Move to the next odd number
    i += 2;
}

// Find and print the first prime number greater than or equal to X
for (int i = X; i < 100008; i++) {
    if (prime[i]) {
        System.out.println(i);  // Print the prime number found
        break;  // Exit the loop after finding the first prime
}

