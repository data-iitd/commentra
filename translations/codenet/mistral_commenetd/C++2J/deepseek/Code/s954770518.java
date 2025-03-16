public class Main {
    public static void main(String[] args) {
        int[] s = new int[11]; // Declare an integer array 's' of size 11
        int i; // Declare an integer variable 'i' for loop counter

        // Read 10 integers from the user and store them in the array 's'
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a Scanner object to read input from the user
        for(i=0;i<10;i++){
            s[i] = scanner.nextInt(); // Read an integer from the standard input and store it in the array 's' at the current index
        }

        // Sort the array 's' in ascending order using the sort function from the java.util.Arrays library
        java.util.Arrays.sort(s);

        // Print the 4th, 5th and 6th smallest elements from the sorted array 's'
        for(i=9;i>6;i--){ // Initialize the loop counter 'i' to 9 (index of the 5th smallest element) and decrement it until it becomes greater than the index of the 6th smallest element
            System.out.println(s[i]); // Print the current element of the array 's' to the standard output
        }
    }
}
