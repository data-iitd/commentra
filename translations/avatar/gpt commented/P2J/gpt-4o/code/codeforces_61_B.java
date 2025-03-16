import java.util.*;
import java.io.*;

public class Main {
    
    // Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
    public static boolean valid(int i, int j, int n, int m) {
        return i < n && i >= 0 && j >= 0 && j < m;
    }

    // Function to calculate the sum of integers from i to n using the formula for the sum of an arithmetic series
    public static double sumn(int i, int n) {
        return (n - i) * (i + n) / 2.0;
    }

    // Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
    public static double sqfun(double a, double b, double c) {
        return (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);
    }

    // Function to read a single line of input and return it as a list of integers
    public static List<Integer> inlst() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] parts = br.readLine().split(" ");
        List<Integer> list = new ArrayList<>();
        for (String part : parts) {
            list.add(Integer.parseInt(part));
        }
        return list;
    }

    // Function to read a single integer from input
    public static int inp() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return Integer.parseInt(br.readLine());
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
    public static void solve() throws IOException {
        List<String> l = new ArrayList<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Read three lines of input, process them, and store the results in a list
        for (int i = 0; i < 3; i++) {
            l.add(f(br.readLine()));
        }
        
        // Generate all permutations of the processed strings
        Set<String> permutations = new HashSet<>();
        permute(l, 0, permutations);
        
        // Read the number of test cases and check if the processed input is in the list of permutations
        for (int i = 0; i < inp(); i++) {
            String inputString = f(br.readLine());
            if (permutations.contains(inputString)) {
                System.out.println("ACC");  // Accepted
            } else {
                System.out.println("WA");   // Wrong Answer
            }
        }
    }

    // Helper function to generate permutations
    private static void permute(List<String> arr, int index, Set<String> result) {
        if (index == arr.size() - 1) {
            result.add(String.join("", arr));
            return;
        }
        for (int i = index; i < arr.size(); i++) {
            Collections.swap(arr, index, i);
            permute(arr, index + 1, result);
            Collections.swap(arr, index, i); // backtrack
        }
    }

    // Entry point of the program
    public static void main(String[] args) throws IOException {
        solve();
    }
}

// <END-OF-CODE>
