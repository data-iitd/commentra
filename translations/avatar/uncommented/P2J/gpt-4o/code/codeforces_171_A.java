import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] parts = input.split(" ");
        String a = parts[0];
        String b = parts[1];

        int x = Math.max(a.length(), b.length());
        a = String.format("%" + x + "s", a).replace(' ', '0');
        b = String.format("%-" + x + "s", b).replace(' ', '0');

        StringBuilder s = new StringBuilder();
        int c = 0;

        for (int i = 0; i < x; i++) {
            int d = Character.getNumericValue(b.charAt(i)) + Character.getNumericValue(a.charAt(x - i - 1)) + c;
            if (d > 9) {
                s.append(d % 10);
                c = 1;
            } else {
                s.append(d);
                c = 0;
            }
        }

        if (c == 1) {
            s.append('1');
        }

        System.out.println(Integer.parseInt(s.reverse().toString()));
    }
}
//<END-OF-CODE>
