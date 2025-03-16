import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args) {
        // Read input from stdin
        Scanner in = new Scanner(System.in);
        long a = in.nextLong();
        long b = in.nextLong();
        long x = in.nextLong();

        // Calculate the difference between the number of complete x-blocks in b and a
        long s = (b/x - a/x);

        // If a is a multiple of x, then the last x-block in a is complete, so add 1 to the result
        if(a%x == 0) s++;

        // Print the result to stdout
        System.out.println(s);
    }
}
