
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int candeleIntere = scan.nextInt();
        int b = scan.nextInt();
        int s = 0;
        int restoSciolte = 0;
        while (candeleIntere > 0 || restoSciolte >= b) {
            candeleIntere += restoSciolte / b;
            restoSciolte %= b;
            s += candeleIntere;
            restoSciolte += candeleIntere % b;
            candeleIntere /= b;
        }
        System.out.println(s);
    }
}

