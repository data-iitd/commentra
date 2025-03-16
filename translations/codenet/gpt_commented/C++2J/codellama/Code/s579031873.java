
// Read the number of items (N) and the total amount (X)
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();
int X = sc.nextInt();

// Initialize the answer and minimum value variables
int ans = 0; // Counter for the number of items processed
int min = 1000000000; // Initialize min to a large value

// Process each item
for (int i = 0; i < N; i++) {
  int tmp; // Temporary variable to hold the current item's value
  tmp = sc.nextInt(); // Read the current item's value
  X -= tmp; // Subtract the item's value from total amount X
  ans++; // Increment the count of items processed
  if (tmp < min) min = tmp; // Update min if the current item is smaller
}

// Calculate how many more items can be added using the remaining amount
ans += X / min; // Add the number of additional items that can be bought

// Output the final answer
System.out.println(ans);

