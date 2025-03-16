import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {
    // Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
    public static boolean valid(int i, int j, int n, int m) {
        if (i < n && i >= 0 && j >= 0 && j < m) return true;
        return false;
    }

    // Function to calculate the sum of an arithmetic series from i to n
    public static double sumn(int i, int n) {
        return (n - i) * (i + n) / 2.0;
    }

    // Function to solve a quadratic equation of the form ax^2 + bx + c = 0
    public static double sqfun(int a, int b, int c) {
        return (-b + Math.sqrt(b * b - 4 * a * c)) / 2.0 * a;
    }

    // Function to read a single or multiple integer values from input
    public static int[] value() {
        String[] tokens = System.in.readLine().split(" ");
        int[] result = new int[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            result[i] = Integer.parseInt(tokens[i]);
        }
        return result;
    }

    // Function to read a single or multiple integer values from standard input
    public static int[] values() {
        String[] tokens = System.in.readLine().split(" ");
        int[] result = new int[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            result[i] = Integer.parseInt(tokens[i]);
        }
        return result;
    }

    // Function to read a list of integers from input
    public static List<Integer> inlst() {
        String[] tokens = System.in.readLine().split(" ");
        List<Integer> result = new ArrayList<>();
        for (String token : tokens) {
            result.add(Integer.parseInt(token));
        }
        return result;
    }

    // Function to read a list of integers from standard input
    public static List<Integer> inlsts() {
        String[] tokens = System.in.readLine().split(" ");
        List<Integer> result = new ArrayList<>();
        for (String token : tokens) {
            result.add(Integer.parseInt(token));
        }
        return result;
    }

    // Function to read a single integer from input
    public static int inp() {
        return Integer.parseInt(System.in.readLine());
    }

    // Function to read a single integer from standard input
    public static int inps() {
        return Integer.parseInt(System.in.readLine());
    }

    // Function to read a string from input
    public static String instr() {
        return System.in.readLine();
    }

    // Function to split a string into a list of words
    public static List<String> stlst() {
        String[] tokens = System.in.readLine().split(" ");
        return Arrays.asList(tokens);
    }

    // Function to sanitize a string by converting it to lowercase and removing certain characters
    public static String f(String s) {
        StringBuilder result = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c != '-' && c != ';' && c != '_') {
                result.append(Character.toLowerCase(c));
            }
        }
        return result.toString();
    }

    // Main logic of the program
    public static void solve() {
        List<String> l = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            l.add(f(instr()));
        }
        List<String> l2 = new ArrayList<>();
        for (List<String> perm : new Permutations<>(l)) {
            l2.add(String.join("", perm));
        }
        int t = inp();
        for (int i = 0; i < t; i++) {
            if (l2.contains(f(instr()))) {
                System.out.println("ACC");
            } else {
                System.out.println("WA");
            }
        }
    }

    public static void main(String[] args) {
        solve();
    }
}

class Permutations<T> extends AbstractList<List<T>> {
    private final List<T> list;
    private final int size;

    public Permutations(List<T> list) {
        this.list = new ArrayList<>(list);
        this.size = factorial(list.size());
    }

    private int factorial(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    @Override
    public List<T> get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        List<T> result = new ArrayList<>(list);
        int tempIndex = index;
        for (int i = 0; i < list.size(); i++) {
            Collections.swap(result, i, i + tempIndex % (list.size() - i));
            tempIndex /= list.size() - i;
        }
        return result;
    }

    @Override
    public int size() {
        return size;
    }
}
