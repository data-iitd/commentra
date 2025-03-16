
// Set the modulus value
int mod = 1000000007;

// Read input values for n and k
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int k = sc.nextInt();

// Initialize a list 'coef' to store coefficients
List<Integer> coef = new ArrayList<>();

// Calculate coefficients for n up to its square root
for (int i = 1; i <= Math.sqrt(n); i++) {
    // Calculate the difference between the quotient and the next quotient
    coef.add(n / i - n / (i + 1));
}

// Add remaining coefficients to the list
coef.addAll(Collections.nCopies(n - coef.size(), 1));

// Reverse the list 'coef'
Collections.reverse(coef);

// Initialize a 2D list 'dp' to store intermediate results
int nn = coef.size();
int[][] dp = new int[k + 1][nn];

// Initialize the first row of dp with 1 at index 0
Arrays.fill(dp[0], 1);

// Calculate dp[i][j] for i from 1 to k and j from nn-1 to 0
for (int i = 1; i <= k; i++) {
    int tmp = 0;
    // Iterate through the reverse list 'coef' from j = nn-1 to j = 0
    for (int j = nn - 1; j >= 0; j--) {
        // Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
        tmp += dp[i - 1][j];
        tmp = (tmp + coef.get(j)) % mod;
        // Update dp[i][j] with the product of coef[j] and tmp
        dp[i][j] = coef.get(j) * tmp;
        dp[i][j] %= mod;
    }
}

// Calculate the final answer by summing up dp[k]
System.out.println(Arrays.stream(dp[k]).sum() % mod);

