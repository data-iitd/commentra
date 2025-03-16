import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read two integers from input: n (an upper limit) and num (a number to be processed)
        int n = scanner.nextInt();
        int num = scanner.nextInt();

        // Read a set of integers from input and convert them to a set to ensure uniqueness
        Set<Integer> numSet = new HashSet<>();
        while (scanner.hasNextInt()) {
            numSet.add(scanner.nextInt());
        }

        // Initialize an empty set to store values related to the two times condition
        Set<Integer> twoTimesSet = new HashSet<>();

        // Iterate through each number in the unique set
        for (int i : numSet) {
            int temp = i;
            // Check how many times the number can be divided by 2
            for (int j = 1; j < 30; j++) {
                temp /= 2;  // Divide the number by 2
                if (temp % 2 != 0) {  // Check if the result is odd
                    twoTimesSet.add(j);  // Add the count of divisions to the set
                    break;  // Exit the inner loop if an odd number is found
                }
            }

            // If more than one unique count of divisions by 2 is found, print 0 and exit
            if (twoTimesSet.size() != 1) {
                System.out.println(0);
                return;  // Exit the program
            }
        }

        // If the loop completes without breaking, proceed to calculate the least common multiple (LCM)
        Integer[] numList = numSet.toArray(new Integer[0]);  // Convert the set to an array for processing
        long lcm = numList[0];  // Initialize LCM with the first element of the array

        // Calculate the LCM of all numbers in the array
        for (int i = 1; i < numList.length; i++) {
            lcm = lcm * numList[i] / gcd(lcm, numList[i]);  // Update LCM using the GCD
        }

        // Calculate and print the final result based on the LCM and the input number
        System.out.println((num - lcm / 2) / lcm + 1);
    }

    // Method to calculate the greatest common divisor (GCD)
    private static int gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return (int) a;
    }
}
// <END-OF-CODE>
