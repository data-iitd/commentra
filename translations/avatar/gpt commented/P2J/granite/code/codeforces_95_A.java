
import java.util.Scanner;

public class codeforces_95_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int pya = scanner.nextInt();
        String[] arre = new String[pya];
        for (int i = 0; i < pya; i++) {
            arre[i] = scanner.next().toLowerCase();
        }
        String oString = scanner.next();
        String lowString = oString.toLowerCase();
        String letter1 = scanner.next().toLowerCase();
        String letter2 = letter1.equals("a")? "b" : "a";
        int[] valid = new int[oString.length()];
        for (int i = 0; i < oString.length(); i++) {
            valid[i] = 0;
        }
        java.util.HashSet<Integer> setcito = new java.util.HashSet<>();
        for (String x : arre) {
            int wat = 0;
            while (true) {
                int index = lowString.indexOf(x, wat);
                if (index < 0) {
                    break;
                }
                for (int i = index; i < index + x.length(); i++) {
                    setcito.add(i);
                }
                wat = index + 1;
            }
        }
        char[] oStringArray = oString.toCharArray();
        for (int i : setcito) {
            char letter = letter1.charAt(0);
            if (lowString.charAt(i)!= letter1.charAt(0)) {
                letter = letter2.charAt(0);
            }
            if (Character.isLowerCase(oStringArray[i])) {
                oStringArray[i] = letter;
            } else {
                oStringArray[i] = Character.toUpperCase(letter);
            }
        }
        System.out.println(String.valueOf(oStringArray));
    }
}
