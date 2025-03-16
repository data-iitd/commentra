import java.util.Scanner;  // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  // Create a Scanner object for reading the input

        int n = sc.nextInt();  // Read an integer from input
        int num = sc.nextInt();  // Read another integer from input

        Set<Integer> numSet = new HashSet<>();  // Create a set to store the unique numbers
        for (int i = 0; i < n; i++) {  // Read n integers from input
            numSet.add(sc.nextInt());  // Add the number to the set
        }

        Set<Integer> twoTimesSet = new HashSet<>();  // Create a set to store the counts of divisions by 2
        for (int i : numSet) {  // Iterate through the set
            for (int j = 0; j < 30; j++) {  // Check how many times the number can be divided by 2
                i /= 2;  // Divide the number by 2
                if (i % 2!= 0) {  // Check if the result is odd
                    twoTimesSet.add(j);  // Add the count of divisions to the set
                    break;  // Exit the inner loop if an odd number is found
                }
            }
        }

        if (twoTimesSet.size()!= 1) {  // If more than one unique count of divisions by 2 is found, print 0 and exit
            System.out.println(0);
            return;
        }

        int[] numList = new int[numSet.size()];  // Convert the set back to an array for processing
        int index = 0;  // Initialize the index of the array
        for (int i : numSet) {  // Iterate through the set
            numList[index++] = i;  // Add the number to the array
        }

        int lcm = numList[0];  // Initialize LCM with the first element of the array
        for (int i = 1; i < numList.length; i++) {  // Calculate the LCM of all numbers in the array
            lcm = lcm * numList[i] / gcd(lcm, numList[i]);  // Update LCM using the GCD
        }

        System.out.println((num - lcm / 2) / lcm + 1);  // Calculate and print the final result based on the LCM and the input number
    }

    public static int gcd(int a, int b) {  // Calculate the greatest common divisor (GCD) of two integers
        if (b == 0) {  // If b is 0, return a
            return a;
        }
        return gcd(b, a % b);  // Recursively call the function with the updated values of a and b
    }
}

