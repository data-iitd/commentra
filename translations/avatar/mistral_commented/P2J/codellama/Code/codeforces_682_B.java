
// Import necessary libraries
import java.util.*;

// Function to read a list of integers from standard input
public static int[] I() {
    Scanner sc = new Scanner(System.in);
    String[] s = sc.nextLine().split(" ");
    int[] l = new int[s.length];
    for (int i = 0; i < s.length; i++) {
        l[i] = Integer.parseInt(s[i]);
    }
    return l;
}

// Function to read an integer from standard input
public static int IS() {
    Scanner sc = new Scanner(System.in);
    return sc.nextInt();
}

// Function to read an integer from standard input and convert it to an integer
public static int IN() {
    Scanner sc = new Scanner(System.in);
    return Integer.parseInt(sc.nextLine());
}

// Function to read a float from standard input
public static float IF() {
    Scanner sc = new Scanner(System.in);
    return Float.parseFloat(sc.nextLine());
}

// Read the number of test cases 'n'
int n = IN();

// Read the list 'l' of length 'n' containing 'n' integers
int[] l = I();

// Initialize variable 'f' to 1
int f = 1;

// Sort the list 'l' in ascending order
Arrays.sort(l);

// Initialize variable 'c' to 0
int c = 0;

// Iterate through the list 'l'
for (int i : l) {
    // If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
    if (i > c) {
        c++;
    }
}

// Print the final result, which is the number of unique elements in the list 'l' plus 1
System.out.println(c + 1);

