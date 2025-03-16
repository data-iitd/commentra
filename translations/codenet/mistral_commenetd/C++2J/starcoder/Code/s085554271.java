
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Initialize I/O streams
        Scanner in = new Scanner(System.in);
        // Set precision for floating point numbers
        DecimalFormat df = new DecimalFormat("#.#########");

        int k, a, b; // Initialize variables a, b, and k
        k = in.nextInt();
        a = in.nextInt();
        b = in.nextInt();

        // Check if there exists an integer between a and b that is divisible by k
        for (int i = a; i <= b; ++i) {
            if(i%k==0){ // If current number is divisible by k
                System.out.println("OK"); // Print "OK" and exit the program
                return; // Exit the program with success status
            }
        }

        System.out.println("NG"); // If no number between a and b is divisible by k, print "NG"
    }
}

