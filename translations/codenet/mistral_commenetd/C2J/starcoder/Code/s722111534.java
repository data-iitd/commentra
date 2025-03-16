import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int hcell, wcell, hpaint, wpaint, nblack, nwhite;

        hcell = sc.nextInt();
        wcell = sc.nextInt();
        hpaint = sc.nextInt();
        wpaint = sc.nextInt();

        nblack = (wcell*hpaint) + (hcell*wpaint) - (hpaint * wpaint);
        nwhite = (hcell*wcell) - nblack;

        System.out.println(nwhite);
    }
}

