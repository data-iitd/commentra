
public class Main {
  public static void main(String[] args) {
    int hcell, wcell, hpaint, wpaint, nblack, nwhite;

    // Declare and initialize variables for the height and width of the grid,
    // the number of rows and columns to be painted with black and white respectively

    Scanner sc = new Scanner(System.in);

    // Create a Scanner object to read input from the console

    hcell = sc.nextInt();
    wcell = sc.nextInt();

    // Read the height and width of the grid from the user

    hpaint = sc.nextInt();
    wpaint = sc.nextInt();

    // Read the number of rows and columns to be painted with black and white respectively

    nblack = (wcell*hpaint) + (hcell*wpaint) - (hpaint * wpaint);

    // Calculate the number of black painted cells by multiplying the number of columns and rows to be painted with black,
    // then multiplying the height and width of the grid and subtracting the product of the number of rows and columns to be painted with black and the number of columns and rows to be painted with white

    nwhite = (hcell*wcell) - nblack;

    // Calculate the number of white unpainted cells by subtracting the number of black painted cells from the total number of cells in the grid

    System.out.println(nwhite);

    // Print the number of white unpainted cells to the console

    sc.close();

    // Close the Scanner object
  }
}

