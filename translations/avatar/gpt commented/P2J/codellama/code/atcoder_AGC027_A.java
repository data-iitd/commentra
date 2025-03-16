// Define a lambda function to read a list of integers from input
Function<List<Integer>> na = () -> Arrays.stream(new Scanner(System.in).nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Read the number of elements (n) and the initial value (x) from input
int n = Integer.parseInt(new Scanner(System.in).nextLine());
int x = Integer.parseInt(new Scanner(System.in).nextLine());

// Read and sort the list of integers
List<Integer> a = na().stream().sorted().collect(Collectors.toList());

// Initialize the answer counter
int ans = 0;

// Check if the smallest element in the sorted list is greater than x
if (a.get(0) > x) {
    // If true, print 0 and exit since no elements can be subtracted from x
    System.out.println(0);
    System.exit(0);
}

// Iterate through the sorted list of integers
for (int i : a) {
    // If the current element is greater than x, set x to 0 and break the loop
    if (i > x) {
        x = 0;
        break;
    }
    // Subtract the current element from x
    x -= i;
    // Increment the answer counter
    ans += 1;
}

// If there is any remaining value in x, decrement the answer counter
if (x != 0) {
    ans -= 1;
}

// Print the final answer
System.out.println(ans);

