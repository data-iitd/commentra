// Declare global variables
int n, k, t; // n: number of elements, k: size of the subset, t: temporary variable for input
int[] vec; // Vector to store the input elements
int ans = 1000000001; // Initialize ans to a large value to find the minimum difference

public static void main(String[] args) {
    // Read the number of elements (n) and the size of the subset (k)
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    k = sc.nextInt();

    // Read n integers from input and store them in the vector
    vec = new int[n];
    for (int i = 0; i < n; i++) {
        t = sc.nextInt(); // Read each integer
        vec[i] = t; // Add the integer to the vector
    }

    // Sort the vector in non-decreasing order
    Arrays.sort(vec);

    // Iterate through the sorted vector to find the minimum difference
    for (int i = 0; i + k - 1 < n; i++) {
        // Calculate the difference between the maximum and minimum of the current subset of size k
        int diff = vec[i + k - 1] - vec[i];
        
        // Update the minimum difference found so far
        if (diff < ans) {
            ans = diff; // Update ans if a smaller difference is found
        }
    }

    // Output the minimum difference found
    System.out.println(ans);

    // End of code
    System.out.println("