// Import the math module for mathematical functions
// Define a function to read an integer input from the user
public static int next_int ( ) {
    // Read an integer input from the user and convert it to an integer
    return Integer.parseInt(input());
}
// Define a function to read a list of integers from the user
public static List<Integer> next_ints ( ) {
    // Read a list of integers from the user and convert each element to an integer
    return Arrays.stream(input().split()).map(Integer::parseInt).collect(Collectors.toList());
}
// Read an integer `n` from the user
int n = next_int();
// Initialize a variable `t` to zero
int t = 0;
// Iterate through the range of integers from 0 to n-1
for (int i = 0; i < n; i++) {
    // Check if the index i is odd
    if (i + 1 & 1) {
        // If it is odd, increment the variable t by 1
        t += 1;
    }
}
// Print the result t/n as the output
System.out.println(t / n);

