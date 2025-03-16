
// Importing the Scanner class
import java.util.Scanner;

// Defining a custom input function
public static void input(String prompt) {
    System.out.print(prompt);
    Scanner sc = new Scanner(System.in);
    return sc.nextLine();
}

// Function to read an integer
public static int I() {
    return Integer.parseInt(input(""));
}

// Function to read multiple integers
public static int[] MI() {
    String[] s = input("").split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
        a[i] = Integer.parseInt(s[i]);
    }
    return a;
}

// Function to read a list of integers
public static List<Integer> LI() {
    String[] s = input("").split(" ");
    List<Integer> a = new ArrayList<Integer>();
    for (int i = 0; i < s.length; i++) {
        a.add(Integer.parseInt(s[i]));
    }
    return a;
}

// Main function
public static void main(String[] args) {
    // Setting the modulus value
    int mod = 1000000007;

    // Reading input values: N, A, and B
    int N = I();
    int A = I();
    int B = I();

    // Initializing the answer variable to 0
    int ans = 0;

    // Calculating the number of repetitions
    int rep = N / (A + B);

    // Adding the number of blocks that can be fully covered by A and B in one repetition
    ans += rep * A;

    // Calculating the remaining number of blocks
    int res = N - rep * (A + B);

    // Adding the number of blocks that can be covered by A in the remaining blocks
    ans += Math.min(res, A);

    // Printing the final answer
    System.out.println(ans);
}

// End of code
