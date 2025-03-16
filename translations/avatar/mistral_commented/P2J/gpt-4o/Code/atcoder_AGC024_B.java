import java.util.Scanner;

public class Main {
    // This is the main function that is called when we run the script.
    // It takes an input of an integer N and a list P of N integers as arguments.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of test cases N from the standard input.
        int N = scanner.nextInt();
        // Read N integers from the standard input and store them in a list P.
        int[] P = new int[N];
        for (int i = 0; i < N; i++) {
            P[i] = scanner.nextInt();
        }
        // Call the editorial function with N and P as arguments.
        editorial(N, P);
        scanner.close();
    }

    // This function calculates the answer based on the given input.
    public static void editorial(int N, int[] P) {
        // Base case: if there is only one element in the list, the answer is 0.
        if (N == 1) {
            System.out.println(0);
            return;
        }
        // Initialize an array a of size N+1 with all elements initialized to 0.
        int[] a = new int[N + 1];
        // Iterate through the list P and assign each element its index in the array a.
        for (int i = 0; i < N; i++) {
            a[P[i]] = i;
        }
        // Initialize two variables: tmp to keep track of the current streak,
        // and max_len to keep track of the maximum streak.
        int tmp = 1;
        int max_len = 1;
        // Iterate through the array a from the second element to the last.
        for (int i = 1; i < N; i++) {
            // If the current element has a smaller index than the previous one,
            // increment the streak and update max_len if necessary.
            if (a[i] < a[i + 1]) {
                tmp++;
                max_len = Math.max(max_len, tmp);
            } 
            // Otherwise, reset the streak to 1.
            else {
                tmp = 1;
            }
        }
        // Calculate the answer as the difference between the total number of elements
        // and the maximum streak.
        int ans = N - max_len;
        // Print the answer.
        System.out.println(ans);
    }

    // This function is used for testing purposes and is not called in the main function.
    public static void WA(int N, int[] P) {
        // Initialize two variables: tmp to keep track of the current streak,
        // and ans to keep track of the maximum answer.
        int tmp = 0;
        int ans = 0;
        // Iterate through the list P and calculate the answer based on the current streak.
        for (int i = 0; i < N; i++) {
            // If the current element is the first one or its previous element plus one,
            // increment the streak and update ans if necessary.
            if (i == 0 || P[i - 1] + 1 == P[i]) {
                tmp++;
                ans = Math.max(ans, tmp);
            } 
            // Otherwise, reset the streak to 1.
            else {
                tmp = 1;
            }
        }
        // Print the answer.
        System.out.println(N - ans);
    }
}

// <END-OF-CODE>
