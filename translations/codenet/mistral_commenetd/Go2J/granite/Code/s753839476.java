

import java.util.*;
import java.io.*;

public class s753839476{
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

        int n = scanner.nextInt();
        double t = scanner.nextDouble();
        double a = scanner.nextDouble();

        double[] heights = new double[n];
        for (int i = 0; i < n; i++) {
            heights[i] = scanner.nextDouble();
        }

        double minDiff = Math.abs(t - heights[0] * 0.006 - a);
        int minIdx = 0;

        for (int i = 1; i < n; i++) {
            double diff = Math.abs(t - heights[i] * 0.006 - a);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i + 1;
            }
        }

        writer.println(minIdx);
        writer.flush();
    }
}

// Function to calculate the absolute difference between two double numbers
public static double absDiffDouble(double n1, double n2) {
    return Math.abs(n1 - n2);
}

// Function to handle resource deallocation
public static void closeResource(Scanner scanner, PrintWriter writer) {
    scanner.close();
    writer.flush();
    System.in.close();
    System.out.close();
}

// Translate the above Java code to C++ and end with comment "