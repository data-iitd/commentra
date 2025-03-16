import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int pya = Integer.parseInt(scanner.nextLine());
        List<String> arre = new ArrayList<>();
        
        while (pya > 0) {
            pya--;
            arre.add(scanner.nextLine().toLowerCase());
        }
        
        String oString = scanner.nextLine();
        String lowString = oString.toLowerCase();
        char letter1 = scanner.nextLine().charAt(0);
        letter1 = Character.toLowerCase(letter1);
        char letter2 = (letter1 != 'a') ? 'a' : 'b';
        
        boolean[] valid = new boolean[oString.length()];
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
            char letter = (lowString.charAt(i) != letter1) ? letter1 : letter2;
            oStringArray[i] = (Character.isLowerCase(oStringArray[i])) ? letter : Character.toUpperCase(letter);
        }
        
        for (char x : oStringArray) {
            System.out.print(x);
        }
        System.out.println();
        
        scanner.close();
    }
}
// <END-OF-CODE>
