public class PaintGrid {
    public static void main(String[] args) {
        int hcell, wcell, hpaint, wpaint, nblack, nwhite;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        hcell = scanner.nextInt();
        wcell = scanner.nextInt();
        hpaint = scanner.nextInt();
        wpaint = scanner.nextInt();

        nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint);
        nwhite = (hcell * wcell) - nblack;

        System.out.println(nwhite);
    }
}
