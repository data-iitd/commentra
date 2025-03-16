
import java.util.Scanner;  // Import the Scanner class for input reading

public class atcoder_ABC150_D{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input reading

        // Read two integers from input: n (an upper limit) and num (a number to be processed)
        int n = scanner.nextInt();
        int num = scanner.nextInt();

        // Read a set of integers from input and convert them to a set to ensure uniqueness
        java.util.Set<Integer> numSet = new java.util.HashSet<>();
        for (int i = 0; i < n; i++) {
            numSet.add(scanner.nextInt());  // Add each integer to the set
        }

        // Initialize an empty set to store values related to the two times condition
        java.util.Set<Integer> twoTimesSet = new java.util.HashSet<>();

        // Iterate through each number in the unique set
        for (int i : numSet) {
            // Check how many times the number can be divided by 2
            int count = 0;
            while (i % 2 == 0) {
                i /= 2;  // Divide the number by 2
                count++;  // Increment the count of divisions
            }
            twoTimesSet.add(count);  // Add the count of divisions to the set
        }

        // If more than one unique count of divisions by 2 is found, print 0 and exit
        if (twoTimesSet.size()!= 1) {
            System.out.println(0);  // Print 0 if more than one unique count is found
        } else {
            // If the loop completes without breaking, proceed to calculate the least common multiple (LCM)
            int[] numArray = numSet.toArray(new Integer[0]);  // Convert the set back to an array for processing
            int lcm = numArray[0];  // Initialize LCM with the first element of the array

            // Calculate the LCM of all numbers in the array
            for (int i = 1; i < numArray.length; i++) {
                int a = lcm;
                int b = numArray[i];
                while (b!= 0) {
                    int temp = b;
                    b = a % b;
                    a = temp;
                }
                lcm = (lcm * numArray[i]) / a;  // Update LCM using the GCD
            }

            // Calculate and print the final result based on the LCM and the input number
            System.out.println(((num - lcm / 2) / lcm) + 1);  // Print the final result
        }

        scanner.close();  // Close the Scanner object to release system resources
    }
}

Translate the above Java code to C++ and end with comment "