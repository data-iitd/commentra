import java.util.*;
import java.io.*;

public class Main {
    // Function to check if given indices are valid
    public static boolean valid(int i, int j, int n, int m) {
        return i < n && i >= 0 && j >= 0 && j < m;
    }

    // Function to calculate sum of first n natural numbers
    public static int sumn(int i, int n) {
        return (n - i) * (i + n) / 2;
    }

    // Function to calculate square root of a number using quadratic formula
    public static double sqfun(double a, double b, double c) {
        return (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);
    }

    // Function to read a single line as a list of integers
    public static List<Integer> readList() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tokens = br.readLine().split(" ");
        List<Integer> list = new ArrayList<>();
        for (String token : tokens) {
            list.add(Integer.parseInt(token));
        }
        return list;
    }

    // Function to read a single integer
    public static int readInt() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return Integer.parseInt(br.readLine());
    }

    // Function to read a single string
    public static String readString() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return br.readLine();
    }

    // Main function to solve the problem
    public static void solve() throws IOException {
        List<String> strings = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            strings.add(readString());
        }

        Set<String> permutations = new HashSet<>();
        permute(strings, 0, permutations);

        int testCases = readInt();
        for (int i = 0; i < testCases; i++) {
            String testString = readString();
            if (permutations.contains(testString)) {
                System.out.println("ACC");
            } else {
                System.out.println("WA");
            }
        }
    }

    // Function to generate permutations
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

    // Starting the program
    public static void main(String[] args) throws IOException {
        solve();
    }
}

// <END-OF-CODE>
