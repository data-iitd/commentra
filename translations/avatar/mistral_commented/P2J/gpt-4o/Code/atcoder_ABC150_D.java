import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Creating a scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Taking input of n and number of distinct numbers
        int n = scanner.nextInt();
        int num = scanner.nextInt();
        
        // Creating a set of distinct numbers
        HashSet<Integer> numSet = new HashSet<>();
        for (int i = 0; i < num; i++) {
            numSet.add(scanner.nextInt());
        }
        
        // Finding the powers of 2 that appear exactly twice in the binary representation of each number in numSet
        HashSet<Integer> twoTimesSet = new HashSet<>();
        for (int i : numSet) {
            // Initializing a counter to keep track of the number of times 2 is divided
            int powerOfTwo = 0;
            
            // Dividing i by 2 repeatedly until it is no longer odd
            while (i % 2 == 0) {
                powerOfTwo++;
                i /= 2;
            }

            // If the number of times 2 is divided is not exactly 1, then the answer is 0
            if (powerOfTwo > 1) {
                System.out.println(0);
                return;
            }

            // Add the power of 2 to twoTimesSet
            twoTimesSet.add(powerOfTwo);
        }

        // If the size of twoTimesSet is not exactly 1, then the answer is 0
        if (twoTimesSet.size() != 1) {
            System.out.println(0);
            return;
        }

        // Finding the least common multiple of all numbers in numSet
        Integer[] numList = numSet.toArray(new Integer[0]);
        long lcm = numList[0];

        // Finding the least common multiple of the first number and the next number
        for (int i = 1; i < numList.length; i++) {
            lcm = lcm * numList[i] / gcd(lcm, numList[i]);
        }

        // Printing the answer
        System.out.println((num - lcm / 2) / lcm + 1);
    }

    // Function to calculate the greatest common divisor
    public static int gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return (int) a;
    }
}
// <END-OF-CODE>
