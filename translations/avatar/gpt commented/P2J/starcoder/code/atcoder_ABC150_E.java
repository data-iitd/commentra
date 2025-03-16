// Define the modulo constant
static final int MOD = 1000000007;

// Read the number of elements
int n = Integer.parseInt(br.readLine());

// Read the list of integers and convert them to a list of integers
List<Integer> c = new ArrayList<Integer>();
String[] s = br.readLine().split(" ");
for (int i = 0; i < n; i++) {
    c.add(Integer.parseInt(s[i]));
}

// Sort the list in descending order
Collections.sort(c, Collections.reverseOrder());

// Calculate the value of b as 2^(2*n - 2) modulo mod
long b = pow(2, 2 * n - 2, MOD);

// Calculate the value of a as 2 * b modulo mod
long a = 2 * b % MOD;

// Initialize the answer variable
long ans = 0;

// Iterate through the sorted list and calculate the answer
for (int i = 0; i < n; i++) {
    // Update the answer by adding the product of the current element and (a + i * b)
    ans += c.get(i) * (a + i * b);
    // Ensure the answer remains within the modulo
    ans %= MOD;
}

// Print the final result
System.out.println(ans);

