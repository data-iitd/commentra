import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {

    // Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
    public static boolean valid(int i, int j, int n, int m) {
        if (i < n && i >= 0 && j >= 0 && j < m) {
            return true;
        }
        return false;
    }

    // Function to calculate the sum of integers from i to n using the formula for the sum of an arithmetic series
    public static long sumn(int i, int n) {
        return (long) (n - i) * (i + n) / 2;
    }

    // Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
    public static double sqfun(int a, int b, int c) {
        return (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);
    }

    // Function to read a single line of input and return it as a tuple of integers
    public static int[] value() {
        Scanner scanner = new Scanner(System.in);
        return Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    // Function to read a single line of input from stdin and return it as a tuple of integers
    public static int[] values() {
        Scanner scanner = new Scanner(System.in);
        return Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    // Function to read a single line of input and return it as a list of integers
    public static List<Integer> inlst() {
        Scanner scanner = new Scanner(System.in);
        return Arrays.stream(scanner.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
    }

    // Function to read a single line of input from stdin and return it as a list of integers
    public static List<Integer> inlsts() {
        Scanner scanner = new Scanner(System.in);
        return Arrays.stream(scanner.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
    }

    // Function to read a single integer from input
    public static int inp() {
        Scanner scanner = new Scanner(System.in);
        return Integer.parseInt(scanner.nextLine());
    }

    // Function to read a single integer from stdin
    public static int inps() {
        Scanner scanner = new Scanner(System.in);
        return Integer.parseInt(scanner.nextLine());
    }

    // Function to read a single line of input and return it as a string
    public static String instr() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    // Function to read a single line of input and return it as a list of strings
    public static List<String> stlst() {
        Scanner scanner = new Scanner(System.in);
        return Arrays.asList(scanner.nextLine().split(" "));
    }

    // Function to process a string by removing specific characters and converting it to lowercase
    public static String f(String s) {
        StringBuilder r = new StringBuilder();
        for (char i : s.toCharArray()) {
            if (i != '-' && i != ';' && i != '_') {
                r.append(Character.toLowerCase(i));
            }
        }
        return r.toString();
    }

    // Main function to solve the problem
    public static void solve() {
        List<String> l = new ArrayList<>();
        // Read three lines of input, process them, and store the results in a list
        for (int i = 0; i < 3; i++) {
            l.add(f(instr()));
        }

        // Generate all permutations of the processed strings
        List<String> permutations = new ArrayList<>();
        permute(l, 0, permutations);

        // Read the number of test cases and check if the processed input is in the list of permutations
        int testCases = inp();
        for (int i = 0; i < testCases; i++) {
            String input = f(instr());
            if (permutations.contains(input)) {
                System.out.println("ACC"); // Accepted
            } else {
                System.out.println("WA"); // Wrong Answer
            }
        }
    }

    // Helper function to generate permutations
    public static void permute(List<String> l, int index, List<String> permutations) {
        if (index == l.size() - 1) {
            permutations.add(String.join("", l));
            return;
        }
        for (int i = index; i < l.size(); i++) {
            Collections.swap(l, i, index);
            permute(l, index + 1, permutations);
            Collections.swap(l, i, index);
        }
    }

    // Entry point of the program
    public static void main(String[] args) {
        solve();
    }
}
