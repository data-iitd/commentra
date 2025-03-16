import java.util.Arrays; // Importing the Arrays class for sorting
import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the console
        Scanner in = new Scanner(System.in);
        
        // Reading the number of elements in the array
        int n = in.nextInt();
        
        // Initializing an array of size n
        int a[] = new int[n];
        
        // Loop to read n integers from the user and store them in the array
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        
        // Sorting the array in ascending order
        Arrays.sort(a);
        
        // Loop to check the condition for adjacent elements in the sorted array
        for (int i = 0; i < a.length - 1; i++) {
            // Checking if the next element is less than double the current element
            // and ensuring they are not equal
            if (a[i + 1] < a[i] * 2 && a[i] != a[i + 1]) {
                // If the condition is met, print "YES" and exit the program
                System.out.println("YES");
                return;
            }
        }
        
        // If no such pair is found, print "NO"
        System.out.println("NO");
    }
}
