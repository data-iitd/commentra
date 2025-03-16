import java.util.*;
import java.io.*;

public class Main {
    // Function to read a single value from input
    public static int[] value() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] parts = br.readLine().split(" ");
        return Arrays.stream(parts).mapToInt(Integer::parseInt).toArray();
    }

    // Function to read multiple values from input
    public static int[] values() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] parts = br.readLine().split(" ");
        return Arrays.stream(parts).mapToInt(Integer::parseInt).toArray();
    }

    // Function to read a list of integers from input
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

    // Function to read a single string from input
    public static String instr() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return br.readLine();
    }

    // Helper function to check if a grid of given dimensions can be formed
    public static boolean help(int a, int b, List<Integer> l) {
        List<List<Integer>> tot = new ArrayList<>();
        for (int i = 0; i < b; i++) {
            List<Integer> row = new ArrayList<>(l.subList(i * a, i * a + a));
            tot.add(row);
        }
        for (int i = 0; i < a; i++) {
            int sum = 0;
            for (int j = 0; j < b; j++) {
                sum += tot.get(j).get(i);
            }
            if (sum == b) {
                return true;
            }
        }
        return false;
    }

    // Main solving function
    public static void solve() throws IOException {
        String x = instr();
        List<Integer> s = new ArrayList<>();
        for (char c : x.toCharArray()) {
            if (c == 'O') {
                s.add(0);
            } else {
                s.add(1);
            }
        }
        List<String> tot = new ArrayList<>();
        for (int i = 1; i <= 12; i++) {
            if (12 % i == 0) {
                if (help(i, 12 / i, s)) {
                    tot.add((12 / i) + "x" + i);
                }
            }
        }
        System.out.print(tot.size() + " ");
        Collections.sort(tot);
        for (String str : tot) {
            System.out.print(str + " ");
        }
        System.out.println();
    }

    // Main execution block
    public static void main(String[] args) throws IOException {
        int t = inp();
        for (int i = 0; i < t; i++) {
            solve();
        }
    }
}

// <END-OF-CODE>
