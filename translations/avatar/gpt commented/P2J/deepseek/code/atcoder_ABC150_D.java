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
        for (String s : scanner.next().split(" ")) {
            numSet.add(Integer.parseInt(s));
        }
        
        // Initialize an empty set to store values related to the two times condition
        Set<Integer> twoTimesSet = new HashSet<>();
        
        // Iterate through each number in the unique set
        for (int i : numSet) {
            // Check how many times the number can be divided by 2
            int count = 0;
            while (i % 2 == 0) {
                i /= 2;
                count++;
            }
            twoTimesSet.add(count);
        }
        
        // If more than one unique count of divisions by 2 is found, print 0 and exit
        if (twoTimesSet.size() != 1) {
            System.out.println(0);
            return;
        }
        
        // If the loop completes without breaking, proceed to calculate the least common multiple (LCM)
        int[] numArray = new int[numSet.size()];
        int index = 0;
        for (int i : numSet) {
            numArray[index++] = i;
        }
        
        // Calculate the LCM of all numbers in the array
        int lcm = numArray[0];
        for (int i = 1; i < numArray.length; i++) {
            lcm = lcm * numArray[i] / gcd(lcm, numArray[i]);
        }
        
        // Calculate and print the final result based on the LCM and the input number
        System.out.println((num - lcm / 2) / lcm + 1);
    }
    
    // Helper method to calculate the greatest common divisor (GCD)
    private static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
