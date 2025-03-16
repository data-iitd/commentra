
import java.util.Scanner;

public class s391054810{
  public static void main(String[] args) {
    // Declare variables to hold the height and width of the rectangle,
    // as well as the height and width of the cut-out section.
    int h, w, hh, ww;

    // Create a Scanner object to read user input.
    Scanner scanner = new Scanner(System.in);

    // Read the height and width of the rectangle, and the height and width of the cut-out section from user input.
    h = scanner.nextInt();
    w = scanner.nextInt();
    hh = scanner.nextInt();
    ww = scanner.nextInt();

    // Calculate the area of the remaining rectangle after the cut-out section
    // by subtracting the cut-out dimensions from the original dimensions.
    // The area is calculated as (remaining height) * (remaining width).
    int area = (h - hh) * (w - ww);

    // Print the calculated area to the console.
    System.out.println(area);

    // Close the Scanner object to release system resources.
    scanner.close();
  }
}
