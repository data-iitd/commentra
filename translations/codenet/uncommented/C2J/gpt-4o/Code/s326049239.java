import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (scanner.hasNextInt()) {
            int a = scanner.nextInt();
            int c = 0, k = 0;
            if (a < 3) {
                System.out.println("0");
            } else {
                int b = a;
                while (a-- > 0) {
                    b--;
                    c++;
                    if (c == 3) {
                        k++;
                        c = 0;
                    }
                }
                System.out.println(k);
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
