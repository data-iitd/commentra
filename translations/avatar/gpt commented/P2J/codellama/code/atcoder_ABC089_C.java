
// Import necessary libraries
import java.util.*;
import java.lang.*;
import java.io.*;

// Function to read a line of input and strip whitespace
public static String input() throws IOException {
    return br.readLine().trim();
}

// Function to read an integer from input
public static int INT() throws IOException {
    return Integer.parseInt(input());
}

// Function to read a map of integers from input
public static Map<Integer, Integer> MAP() throws IOException {
    Map<Integer, Integer> map = new HashMap<>();
    String[] tokens = input().split(" ");
    for (int i = 0; i < tokens.length; i++) {
        map.put(i, Integer.parseInt(tokens[i]));
    }
    return map;
}

// Function to read a list of integers from input
public static List<Integer> LIST() throws IOException {
    List<Integer> list = new ArrayList<>();
    String[] tokens = input().split(" ");
    for (int i = 0; i < tokens.length; i++) {
        list.add(Integer.parseInt(tokens[i]));
    }
    return list;
}

// Function to read multiple lists of integers and zip them together
public static List<List<Integer>> ZIP(int n) throws IOException {
    List<List<Integer>> lists = new ArrayList<>();
    for (int i = 0; i < n; i++) {
        lists.add(LIST());
    }
    return lists;
}

// Set the recursion limit to a high value
Thread.setStackSize(100000000);

// Define constants for infinity and modulo
final int INF = 1000000000;
final int mod = 1000000007;

// Import java.util.Arrays for sorting
import java.util.Arrays;

// Import java.util.stream.Collectors for collecting streams
import java.util.stream.Collectors;

// Define the BufferedReader object
static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

// Define the PrintWriter object
static PrintWriter pw = new PrintWriter(System.out);

// Read the number of strings to process
int N = INT();

// Read N strings from input
List<String> S = new ArrayList<>();
for (int i = 0; i < N; i++) {
    S.add(input());
}

// Define the target characters to count
List<String> march = Arrays.asList("M", "A", "R", "C", "H");

// Initialize a list to count occurrences of each target character
List<Integer> march_lis = new ArrayList<>();
for (int i = 0; i < 5; i++) {
    march_lis.add(0);
}

// Count the occurrences of each character in the input strings
for (String s : S) {
    if (march.contains(s.toUpperCase())) {
        march_lis.set(march.indexOf(s.toUpperCase()), march_lis.get(march.indexOf(s.toUpperCase())) + 1);
    }
}

// Initialize the answer variable to store the result
int ans = 0;

// Calculate the number of ways to choose 3 different characters from the counts
for (int x : march_lis) {
    for (int y : march_lis) {
        for (int z : march_lis) {
            if (x != y && x != z && y != z) {
                ans += x * y * z;
            }
        }
    }
}

// Print the final answer
pw.println(ans);

// End the program
pw.close();

