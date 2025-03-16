import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input of n and number of distinct numbers
        int n = scanner.nextInt();
        int num = scanner.nextInt();
        
        // Creating a set of distinct numbers
        Set<Integer> numSet = new HashSet<>();
        scanner.nextLine(); // Consume newline
        String[] numStrArray = scanner.nextLine().split(" ");
        for (String numStr : numStrArray) {
            numSet.add(Integer.parseInt(numStr));
        }
        
        // Finding the powers of 2 that appear exactly twice in the binary representation of each number in numSet
        Set<Integer> twoTimesSet = new HashSet<>();
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
        List<Integer> numList = new ArrayList<>(numSet);
        int lcm = numList.get(0);
        
        // Finding the least common multiple of the first number and the next number
        for (int i = 1; i < numList.size(); i++) {
            lcm = lcm(lcm, numList.get(i));
        }
        
        // Printing the answer
        System.out.println((num - lcm / 2) / lcm + 1);
    }
    
    // Helper method to find the greatest common divisor
    private static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    // Helper method to find the least common multiple
    private static int lcm(int a, int b) {
        return a * (b / gcd(a, b));
    }
}
