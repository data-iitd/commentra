
import java.util.*;  // Importing Scanner for input reading
import java.io.*;  // Importing PrintWriter for output writing

public class atcoder_AGC019_A{
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);  // Creating a Scanner object for input reading
        PrintWriter out = new PrintWriter(System.out);  // Creating a PrintWriter object for output writing

        int q = sc.nextInt();  // Reading integer input q
        int h = sc.nextInt();  // Reading integer input h
        int s = sc.nextInt();  // Reading integer input s
        int d = sc.nextInt();  // Reading integer input d
        int n = sc.nextInt();  // Reading integer input n

        int best1L = Math.min(Math.min(q * 4, h * 2), s);  // Calculating the best price for single liters
        int best2L = Math.min(d, best1L * 2);  // Calculating the best price for double liters

        if (n % 2 == 0) {  // Checking if the quantity n is even
            out.println(best2L * (n / 2));  // Printing the total cost for even n
        } else {  // If n is odd
            out.println(best2L * (n / 2) + best1L);  // Printing the total cost for odd n
        }

        out.close();  // Closing the PrintWriter object
    }
}

Translate the above Java code to C++ and end with comment "