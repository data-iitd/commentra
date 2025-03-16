import java.util.*; // Importing the necessary package for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize Scanner object to read input
        int n = sc.nextInt(); // Read the size of the array
        int[] arr = new int[n]; // Create an array of size n
        int sum = 0; // Initialize sum to 0

        // Read n integers from the user and store them in the array arr, while updating the sum
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            sum += arr[i];
        }

        int c = 0; // Initialize count of valid elements to remove
        StringBuilder sb = new StringBuilder(); // Create a StringBuilder to build the output string

        // Iterate through the array arr to find elements that can be removed
        for (int i = 0; i < n; i++) {
            // Check if removing the current element keeps the average unchanged
            if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
                c++; // Increment the count
                sb.append((i + 1) + " "); // Append the index (plus one) to the StringBuilder
            }
        }

        // Print the count of valid elements and the indices of these elements
        System.out.println(c);
        System.out.println(sb.toString());
    }
}
