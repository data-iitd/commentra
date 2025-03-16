public class BubbleSort {
    public static void main(String[] args) {
        // Declare an integer array 'a' of size 1000 and three integer variables 'n', 'i', and 'j'
        int[] a = new int[1000];
        int n, i, j;
        int d = 0; // Initialize a variable 'd' to keep track of the number of swaps made during sorting

        // Read the size of the array from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        // Read 'n' integers from the user and store them in the array 'a'
        for (i = 0; i < n; i++) {
            a[i] = scanner.nextInt(); // Read an integer and store it in the current index of the array 'a'
        }

        // Implement bubble sort algorithm to sort the array 'a' in ascending order
        for (i = 0; i < n; i++) { // Iterate through each index of the array 'a'
            for (j = n - 1; j >= i + 1; j--) { // Iterate through the array from the last index to the current index
                if (a[j] < a[j - 1]) { // Check if the current element is smaller than the previous element
                    int temp = a[j]; // Swap the elements if they are in the wrong order
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                    d++; // Increment the swap counter
                }
            }
        }

        // Print the sorted array 'a'
        System.out.print(a[0]); // Print the first element of the array
        for (i = 1; i < n; i++) { // Iterate through the remaining elements of the array
            System.out.print(" " + a[i]); // Print each element followed by a space
        }
        System.out.println(); // Print a newline character at the end of the line

        // Print the number of swaps made during sorting
        System.out.println(d);

        // Return 0 to indicate successful execution of the program
        return 0;
    }
}
