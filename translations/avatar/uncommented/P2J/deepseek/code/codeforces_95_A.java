import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int pya = Integer.parseInt(scanner.nextLine());
        ArrayList<String> arre = new ArrayList<>();

        while (pya > 0) {
            pya--;
            arre.add(scanner.nextLine().toLowerCase());
        }

        String oString = scanner.nextLine().toLowerCase();
        String lowString = oString.toLowerCase();
        char letter1 = scanner.nextLine().toLowerCase().charAt(0);
        char letter2 = letter1 == 'a' ? 'b' : 'a';
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
            char letter = letter1 == lowString.charAt(i) ? letter2 : letter1;
            oStringArray[i] = Character.isLowerCase(oString.charAt(i)) ? letter : Character.toUpperCase(letter);
        }

        for (char x : oStringArray) {
            System.out.print(x);
        }
        System.out.println();
    }
}
