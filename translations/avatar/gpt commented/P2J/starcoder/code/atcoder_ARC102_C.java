// Read input values K and N from user
Scanner sc = new Scanner(System.in);
int K = sc.nextInt();
int N = sc.nextInt();

// Define a debug print function (currently does nothing)
// dprint = lambda *x: x

// Function to compute combinations modulo'mod'
long cmb(int n, int r, int mod) {
    // Return 0 if r is out of bounds
    if (r < 0 || r > n)
        return 0;
    // Use symmetry property of combinations
    r = Math.min(r, n - r);
    // Calculate combination using precomputed factorials and inverses
    return g1[n] * g2[r] * g2[n - r] % mod;
}

// Set modulo value and maximum value for precomputation
int mod = 998244353;
int __N = 8000;

// Precompute factorials and inverse factorials
long[] g1 = new long[__N + 1];
long[] g2 = new long[__N + 1];
long[] inverse = new long[__N + 1];

// Fill g1, g2, and inverse arrays
g1[0] = 1;
g2[0] = 1;
inverse[1] = 1;
for (int i = 2; i <= __N; i++) {
    g1[i] = (g1[i - 1] * i) % mod;  // Compute factorial
    inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;  // Compute modular inverse using Fermat's Little Theorem
    g2[i] = (g2[i - 1] * inverse[i]) % mod;  // Compute inverse factorial
}

// Function to compute kumiawase (combinations with repetition)
long kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1, mod);
}

// Function to solve the main problem for a given n
long solve(int n) {
    assert n <= K + 1;  // Ensure n is within valid range
    long ans = 0;  // Initialize answer
    int kumi = (n - 1) / 2;  // Calculate half of n-1

    // Iterate over possible values of p
    for (int p = 0; p <= kumi; p++) {
        if (p > N)  // Break if p exceeds N
            break;
        // Update answer with contributions from current p
        ans += (long) Math.pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)));

        // If n is even, consider the case where p is used one less
        if (n % 2 == 0 && N - p - 1 >= 0)
            ans += (long) Math.pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)));
    }

    return ans;  // Return the computed answer
}

// List to store answers for each i
List<Long> ans = new ArrayList<>();

// Iterate over the range to compute results for each i
for (int i = 2; i <= 2 * K + 1; i++) {
    if (i <= K + 1) {
        // Solve for i and store the result
        long tmp = solve(i) % 998244353;
        ans.add(tmp);  // Append result to answers list
        System.out.println(tmp);  // Print the result
    } else {
        // For i greater than K+1, use previously computed results
        System.out.println(ans.get(i - K - 1));  // Print the corresponding result from the answers list
}

