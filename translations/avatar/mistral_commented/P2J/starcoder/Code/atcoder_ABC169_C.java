// Set the recursion limit for the function call stack
// This is necessary to prevent a "RecursionError" when dealing with large inputs
public static void main(String[] args) {
    // Set the recursion limit to a large value
    System.setrecursionlimit(1000000);

    // Import other required modules
    import java.util.*;
    import java.io.*;

    // Define a debug function to print debug messages
    // This function is used only when running the program in an IDE or terminal
    public static void dbg(Object... something) {
        if (System.getenv("TERM_PROGRAM")!= null) {
            System.out.println(Arrays.deepToString(something));
        }
    }

    // Define the input function to read input from standard input
    public static String input() {
        return new BufferedReader(new InputStreamReader(System.in)).readLine();
    }

    // Define a function to read multiple integers as a list
    public static List<Integer> LMIIS() {
        return Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
    }

    // Define input reading functions for single integer and string
    public static int II() {
        return Integer.parseInt(input());
    }

    // Define input reading functions for single integer and string
    public static String P() {
        return input();
    }

    // Define input reading functions for single integer and string
    public static int INF() {
        return 1000000000;
    }

    // Read input for two numbers 'a' and 'b'
    String sa, sb;
    sa = input();
    sb = input();
    int a = Integer.parseInt(sa);
    int b = (int) (Double.parseDouble(sb) * 100 + 0.1);

    // Calculate the product of 'a' and 'b' and print the result
    System.out.println(a * b / 100);
}

// Call the main function to start the program
main();

