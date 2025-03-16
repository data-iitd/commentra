// Function to find the greatest common divisor (GCD) of two numbers
public static int gcd(int a, int b) {
    // Base case: if b is 0, return a as the GCD
    if (b == 0) {
        return a;
    }
    // Recursive case: find the GCD of b and the remainder of a divided by b
    return gcd(b, a % b);
}

// Function to perform Ruiseki algorithm on a given array
public static int[] ruiseki_lr(int[] array) {
    // Define a helper function to find the GCD of two numbers
    IntBinaryOperator op = (a, b) -> gcd(a, b);
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    int n = array.length;
    int[] left = new int[n + 1];
    int[] right = new int[n + 1];
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i + 1] = op.applyAsInt(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n - 1; i >= 0; i--) {
        right[i] = op.applyAsInt(right[i + 1], array[i]);
    }
    // Return the calculated left and right arrays
    return left;
}

// Read input from the user: number of elements in the array and the array itself
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int[] a = new int[n];
for (int i = 0; i < n; i++) {
    a[i] = sc.nextInt();
}
// Perform Ruiseki algorithm on the given array and get the left and right arrays
int[] left = ruiseki_lr(a);
int[] right = ruiseki_lr(a);
// Initialize answer variable with 0
int ans = 0;
// Iterate through the array and find the maximum GCD between adjacent elements in the left and right arrays
for (int i = 0; i < n; i++) {
    ans = Math.max(gcd(left[i], right[i + 1]), ans);
}
// Print the final answer
System.out.println(ans);

