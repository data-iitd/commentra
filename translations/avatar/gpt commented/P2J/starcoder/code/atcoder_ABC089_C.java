
// Import necessary libraries
import java.util.*;

// Function to read a line of input and strip whitespace
public static String input() {
    return new Scanner(System.in).nextLine().trim();
}

// Function to read an integer from input
public static int INT() {
    return Integer.parseInt(input());
}

// Function to read a map of integers from input
public static int[] MAP() {
    return Arrays.stream(input().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// Function to read a list of integers from input
public static List<Integer> LIST() {
    return new ArrayList<>(Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList()));
}

// Function to read multiple lists of integers and zip them together
public static List<List<Integer>> ZIP(int n) {
    List<List<Integer>> lists = new ArrayList<>();
    for (int i = 0; i < n; i++) {
        lists.add(LIST());
    }
    return lists;
}

// Set the recursion limit to a high value
public static void main(String[] args) {
    // Define constants for infinity and modulo
    final int INF = (int) 1e9;
    final int mod = (int) 1e9 + 7;

    // Read the number of strings to process
    int N = INT();

    // Read N strings from input
    String[] S = new String[N];
    for (int i = 0; i < N; i++) {
        S[i] = input();
    }

    // Define the target characters to count
    String[] march = {"M", "A", "R", "C", "H"};

    // Initialize a list to count occurrences of each target character
    int[] march_lis = new int[5];

    // Count the occurrences of each character in the input strings
    for (String s : S) {
        if (s.charAt(0) == 'M' || s.charAt(0) =='m') {
            march_lis[0]++;
        }
        if (s.charAt(0) == 'A' || s.charAt(0) == 'a') {
            march_lis[1]++;
        }
        if (s.charAt(0) == 'R' || s.charAt(0) == 'r') {
            march_lis[2]++;
        }
        if (s.charAt(0) == 'C' || s.charAt(0) == 'c') {
            march_lis[3]++;
        }
        if (s.charAt(0) == 'H' || s.charAt(0) == 'h') {
            march_lis[4]++;
        }
    }

    // Initialize the answer variable to store the result
    int ans = 0;

    // Calculate the number of ways to choose 3 different characters from the counts
    for (int x : march_lis) {
        for (int y : march_lis) {
            for (int z : march_lis) {
                if (x!= y && x!= z && y!= z) {
                    ans += x * y * z;
                }
            }
        }
    }

    // Print the final answer
    System.out.println(ans);
}

// 