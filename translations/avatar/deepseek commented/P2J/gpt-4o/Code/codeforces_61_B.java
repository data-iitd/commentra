import java.util.*;
import java.io.*;

public class Main {
    
    // Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
    public static boolean valid(int i, int j, int n, int m) {
        return i < n && i >= 0 && j >= 0 && j < m;
    }

    // Function to calculate the sum of an arithmetic series from i to n
    public static long sumn(int i, int n) {
        return (long) (n - i) * (i + n) / 2;
    }

    // Function to solve a quadratic equation of the form ax^2 + bx + c = 0
    public static double sqfun(double a, double b, double c) {
        return (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);
    }

    // Function to read a single or multiple integer values from input
    public static int[] value() {
        Scanner sc = new Scanner(System.in);
        return Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    // Function to read a list of integers from input
    public static List<Integer> inlst() {
        Scanner sc = new Scanner(System.in);
        List<Integer> list = new ArrayList<>();
        for (String s : sc.nextLine().split(" ")) {
            list.add(Integer.parseInt(s));
        }
        return list;
    }

    // Function to read a single integer from input
    public static int inp() {
        Scanner sc = new Scanner(System.in);
        return Integer.parseInt(sc.nextLine());
    }

    // Function to read a string from input
    public static String instr() {
        Scanner sc = new Scanner(System.in);
        return sc.nextLine();
    }

    // Function to sanitize a string by converting it to lowercase and removing certain characters
    public static String f(String s) {
        StringBuilder r = new StringBuilder();
        for (char i : s.toCharArray()) {
            if (i != '-' && i != ';' && i != '_') {
                r.append(Character.toLowerCase(i));
            }
        }
        return r.toString();
    }

    // Main logic of the program
    public static void solve() {
        Scanner sc = new Scanner(System.in);
        List<String> l = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            l.add(f(sc.nextLine()));
        }
        
        Set<String> permutations = new HashSet<>();
        permute(l, 0, permutations);
        
        int t = inp();
        for (int i = 0; i < t; i++) {
            if (permutations.contains(f(instr()))) {
                System.out.println("ACC");
            } else {
                System.out.println("WA");
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

    public static void main(String[] args) {
        solve();
    }
}

// <END-OF-CODE>
