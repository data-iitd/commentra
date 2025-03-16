

import java.util.Scanner;

public class s201528373{
    public static void main(String[] args) {
        // Initialize variables
        int n, x;
        int[] l;

        // Read input values for n and x
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of arrays:");
        n = scanner.nextInt();
        System.out.println("Enter the sum of elements in an array that should not exceed:");
        x = scanner.nextInt();

        // Initialize an empty array l to store the arrays
        l = new int[n];

        // Read input values for each array and store them in the array l
        for (int i = 0; i < n; i++) {
            // Read the length of the current array
            System.out.println("Enter the length of array number " + (i + 1) + ":");
            int tmpL = scanner.nextInt();

            // Store the length of the current array in the array l
            l[i] = tmpL;
        }

        // Initialize variables for sum and result array index
        int tmpSum, rs;

        // Iterate through the array l to find the index of the last array whose sum is less than or equal to x
        for (int i = 0; i < n; i++) {
            // Initialize a variable tmpSum to store the sum of elements in the current array
            tmpSum = 0;

            // Calculate the sum of elements in the current array
            for (int j = 0; j < l[i]; j++) {
                // Read the value of the current element and add it to the sum
                System.out.println("Enter the value of element number " + (j + 1) + " in array number " + (i + 1) + ":");
                int tmp = scanner.nextInt();
                tmpSum += tmp;
            }

            // Check if the sum of elements in the current array is greater than x
            if (tmpSum > x) {
                // If yes, break the loop as we don't need to check further arrays
                break;
            }

            // If the sum of elements in the current array is less than or equal to x, update the result array index
            rs = i + 1;
        }

        // Print the result array index
        System.out.println("The last array index whose sum of elements is less than or equal to " + x + " is: " + rs);
    }
}
