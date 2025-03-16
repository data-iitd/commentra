public class Main {
    // Method to compare two integers for sorting in descending order
    public static int compare(int a, int b) {
        return b - a;
    }

    public static void main(String[] args) {
        // Declare an array of integers and a variable for iteration
        int[] array = new int[10];

        // Read 10 integers from standard input into the array
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        for (int i = 0; i < 10; i++) {
            array[i] = scanner.nextInt();
        }

        // Sort the array in descending order using Arrays.sort with a custom comparator
        java.util.Arrays.sort(array);
        java.util.Collections.reverseOrder(array);

        // Print the first 3 elements of the sorted array
        for (int i = 0; i < 3; i++) {
            System.out.println(array[i]);
        }

        // Return 0 to indicate successful completion of the program
        System.exit(0);
    }
}
