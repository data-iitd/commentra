import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Set output format to fixed-point notation with 10 decimal places
        System.out.printf("%.10f\n", 1.0);
        // Read strings from standard input until EOF
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            String in = sc.nextLine();
            // Output the string
            System.out.println(in);
        }
    }
}

