public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the height and width of the rectangle,
        // as well as the height and width of the cut-out section.
        int h, w, hh, ww;

        // Read the height and width of the rectangle, and the height and width of the cut-out section from user input.
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        h = scanner.nextInt();
        w = scanner.nextInt();
        hh = scanner.nextInt();
        ww = scanner.nextInt();

        // Calculate the area of the remaining rectangle after the cut-out section
        // by subtracting the cut-out dimensions from the original dimensions.
        // The area is calculated as (remaining height) * (remaining width).
        System.out.println((h - hh) * (w - ww));

        // Return 0 to indicate that the program finished successfully.
    }
}
