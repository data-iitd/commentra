import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking input of n and number of distinct numbers
        int n = sc.nextInt();
        int num = sc.nextInt();

        // Creating a set of distinct numbers
        Set<Integer> num_set = new HashSet<>();
        for (int i = 0; i < num; i++) {
            num_set.add(sc.nextInt());
        }

        // Finding the powers of 2 that appear exactly twice in the binary representation of each number in num_set
        Set<Integer> two_times_set = new HashSet<>();
        for (int i : num_set) {
            // Initializing a counter to keep track of the number of times 2 is divided
            int power_of_two = 0;

            // Dividing i by 2 repeatedly until it is no longer odd
            while (i % 2 == 0) {
                power_of_two++;
                i /= 2;
            }

            // If the number of times 2 is divided is not exactly 1, then the answer is 0
            if (power_of_two > 1) {
                System.out.println(0);
                return;
            }

            // Add the power of 2 to two_times_set
            two_times_set.add(power_of_two);
        }

        // If the size of two_times_set is not exactly 1, then the answer is 0
        if (two_times_set.size()!= 1) {
            System.out.println(0);
            return;
        }

        // Finding the least common multiple of all numbers in num_set
        List<Integer> num_list = new ArrayList<>(num_set);
        int lcm = num_list.get(0);

        // Finding the least common multiple of the first number and the next number
        for (int i = 1; i < num_list.size(); i++) {
            lcm = lcm * num_list.get(i) / gcd(lcm, num_list.get(i));
        }

        // Printing the answer
        System.out.println((num - lcm / 2) / lcm + 1);
    }

    // Function to find the greatest common divisor of two numbers
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}

