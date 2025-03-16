public class Main {
    public static void main(String[] args) {
        int n, a[] = new int[100]; // Declare an integer n for the number of elements and an array a to store the elements
        double avg = 0, s, ans; // Initialize variables for average, the smallest difference, and the index of the closest element

        // Input the number of elements
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        // Loop to read n elements into the array and calculate their sum
        for(int i = 0; i < n; i++) {
            a[i] = scanner.nextInt(); // Read each element into the array
            avg += a[i]; // Accumulate the sum of the elements
        }

        // Calculate the average of the elements
        avg /= n;

        // Initialize the smallest difference with the absolute difference of the first element from the average
        s = Math.abs(a[0] - avg);
        ans = 0; // Initialize the index of the closest element to the first element

        // Loop to find the index of the element closest to the average
        for(int i = 1; i < n; i++) {
            // Check if the current element's difference from the average is smaller than the smallest found so far
            if(s > Math.abs(a[i] - avg)) {
                s = Math.abs(a[i] - avg); // Update the smallest difference
                ans = i; // Update the index of the closest element
            }
        }

        // Output the index of the element closest to the average
        System.out.println(ans);
    }
}
