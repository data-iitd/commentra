
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare four integer variables: h, w, hh, and ww.
        int h, w, hh, ww;

        // Read four integers from the standard input and assign them to the variables h, w, hh, and ww respectively.
        Scanner in = new Scanner(System.in);
        h = in.nextInt();
        w = in.nextInt();
        hh = in.nextInt();
        ww = in.nextInt();

        // Calculate the difference between h and hh and the difference between w and ww.
        int difference_h = h - hh;
        int difference_w = w - ww;

        // Output the product of the differences to the standard output.
        System.out.println("The area of the rectangle is: " + difference_h * difference_w);
    }
}

