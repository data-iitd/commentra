import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the input values for n and num
        int n = scanner.nextInt();
        int num = scanner.nextInt();

        // Read the set of integers
        Set<Integer> numSet = new HashSet<>();
        for (int i = 0; i < n; i++) {
            numSet.add(scanner.nextInt());
        }

        // Initialize an empty set to store the number of times each integer is divisible by 2
        Set<Integer> twoTimesSet = new HashSet<>();

        // Loop through each integer in the numSet
        for (int i : numSet) {
            // Divide the integer by 2 repeatedly until it is no longer even
            int count = 0;
            while (i % 2 == 0) {
                i /= 2;
                count++;
            }
            // Add the count to two_times_set
            twoTimesSet.add(count);
            // If two_times_set contains more than one element, print 0 and break
            if (twoTimesSet.size() > 1) {
                System.out.println(0);
                return;
            }
        }

        // If the loop completes, calculate the LCM of the integers in numSet
        List<Integer> numList = new ArrayList<>(numSet);
        int lcm = numList.get(0);
        for (int i = 1; i < numList.size(); i++) {
            lcm = lcm(lcm, numList.get(i));
        }

        // Calculate the number of integers in the range from 1 to num that are divisible by the LCM
        System.out.println((num / lcm) - (lcm / 2) / lcm + 1);
    }

    // Helper method to calculate the LCM of two numbers
    public static int lcm(int a, int b) {
        return a * (b / gcd(a, b));
    }

    // Helper method to calculate the GCD of two numbers
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
