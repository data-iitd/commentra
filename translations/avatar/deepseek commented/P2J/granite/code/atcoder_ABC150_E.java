

long mod = 100000007L;
// Define the modulo value as \(10^9 + 7\)

int n = scanner.nextInt();
// Read the integer input `n`

long[] c = new long[n];
// Create an array `c` to store the input integers

for (int i = 0; i < n; i++) {
    c[i] = scanner.nextLong();
    // Read the integers `c` and store them in the array
}

Arrays.sort(c);
// Sort the array `c` in descending order

long b = pow(2, 2 * n - 2, mod);
// Calculate `b` using the power function with base 2, exponent \(2 * n - 2\), and modulo `mod`

long a = 2 * b % mod;
// Calculate `a` as twice `b` modulo `mod`

long ans = 0;
// Initialize `ans` to 0

for (int i = 0; i < n; i++) {
    // Loop through each element in the range `n`
    ans += c[i] * (a + i * b) % mod;
    // Update `ans` with the sum of the product of `c[i]` and `(a + i * b)`
    ans %= mod;
    // Take modulo `mod` at each step to prevent overflow
}

System.out.println(ans);
// Print the final result `ans`

