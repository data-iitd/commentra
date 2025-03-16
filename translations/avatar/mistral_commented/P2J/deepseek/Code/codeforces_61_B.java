import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {
    // Function to check if given indices are valid
    public static boolean valid(int i, int j, int n, int m) {
        if (i < n && i >= 0 && j >= 0 && j < m) {
            return true;
        }
        return false;
    }

    // Function to calculate sum of first n natural numbers
    public static int sumn(int i, int n) {
        return (n - i) * (i + n) / 2;
    }

    // Function to calculate square root of a number using quadratic formula
    public static double sqfun(int a, int b, int c) {
        return (-b + Math.sqrt(b * b - 4 * a * c)) / 2 * a;
    }

    // Function to read a single line as a tuple of integers
    public static int[] value() {
        Scanner scanner = new Scanner(System.in);
        String[] parts = scanner.nextLine().split(" ");
        int[] result = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            result[i] = Integer.parseInt(parts[i]);
        }
        return result;
    }

    // Function to read a single line as a list of integers
    public static List<Integer> values() {
        Scanner scanner = new Scanner(System.in);
        String[] parts = scanner.nextLine().split(" ");
        List<Integer> result = new ArrayList<>();
        for (String part : parts) {
            result.add(Integer.parseInt(part));
        }
        return result;
    }

    // Function to read a single integer
    public static int inp() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    // Function to read a single integer from the standard input as a string
    public static String instr() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    // Function to read a list of integers
    public static List<Integer> inlst() {
        Scanner scanner = new Scanner(System.in);
        String[] parts = scanner.nextLine().split(" ");
        List<Integer> result = new ArrayList<>();
        for (String part : parts) {
            result.add(Integer.parseInt(part));
        }
        return result;
    }

    // Function to read a list of integers from the standard input
    public static List<Integer> inlsts() {
        Scanner scanner = new Scanner(System.in);
        String[] parts = scanner.nextLine().split(" ");
        List<Integer> result = new ArrayList<>();
        for (String part : parts) {
            result.add(Integer.parseInt(part));
        }
        return result;
    }

    // Function to read a single integer from the standard input
    public static int inp() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    // Function to read a single integer from the standard input
    public static int inps() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    // Function to read a single string from the standard input
    public static String instr() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    // Function to convert a string to a list
    public static List<String> stlst() {
        Scanner scanner = new Scanner(System.in);
        String[] parts = scanner.nextLine().split(" ");
        List<String> result = new ArrayList<>();
        for (String part : parts) {
            result.add(part);
        }
        return result;
    }

    // Main function to solve the problem
    public static void main(String[] args) {
        List<String> l = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            l.add(instr());
        }
        List<String> permutations = new ArrayList<>();
        for (List<String> perm : new HashSet<>(new Permutations<>(l))) {
            permutations.add(String.join("", perm));
        }
        int testCases = inp();
        for (int i = 0; i < testCases; i++) {
            String testString = instr();
            if (permutations.contains(testString)) {
                System.out.println("ACC");
            } else {
                System.out.println("WA");
            }
        }
    }
}

class Permutations<T> extends ArrayList<List<T>> {
    public Permutations(List<T> list) {
        super();
        permute(list, 0, list.size() - 1);
    }

    private void permute(List<T> list, int l, int r) {
        if (l == r) {
            this.add(new ArrayList<>(list));
        } else {
            for (int i = l; i <= r; i++) {
                Collections.swap(list, l, i);
                permute(list, l + 1, r);
                Collections.swap(list, l, i); // backtrack
            }
        }
    }
}
