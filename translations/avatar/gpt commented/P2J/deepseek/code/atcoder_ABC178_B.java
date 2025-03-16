import java.util.*;

public class Main {
    // Define a large constant for infinity
    static final long inf = (long) 1e20;

    // Define a modulus value commonly used in competitive programming
    static final long mod = (long) 1e9 + 7;

    // Define directional movements for 4 directions (up, right, down, left)
    static final int[] dx = {-1, 0, 1, 0};
    static final int[] dy = {0, 1, 0, -1};

    // Define diagonal movements for 8 directions (including diagonals)
    static final int[] ddx = {-1, -1, 0, 1, 1, 1, 0, -1};
    static final int[] ddy = {0, 1, 1, 1, 0, -1, -1, -1};

    // Function to read a line of input and return it as a list of integers
    static List<Integer> LI() {
        Scanner scanner = new Scanner(System.in);
        String[] tokens = scanner.nextLine().split(" ");
        List<Integer> result = new ArrayList<>();
        for (String token : tokens) {
            result.add(Integer.parseInt(token));
        }
        return result;
    }

    // Function to read a single integer from input
    static int I() {
        Scanner scanner = new Scanner(System.in);
        return Integer.parseInt(scanner.nextLine());
    }

    // Function to read a single float from input
    static double F() {
        Scanner scanner = new Scanner(System.in);
        return Double.parseDouble(scanner.nextLine());
    }

    // Function to read a line of input and return it as a list of strings
    static List<String> LS() {
        Scanner scanner = new Scanner(System.in);
        return Arrays.asList(scanner.nextLine().split(" "));
    }

    // Function to read a single string from input
    static String S() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    // Main function to execute the core logic of the program
    public static void main(String[] args) {
        // Read four integers from input
        List<Integer> values = LI();
        int a = values.get(0);
        int b = values.get(1);
        int c = values.get(2);
        int d = values.get(3);

        // Calculate the maximum value from the products of the pairs and return it
        int result = Math.max(Math.max(a * c, b * d), Math.max(a * d, b * c));
        System.out.println(result);
    }
}
