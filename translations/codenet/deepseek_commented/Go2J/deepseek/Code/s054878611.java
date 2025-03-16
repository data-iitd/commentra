import java.util.Scanner;

public class Main {
    // solution function takes an integer n and an array a as input.
    // It initializes a memoization array memo with a size of 100002.
    // It iterates over the elements of a, incrementing the counts in memo for each element and its neighbors.
    // It then iterates over the memo array to find the maximum count, which represents the most frequent element or its neighbors.
    // The max function is a helper function to find the maximum of two integers.
    // The main function reads the input values, calls the solution function, and prints the result.
    public static int solution(int n, int[] a) {
        int[] memo = new int[100002];
        for (int num : a) {
            memo[num]++;
            memo[num + 1]++;
            memo[num + 2]++;
        }
        int out = 0;
        for (int num : memo) {
            if (num > 0) {
                out = Math.max(out, num);
            }
        }
        return out;
    }

    // max function returns the maximum of two integers.
    public static int max(int x, int y) {
        if (x > y) {
            return x;
        }
        return y;
    }

    // main function reads the input values, calls the solution function, and prints the result.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        System.out.println(solution(n, a));
    }
}
