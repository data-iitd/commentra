import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Declare necessary variables for input/output operations, mathematical calculations, and data structures.
        Scanner sc = new Scanner(System.in);
        int n, d;
        n = sc.nextInt();
        d = sc.nextInt();
        double a = d * 2 + 1;
        // Calculate the value of 'a' which is used in the subsequent calculations.
        System.out.println(Math.ceil(n / a));
        // Output the ceiling of the division of n by 'a' to the standard output.
    }
}

