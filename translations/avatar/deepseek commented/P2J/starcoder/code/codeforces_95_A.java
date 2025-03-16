
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int pya = sc.nextInt();
        String[] arre = new String[pya];
        for (int i = 0; i < pya; i++) {
            arre[i] = sc.next();
        }
        String oString = sc.next();
        String lowString = oString.toLowerCase();
        String letter1 = sc.next().toLowerCase();
        String letter2 = "a" + (letter1.equals("a")? "b" : "");
        int[] valid = new int[oString.length()];
        Set<Integer> setcito = new HashSet<>();
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
        char[] oStringArr = oString.toCharArray();
        for (int i : setcito) {
            char letter = letter1.equals(lowString.charAt(i))? letter1.charAt(0) : letter2.charAt(0);
            oStringArr[i] = Character.isLowerCase(oStringArr[i])? letter : Character.toUpperCase(letter);
        }
        for (char x : oStringArr) {
            System.out.print(x);
        }
        System.out.println();
    }
}

