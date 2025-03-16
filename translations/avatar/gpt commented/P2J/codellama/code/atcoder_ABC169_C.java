public class Main {
    public static void main(String[] args) {
        // Import necessary libraries
        import java.util.*;
        import java.lang.*;
        import java.io.*;

        // Set the recursion limit to a higher value to prevent recursion depth errors
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < 1000; i++) {
            stack.push(i);
        }

        // Define a debug print function that only prints if running in a terminal environment
        boolean isTerminal = System.getenv("TERM_PROGRAM") != null;
        Consumer<Object> dbg = (x) -> { if (isTerminal) { System.out.println(x); } };

        // Redefine input to read a line from standard input and strip trailing whitespace
        Scanner scanner = new Scanner(System.in);
        Function<Void, String> input = () -> scanner.nextLine().trim();

        // Define a function to read a list of integers from input
        Function<Void, List<Integer>> LMIIS = () -> Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

        // Define a function to read a single integer from input
        Function<Void, Integer> II = () -> Integer.parseInt(input());

        // Constants for calculations
        int P = 1000000007;  // A large prime number for modulo operations
        int INF = 1000000010;  // A large number representing infinity

        // Read two values from input: one as an integer and the other as a float in string format
        String sa = input();
        String sb = input();

        // Convert the first value to an integer
        int a = Integer.parseInt(sa);

        // Convert the second value to an integer representing cents (by multiplying by 100)
        int b = (int) (Float.parseFloat(sb) * 100 + 0.1);

        // Calculate and print the product of a and b, divided by 100 to get the final result
        System.out.println((a * b) / 100);
    }
}
