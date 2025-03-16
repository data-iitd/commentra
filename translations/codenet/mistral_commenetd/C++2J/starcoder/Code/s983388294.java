
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        // Read the number of elements in the array from the standard input
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int n = sc.nextInt();

        // Allocate memory for the array and read its elements
        int[] a = new int[n];
        for(int i=0; i<n; i++) {
            System.out.print("Enter element " + (i+1) + ": ");
            a[i] = sc.nextInt();
        }

        // Initialize a counter to keep track of the current element in the array
        int curr = 0;

        // Iterate through the array and increment the counter whenever the current element is one more than the previous one
        for(int i=0; i<n; i++) {
            if(a[i]==curr+1) curr++;
        }

        // Check if the counter is greater than zero, and if so, print the number of elements that are not consecutive
        if(curr>0) {
            System.out.println("The array has " + (n-curr) + " non-consecutive elements.");
        }

        // If the counter is zero, print -1 to indicate that all elements are not consecutive
        else {
            System.out.println("-1");
        }
    }
}

