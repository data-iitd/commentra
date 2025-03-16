public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Step 1: Read the value of n, which represents the number of elements in the array.
        long sum = 0; // Initialize sum to store the total difference.
        int[] a = new int[n]; // Step 2: Dynamically allocate memory for an array 'a' of size n.
        for (int i = 0; i < n; i++) { // Step 3: Read n elements into the array 'a'.
            a[i] = scanner.nextInt();
        }
        for (int i = 1; i < n; i++) { // Step 4: Iterate through the array and calculate the sum of the differences between consecutive elements, updating the array 'a' to ensure each element is at least as large as the previous one.
            if (a[i - 1] > a[i]) {
                sum += a[i - 1] - a[i]; // Add the difference to the sum.
                a[i] = a[i - 1]; // Update the current element to be at least as large as the previous one.
            }
        }
        System.out.println(sum); // Step 5: Print the calculated sum.
        scanner.close();
    }
}
