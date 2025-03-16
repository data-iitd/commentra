import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str;

        while (true) {
            str = scanner.next();
            if (str.equals("0")) break;
            int sum = 0;
            for (int i = 0; i < str.length(); i++) {
                String tmp = String.valueOf(str.charAt(i));
                int num = Integer.parseInt(tmp);
                sum += num;
            }
            System.out.println(sum);
        }
        scanner.close();
    }
}

// <END-OF-CODE>
