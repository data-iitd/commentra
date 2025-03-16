// Declare variables for the number of groups (n) and the maximum number (m)
int n, m;
// Declare variables for the number of elements in each group (k) and the individual element (a)
int k, a;
// Array to count occurrences of each number from 1 to m
int[] x = new int[31];

// Read the number of groups (n) and the maximum number (m)
Scanner sc = new Scanner(System.in);
n = sc.nextInt();
m = sc.nextInt();

// Loop through each group
for (int i = 0; i < n; ++i) {
  // Read the number of elements in the current group
  k = sc.nextInt();
  // Loop through each element in the current group
  for (int j = 0; j < k; ++j) {
    // Read the element and increment its count in the array
    a = sc.nextInt();
    x[a]++;
  }
}

// Initialize the answer variable to count how many numbers appear in all groups
int ans = 0;

// Check each number from 1 to m
for (int i = 1; i <= m; ++i) {
  // If the number appears in all n groups, increment the answer
  if (x[i] == n) {
    ans++;
  }
}

// Output the final count of numbers that appeared in all groups
System.out.println(ans);

// End of the program
