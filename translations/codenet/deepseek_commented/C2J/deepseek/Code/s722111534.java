public class PaintCells {
    public static void main(String[] args) {
        int hcell, wcell, hpaint, wpaint, nblack, nwhite;

        // Read the number of cells in the grid and the number of rows/columns to be painted
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        hcell = scanner.nextInt();
        wcell = scanner.nextInt();
        hpaint = scanner.nextInt();
        wpaint = scanner.nextInt();

        // Calculate the number of black cells
        nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint);

        // Calculate the number of white cells
        nwhite = (hcell * wcell) - nblack;

        // Print the number of white cells
        System.out.println(nwhite);
    }
}
