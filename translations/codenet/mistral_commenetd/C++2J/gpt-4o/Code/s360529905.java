import java.util.Arrays; // import the Arrays class for sorting

public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in); // create a Scanner object for input
        int N = scanner.nextInt(); // read the number of elements from the standard input
        int[] a = new int[N]; // allocate an array of size N for a
        int[] b = new int[N]; // allocate an array of size N for b

        for (int i = 0; i < N; i++) { // iterate through the array a and assign each element to b
            a[i] = scanner.nextInt(); // read an integer from the standard input and assign it to the ith position in array a
            b[i] = a[i]; // copy the value of the ith position in array a to the ith position in array b
        }

        Arrays.sort(b); // sort the elements in array b in ascending order

        int frontHalf = b[N / 2 - 1]; // assign the middle value of the first half of the sorted array b to frontHalf
        int backHalf = b[N / 2]; // assign the middle value of the second half of the sorted array b to backHalf

        for (int i = 0; i < N; i++) { // iterate through the array a and print the appropriate middle value based on the condition
            if (a[i] < backHalf) { // if the value at the ith position in array a is less than the middle value of the second half of the sorted array b
                System.out.println(backHalf); // print the middle value of the second half of the sorted array b
            } else {
                System.out.println(frontHalf); // print the middle value of the first half of the sorted array b
            }
        }

        scanner.close(); // close the scanner
    }
}
// <END-OF-CODE>
