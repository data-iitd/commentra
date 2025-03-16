import java.util.*;
import java.io.*;

public class Main {
    // Function to read a single value as a tuple
    public static int[] value() {
        Scanner scanner = new Scanner(System.in);
        return Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    // Function to read multiple values as a tuple
    public static int[] values() {
        Scanner scanner = new Scanner(System.in);
        return Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    // Function to read a single value as a list
    public static List<Integer> inlst() {
        Scanner scanner = new Scanner(System.in);
        return Arrays.stream(scanner.nextLine().split(" ")).map(Integer::parseInt).toList();
    }

    // Function to read multiple values as a list
    public static List<Integer> inlsts() {
        Scanner scanner = new Scanner(System.in);
        return Arrays.stream(scanner.nextLine().split(" ")).map(Integer::parseInt).toList();
    }

    // Function to read a single value as an integer
    public static int inp() {
        Scanner scanner = new Scanner(System.in);
        return Integer.parseInt(scanner.nextLine());
    }

    // Function to read a single line as a string
    public static String instr() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    // Helper function to check if a sub-array of given size exists in a list
    public static boolean help(int a, int b, List<Integer> l) {
        List<List<Integer>> tot = new ArrayList<>();
        for (int i = 0; i < b; i++) {
            tot.add(l.subList(i * a, i * a + a));
        }
        for (int i = 0; i < a; i++) {
            int sum = 0;
            for (List<Integer> integers : tot) {
                sum += integers.get(i);
            }
            if (sum == b) {
                return true;
            }
        }
        return false;
    }

    // Main function to solve the problem
    public static void solve() {
        String x = instr();
        List<Integer> s = new ArrayList<>();
        for (char i : x.toCharArray()) {
            if (i == 'O') {
                s.add(0);
            } else {
                s.add(1);
            }
        }

        List<int[]> tot = new ArrayList<>();
        for (int i = 1; i <= 12; i++) {
            if (12 % i == 0) {
                if (help(i, 12 / i, s)) {
                    tot.add(new int[]{12 / i, i});
                }
            }
        }

        System.out.print(tot.size() + " ");
        tot.sort(Comparator.comparingInt(a -> a[0]));
        for (int[] a : tot) {
            System.out.print(a[0] + "x" + a[1] + " ");
        }
        System.out.println();
    }

    // Main function to run the code
    public static void main(String[] args) {
        for (int i = 0; i < inp(); i++) {
            solve();
        }
    }
}

// <END-OF-CODE>
