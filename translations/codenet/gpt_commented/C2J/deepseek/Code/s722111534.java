public class Main {
    public static void main(String[] args) {
        // Declare variables for cell dimensions and paint dimensions
        int hcell, wcell, hpaint, wpaint, nblack, nwhite;

        // Create a Scanner object to read input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Input the dimensions of the grid (number of cells in height and width)
        // 順にマス行、マス列
        hcell = scanner.nextInt();
        wcell = scanner.nextInt();

        // Input the dimensions of the paint area (height and width of the painted area)
        // 塗る行、塗る列
        hpaint = scanner.nextInt();
        wpaint = scanner.nextInt();

        // Calculate the number of black cells painted
        // nblack = (width of the cells * height of the painted area) + (height of the cells * width of the painted area) - (area of the painted area)
        nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint);

        // Calculate the number of white cells remaining
        // Total cells - painted black cells
        nwhite = (hcell * wcell) - nblack;

        // Output the number of white cells
        System.out.println(nwhite);
    }
}
