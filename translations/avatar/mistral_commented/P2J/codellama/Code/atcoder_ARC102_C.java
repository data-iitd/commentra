// Define K and N as integers read from the standard input
int K = Integer.parseInt(scanner.nextLine());
int N = Integer.parseInt(scanner.nextLine());

// Define a helper function to print arguments with a space between them
void dprint(Object... x) {
    System.out.print(Arrays.toString(x));
}

// Define a function to compute the number of combinations of r items chosen from a set of n items, modulo a given modulus
int cmb(int n, int r, int mod) {
    // Check if r is out of range
    if (r < 0 || r > n) {
        return 0;
    }
    // Adjust r to be between 0 and n
    r = Math.min(r, n - r);
    // Compute the combination using the formula
    return g1[n] * g2[r] * g2[n - r] % mod;
}

// Set the modulus to 998244353
int mod = 998244353;

// Define a constant N for the size of the arrays
int __N = 8000;

// Initialize g1 and g2 with the first two elements
int[] g1 = {1, 1};
int[] g2 = {1, 1};

// Initialize inverse with the first two elements and the identity list
int[] inverse = {0, 1};
for (int i = 2; i <= __N; i++) {
    // Compute g1[i] using the previous value and the current i
    g1[i] = (g1[i - 1] * i) % mod;
    // Compute inverse[i] using the formula
    inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;
    // Compute g2[i] using the previous values of g1 and inverse
    g2[i] = (g2[i - 1] * inverse[i]) % mod;
}

// Define a function to compute the value of a combinatorial sum
int kumiawase(int p, int q) {
    // Compute the combination using the cmb function
    return cmb(p + q - 1, q - 1, mod);
}

// Define a function to compute the answer for a given value of n
int solve(int n) {
    // Check if n is out of range
    assert n <= K + 1;
    // Initialize the answer as 0
    int ans = 0;
    // Compute the number of pairs (p, q) such that p <= N and q <= K - p
    int kumi = (n - 1) / 2;
    // Compute the answer using the kumiawase function and the precomputed values
    for (int p = 0; p <= kumi; p++) {
        if (p > N) {
            break;
        }
        ans += (int) (Math.pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0 ? 1 : 0))) % mod);
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += (int) (Math.pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0 ? 1 : 0))) % mod);
        }
    }
    // Return the answer
    return ans;
}

// Initialize an empty list to store the answers
List<Integer> ans = new ArrayList<>();

// Compute the answers for all integers from 2 to 2K+1
for (int i = 2; i <= 2 * K + 1; i++) {
    // Compute the answer for the current integer using the solve function
    int tmp = solve(i) % mod;
    // Store the answer in the ans list
    ans.add(tmp);
    // Print the answer
    System.out.println(tmp);
}

// Print the answers for the negative integers by reprinting the results from the ans list
for (int i = 2; i <= 2 * K + 1; i++) {
    if (i <= K + 1) {
        System.out.println(ans.get(i - K));
    } else {
        System.out.println(ans.get(-i + K));
    }
}

