import java.util.Scanner;

public class BinarySearchExample {
    static int[] A = new int[1000000]; // initialize an integer array A of size 1,000,000
    static int n; // declare an integer n

    /* Binary Search */
    static int binarySearch(int key) { // method to perform binary search
        int left = 0; // initialize left index to 0
        int right = n; // initialize right index to the last index of the array
        int mid; // initialize middle index

        while (left < right) { // while left index is less than right index
            mid = (left + right) / 2; // calculate middle index
            if (key == A[mid]) { // if key is equal to the middle element
                return 1; // return 1 to indicate key is found
            }
            if (key > A[mid]) { // if key is greater than the middle element
                left = mid + 1; // update left index to search in the right half
            } else { // if key is less than the middle element
                right = mid; // update right index to search in the left half
            }
        }
        return 0; // if key is not found, return 0
    }

    public static void main(String[] args) { // main method
        Scanner scanner = new Scanner(System.in); // create a Scanner object for input
        int sum = 0; // initialize sum

        n = scanner.nextInt(); // read the number of elements in the array from the standard input
        for (int i = 0; i < n; i++) { // for loop to read and store the elements of the array
            A[i] = scanner.nextInt();
        }
        int q = scanner.nextInt(); // read the number of queries from the standard input
        for (int i = 0; i < q; i++) { // for loop to perform binary search for each query
            int k = scanner.nextInt();
            if (binarySearch(k) == 1) // if key is found in the array
                sum++; // increment sum by 1
        }
        System.out.println(sum); // print the number of queries with a matching element in the array
        scanner.close(); // close the scanner
    }
}

// <END-OF-CODE>
