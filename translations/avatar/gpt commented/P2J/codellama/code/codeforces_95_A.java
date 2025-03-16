
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int pya = sc.nextInt();
        sc.nextLine();
        String[] arre = new String[pya];
        for (int i = 0; i < pya; i++) {
            arre[i] = sc.nextLine();
        }
        String oString = sc.nextLine();
        String lowString = oString.toLowerCase();
        char letter1 = sc.next().charAt(0);
        char letter2 = 'a';
        if (letter1 != 'a') {
            letter2 = 'b';
        }
        int[] valid = new int[oString.length()];
        for (int i = 0; i < oString.length(); i++) {
            valid[i] = 0;
        }
        for (int i = 0; i < arre.length; i++) {
            int wat = 0;
            while (true) {
                int index = lowString.indexOf(arre[i], wat);
                if (index < 0) {
                    break;
                }
                for (int j = index; j < index + arre[i].length(); j++) {
                    valid[j] = 1;
                }
                wat = index + 1;
            }
        }
        char[] oStringArray = oString.toCharArray();
        for (int i = 0; i < oStringArray.length; i++) {
            if (valid[i] == 1) {
                if (oStringArray[i] == Character.toLowerCase(oStringArray[i])) {
                    oStringArray[i] = letter1;
                } else {
                    oStringArray[i] = Character.toUpperCase(letter1);
                }
            } else {
                if (oStringArray[i] == Character.toLowerCase(oStringArray[i])) {
                    oStringArray[i] = letter2;
                } else {
                    oStringArray[i] = Character.toUpperCase(letter2);
                }
            }
        }
        for (int i = 0; i < oStringArray.length; i++) {
            System.out.print(oStringArray[i]);
        }
        System.out.println();
    }
}

