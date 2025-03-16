import java.util.*;
import java.io.*;

public class Main {
    // Function to read a single line of input
    public static String input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return br.readLine().trim();
    }

    // Function to convert input to an integer
    public static int INT() throws IOException {
        return Integer.parseInt(input());
    }

    // Function to read a list of integers
    public static List<Integer> LIST() throws IOException {
        String[] tokens = input().split(" ");
        List<Integer> list = new ArrayList<>();
        for (String token : tokens) {
            list.add(Integer.parseInt(token));
        }
        return list;
    }

    public static void main(String[] args) throws IOException {
        // Read the number of strings
        int N = INT();

        // Read the list of strings
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = input();
        }

        // List of characters that can be selected
        String[] march = {"M", "A", "R", "C", "H"};

        // Initialize a list to count occurrences of each character in 'march'
        int[] march_lis = new int[5];

        // Count the occurrences of characters in 'march' in the list of strings
        for (String s : S) {
            char firstChar = Character.toUpperCase(s.charAt(0));
            for (int j = 0; j < march.length; j++) {
                if (firstChar == march[j].charAt(0)) {
                    march_lis[j]++;
                    break;
                }
            }
        }

        // Initialize the answer variable
        long ans = 0;

        // Calculate the number of combinations of three elements from march_lis
        for (int i = 0; i < march_lis.length; i++) {
            for (int j = i + 1; j < march_lis.length; j++) {
                for (int k = j + 1; k < march_lis.length; k++) {
                    ans += (long) march_lis[i] * march_lis[j] * march_lis[k];
                }
            }
        }

        // Print the final answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
