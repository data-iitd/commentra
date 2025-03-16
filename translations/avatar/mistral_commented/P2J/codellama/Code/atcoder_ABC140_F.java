// Import the java.util.Scanner class to read input from standard input
import java.util.Scanner;

// Function to read an integer from standard input
public static int I() {
    Scanner sc = new Scanner(System.in);
    return sc.nextInt();
}

// Function to read a list of integers from standard input
public static int[] LI() {
    Scanner sc = new Scanner(System.in);
    String[] S = sc.nextLine().split(" ");
    int[] L = new int[S.length];
    for (int i = 0; i < S.length; i++) {
        L[i] = Integer.parseInt(S[i]);
    }
    return L;
}

// Function to sort a list of integers in descending order
public static void sort(int[] L) {
    for (int i = 0; i < L.length; i++) {
        for (int j = i + 1; j < L.length; j++) {
            if (L[i] < L[j]) {
                int temp = L[i];
                L[i] = L[j];
                L[j] = temp;
            }
        }
    }
}

// Function to check if a list of integers contains a subsequence of integers
public static boolean contains(int[] L, int[] S) {
    for (int i = 0; i < L.length; i++) {
        for (int j = 0; j < S.length; j++) {
            if (L[i] == S[j]) {
                return true;
            }
        }
    }
    return false;
}

// Main function to solve the problem
public static void main(String[] args) {
    // Read the number of test cases
    int N = I();

    // Read the list of integers and sort it in descending order
    int[] S = LI();
    sort(S);

    // Initialize a list of flags to keep track of whether each integer has been included in the current subsequence or not
    boolean[] flag = new boolean[S.length];

    // Initialize an empty list to store the current subsequence
    int[] cur = new int[0];

    // Start from the first integer and include it in the subsequence
    cur = add(cur, S[0]);
    flag[0] = false;

    // For each integer in the sorted list
    for (int i = 1; i < N; i++) {
        // Initialize variables
        int j = 0;
        int jM = cur.length;

        // Try to include the current integer in the subsequence
        for (int k = 0; k < S.length; k++) {
            // If the flag of the current integer is True and it is smaller than the last integer in the subsequence
            if (flag[k] && S[k] < cur[j]) {
                // Include the current integer in the subsequence and update the flag and the index of the last integer in the subsequence
                cur = add(cur, S[k]);
                j += 1;
                flag[k] = false;
                // If the length of the subsequence hasn't changed, break the loop
                if (j == jM) {
                    break;
                }
            }
        }

        // If we couldn't include any integer in the subsequence after the current one, return "No"
        if (j == 0) {
            System.out.println("No");
            return;
        }

        // Sort the subsequence in descending order
        sort(cur);
    }

    // If we could include all the integers in the subsequence, return "Yes"
    System.out.println("Yes");
}

// Function to add an integer to a list of integers
public static int[] add(int[] L, int x) {
    int[] newL = new int[L.length + 1];
    for (int i = 0; i < L.length; i++) {
        newL[i] = L[i];
    }
    newL[L.length] = x;
    return newL;
}

// Function to print a list of integers
public static void print(int[] L) {
    for (int i = 0; i < L.length; i++) {
        System.out.print(L[i] + " ");
    }
    System.out.println();
}

// Function to print a list of integers in a specific format
public static void print(int[] L, int[] S) {
    for (int i = 0; i < L.length; i++) {
        System.out.print(L[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < S.length; i++) {
        System.out.print(S[i] + " ");
    }
    System.out.println();
}

// Function to print a list of integers in a specific format
public static void print(int[] L, int[] S, int[] cur) {
    for (int i = 0; i < L.length; i++) {
        System.out.print(L[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < S.length; i++) {
        System.out.print(S[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < cur.length; i++) {
        System.out.print(cur[i] + " ");
    }
    System.out.println();
}

// Function to print a list of integers in a specific format
public static void print(int[] L, int[] S, int[] cur, boolean[] flag) {
    for (int i = 0; i < L.length; i++) {
        System.out.print(L[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < S.length; i++) {
        System.out.print(S[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < cur.length; i++) {
        System.out.print(cur[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < flag.length; i++) {
        System.out.print(flag[i] + " ");
    }
    System.out.println();
}

// Function to print a list of integers in a specific format
public static void print(int[] L, int[] S, int[] cur, boolean[] flag, int[] newL) {
    for (int i = 0; i < L.length; i++) {
        System.out.print(L[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < S.length; i++) {
        System.out.print(S[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < cur.length; i++) {
        System.out.print(cur[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < flag.length; i++) {
        System.out.print(flag[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newL.length; i++) {
        System.out.print(newL[i] + " ");
    }
    System.out.println();
}

// Function to print a list of integers in a specific format
public static void print(int[] L, int[] S, int[] cur, boolean[] flag, int[] newL, int[] newS) {
    for (int i = 0; i < L.length; i++) {
        System.out.print(L[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < S.length; i++) {
        System.out.print(S[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < cur.length; i++) {
        System.out.print(cur[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < flag.length; i++) {
        System.out.print(flag[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newL.length; i++) {
        System.out.print(newL[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newS.length; i++) {
        System.out.print(newS[i] + " ");
    }
    System.out.println();
}

// Function to print a list of integers in a specific format
public static void print(int[] L, int[] S, int[] cur, boolean[] flag, int[] newL, int[] newS, int[] newCur) {
    for (int i = 0; i < L.length; i++) {
        System.out.print(L[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < S.length; i++) {
        System.out.print(S[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < cur.length; i++) {
        System.out.print(cur[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < flag.length; i++) {
        System.out.print(flag[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newL.length; i++) {
        System.out.print(newL[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newS.length; i++) {
        System.out.print(newS[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newCur.length; i++) {
        System.out.print(newCur[i] + " ");
    }
    System.out.println();
}

// Function to print a list of integers in a specific format
public static void print(int[] L, int[] S, int[] cur, boolean[] flag, int[] newL, int[] newS, int[] newCur, boolean[] newFlag) {
    for (int i = 0; i < L.length; i++) {
        System.out.print(L[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < S.length; i++) {
        System.out.print(S[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < cur.length; i++) {
        System.out.print(cur[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < flag.length; i++) {
        System.out.print(flag[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newL.length; i++) {
        System.out.print(newL[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newS.length; i++) {
        System.out.print(newS[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newCur.length; i++) {
        System.out.print(newCur[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newFlag.length; i++) {
        System.out.print(newFlag[i] + " ");
    }
    System.out.println();
}

// Function to print a list of integers in a specific format
public static void print(int[] L, int[] S, int[] cur, boolean[] flag, int[] newL, int[] newS, int[] newCur, boolean[] newFlag, int[] newNewL) {
    for (int i = 0; i < L.length; i++) {
        System.out.print(L[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < S.length; i++) {
        System.out.print(S[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < cur.length; i++) {
        System.out.print(cur[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < flag.length; i++) {
        System.out.print(flag[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newL.length; i++) {
        System.out.print(newL[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newS.length; i++) {
        System.out.print(newS[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newCur.length; i++) {
        System.out.print(newCur[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newFlag.length; i++) {
        System.out.print(newFlag[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < newNewL.length; i++) {
        System.out.print(newNewL[i] + " ");
    }
    System.out.println();
}

// Function to print a list of integers in a specific format
public static void print(int[] L, int[] S, int[] cur, boolean[] flag, int[] newL, int[] newS, int[] newCur, boolean[] newFlag, i