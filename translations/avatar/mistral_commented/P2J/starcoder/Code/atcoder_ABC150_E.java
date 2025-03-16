// Set the value of modulo for modular arithmetic calculations
static final int mod = 1000000007;

// Read an integer n from the standard input
int n = Integer.parseInt(br.readLine());

// Read n integers from the standard input and store them in a list c in descending order
List<Integer> c = new ArrayList<Integer>();
String[] c_temp = br.readLine().split(" ");
for (int i = 0; i < n; i++) {
    c.add(Integer.parseInt(c_temp[i]));
}
Collections.sort(c, Collections.reverseOrder());

// Calculate the value of b using the formula 2^(2*n-2) modulo mod
long b = Math.pow(2, 2 * n - 2, mod);

// Calculate the value of a as 2*b modulo mod
long a = 2 * b % mod;

// Initialize the variable ans to zero
long ans = 0;

// Iterate through each index i from 0 to n-1 in the list c
for (int i = 0; i < n; i++) {
    // Add the product of the current element c[i] and the sum of a and i*b to the variable ans
    ans += c.get(i) * (a + i * b);
    // Update the value of ans by taking the modulo of the current sum with mod
    ans %= mod;
}

// Print the value of ans as the output
System.out.println(ans);

