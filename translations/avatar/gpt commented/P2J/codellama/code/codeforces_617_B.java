import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) == '1') {
                count++;
            }
        }
        if (count == 0) {
            System.out.println(0);
        } else {
            int product = 1;
            for (int i = 0; i < a.length(); i++) {
                if (a.charAt(i) == '0') {
                    product *= 2;
                }
            }
            System.out.println(product);
        }
    }
}

