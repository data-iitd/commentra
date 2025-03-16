public class Main {
    public static void main(String[] args) {
        int[] s = new int[11]; // Declare an array to store the input numbers
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a scanner object to read input

        // Step 3: Read input numbers into the array
        for(int i = 0; i < 10; i++) {
            s[i] = scanner.nextInt(); // Read input and store it in the array
        }

        // Step 4: Sort the array
        java.util.Arrays.sort(s, 0, 10); // Sort the array in ascending order

        // Step 5: Print the last four numbers of the sorted array
        for(int i = 9; i > 6; i--) {
            System.out.println(s[i]); // Print the last four numbers
        }
    }
}
