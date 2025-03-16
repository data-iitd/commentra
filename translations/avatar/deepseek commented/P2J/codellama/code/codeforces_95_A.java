
import java.util.Scanner;

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
        String letter1 = sc.next();
        String letter2 = "a".equals(letter1.toLowerCase()) ? "b" : "a";
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
        char[] oStringArray = oString.toCharArray();
        for (int i : setcito) {
            char letter = letter1.charAt(0) == oStringArray[i] ? letter2.charAt(0) : letter1.charAt(0);
            oStringArray[i] = Character.isLowerCase(oStringArray[i]) ? letter : Character.toUpperCase(letter);
        }
        for (char x : oStringArray) {
            System.out.print(x);
        }
        System.out.println();
    }
}

