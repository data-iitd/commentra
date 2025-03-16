import java.util.Scanner;  // Importing the Scanner class for reading input from the console
import java.util.TreeMap; // Importing the TreeMap class for storing integer keys and their corresponding integer values

public class Main {
    public static void main(String[] args) throws Exception { // Main method to start the program
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the console

        int a[] = new int[5]; // Creating an integer array 'a' of size 5
        int r[] = new int[5]; // Creating an integer array 'r' of size 5
        TreeMap<Integer, Integer> map = new TreeMap<>(); // Creating an empty TreeMap to store integer keys and their corresponding integer values

        // Reading input elements of array 'a' and storing their remainders in array 'r'
        for (int i = 0; i < a.length; i++) {
            a[i] = sc.nextInt(); // Reading an integer value from the console and storing it in the 'i'th index of array 'a'
            r[i] = a[i] % 10; // Calculating the remainder of the 'i'th element of array 'a' and storing it in the 'i'th index of array 'r'

            int b = 10; // Initializing 'b' to 10
            if (r[i] != 0) { // Checking if the remainder of the 'i'th element of array 'a' is not zero
                b = 10 - r[i]; // Calculating the complement of the remainder and assigning it to 'b'
                map.put(b, a[i]); // Storing the complement as a key and the corresponding integer value (the 'i'th element of array 'a') in the TreeMap
            }
        }

        int ans = 0; // Initializing 'ans' to zero

        // Checking if the TreeMap is empty
        if (map.size() == 0) {
            for (int i = 0; i < a.length; i++) { // Iterating through the array 'a'
                ans += a[i]; // Adding the 'i'th element of array 'a' to the sum 'ans'
            }
            System.out.println(ans); // Printing the sum of all elements in array 'a'
            return; // Exiting the method if the TreeMap is empty
        }

        int last = map.get(map.lastKey()); // Getting the last key (complement) from the TreeMap and finding its corresponding value (the last element of array 'a')
        int idx = 0; // Initializing 'idx' to zero

        // Finding the index of the last element in array 'a'
        for (int i = 0; i < a.length; i++) {
            if (a[i] == last) { // Checking if the 'i'th element of array 'a' is equal to the last element
                idx = i; // If true, assigning the index to 'idx'
                break; // Exiting the loop
            }
        }

        // Calculating the sum of all elements in array 'a' except the last one
        for (int i = 0; i < a.length; i++) {
            if (i != idx) { // Checking if the current index is not equal to 'idx'
                if (a[i] % 10 == 0) { // Checking if the 'i'th element of array 'a' is a multiple of 10
                    ans += a[i]; // If true, adding it to the sum 'ans'
                } else { // If the 'i'th element of array 'a' is not a multiple of 10
                    ans += a[i] + (10 - r[i]); // Adding the 'i'th element of array 'a' and its complement to the sum 'ans'
                }
            }
        }

        // Adding the last element of array 'a' to the sum 'ans'
        ans += last;

        System.out.println(ans); // Printing the final sum
    }
}
