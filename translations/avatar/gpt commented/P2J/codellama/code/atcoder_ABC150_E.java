// Define the modulo constant
final int mod = 1000000007;

// Read the number of elements
int n = Integer.parseInt(scanner.nextLine());

// Read the list of integers and convert them to a list of integers
List<Integer> c = new ArrayList<>();
for (int i = 0; i < n; i++) {
    c.add(Integer.parseInt(scanner.nextLine()));
}

// Sort the list in descending order
Collections.sort(c, Collections.reverseOrder());

// Calculate the value of b as 2^(2*n - 2) modulo mod
int b = (int) Math.pow(2, 2 * n - 2) % mod;

// Calculate the value of a as 2 * b modulo mod
int a = 2 * b % mod;

// Initialize the answer variable
int ans = 0;

// Iterate through the sorted list and calculate the answer
for (int i = 0; i < n; i++) {
    // Update the answer by adding the product of the current element and (a + i * b)
    ans += c.get(i) * (a + i * b);
    // Ensure the answer remains within the modulo
    ans %= mod;
}

// Print the final result
System.out.println(ans);

