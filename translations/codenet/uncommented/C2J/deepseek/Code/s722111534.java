public class Main {
    public static void main(String[] args) {
        int hcell, wcell, hpaint, wpaint, nblack, nwhite;
        // 順にマス行、マス列、塗る行、塗る列、塗られたマス、白いマス
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
