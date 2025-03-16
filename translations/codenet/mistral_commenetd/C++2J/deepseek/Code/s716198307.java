public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n;          // Number of elements in the array
        double avg;     // Average of the elements in the array
        double s;       // Difference between the first element and the average
        int ans;        // Index of the element with the maximum difference from the average

        // Initialize variables
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt(); // Read the number of elements from the standard input
        int[] a = new int[100]; // Declare and initialize an array of size 100 with zeros

        // Calculate the average of the elements in the array
        avg = 0;
        for(int i = 0; i < n; i++){
            a[i] = scanner.nextInt(); // Read an element from the standard input and store it in the array
            avg += a[i]; // Add the current element to the sum of all elements
        }

        // Calculate the average and divide it by the number of elements
        avg /= n;

        // Initialize the difference between the first element and the average
        s = Math.abs(a[0] - avg);

        // Initialize the index of the element with the maximum difference from the average
        ans = 0;

        // Find the index of the element with the maximum difference from the average
        for(int i = 1; i < n; i++){
            if(s > Math.abs(a[i] - avg)){ // If the current difference is greater than the previous difference
                s = Math.abs(a[i] - avg); // Update the difference
                ans = i;                 // Update the index
            }
        }

        // Print the index of the element with the maximum difference from the average
        System.out.println(ans);

        // Terminate the program
    }
}
