import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);  // Create a Scanner object
    int hcell, wcell, hpaint, wpaint, nblack, nwhite;  // Declare integer variables

    // Read the number of cells in the grid and the number of rows/columns to be painted
    hcell = sc.nextInt();
    wcell = sc.nextInt();
    hpaint = sc.nextInt();
    wpaint = sc.nextInt();

    // Calculate the number of black cells
    nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint);

    // Calculate the number of white cells
    nwhite = (hcell * wcell) - nblack;

    // Print the number of white cells
    System.out.println(nwhite);
  }
}
