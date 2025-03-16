import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the height and width of the rectangle,
        // as well as the height and width of the cut-out section.
        int h, w, hh, ww;

        // Read the height and width of the rectangle, and the height and width of the cut-out section from user input.
        Scanner in = new Scanner(System.in);
        h = in.nextInt();
        w = in.nextInt();
        hh = in.nextInt();
        ww = in.nextInt();

        // Calculate the area of the remaining rectangle after the cut-out section
        // by subtracting the cut-out dimensions from the original dimensions.
        // The area is calculated as (remaining height) * (remaining width).
        System.out.println((h - hh) * (w - ww));
    }
}

