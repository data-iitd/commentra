public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Input the size of the vector
        int[] p = new int[n]; // Initialize an array of size n

        // Input the elements of the array
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt(); // Read each element into the array
        }

        int ans = 0; // Initialize the answer counter to zero

        // Loop through the array to check for specific conditions
        for (int i = 0; i < n - 1; i++) {
            // Check if the current element matches its expected position (1-based index)
            if (p[i] == i + 1) {
                p[i + 1] = p[i]; // Set the next element to the current element
                ans += 1; // Increment the answer counter
            }
        }

        // Check if the last element matches its expected position
        if (p[n - 1] == n) {
            ans += 1; // Increment the answer counter if the condition is met
        }

        System.out.println(ans); // Output the final count of matches
    }
}
