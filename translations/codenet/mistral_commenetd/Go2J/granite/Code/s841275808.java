

import java.util.*;

public class s841275808{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] X = new int[N];
        int[] Y = new int[N];

        for (int i = 0; i < N; i++) {
            X[i] = scanner.nextInt();
            Y[i] = X[i];
        }

        Arrays.sort(Y);

        int m1 = Y[N / 2 - 1];
        int m2 = Y[N / 2];

        for (int i = 0; i < N; i++) {
            if (X[i] <= m1) {
                System.out.println(m2);
            } else {
                System.out.println(m1);
            }
        }
    }
}

// Function to read an integer from the input
public static int ScanInt(Scanner scanner) {
    return scanner.nextInt();
}

// Function to read a float64 from the input
public static double ScanFloat64(Scanner scanner) {
    return scanner.nextDouble();
}

// Function to read a text from the input
public static String ScanText(Scanner scanner) {
    return scanner.next();
}

// Function to find the maximum of two integers
public static int Max(int a, int b) {
    return Math.max(a, b);
}

// Function to find the minimum of two integers
public static int Min(int a, int b) {
    return Math.min(a, b);
}

// Function to find the absolute value of an integer
public static int Abs(int a) {
    return Math.abs(a);
}


