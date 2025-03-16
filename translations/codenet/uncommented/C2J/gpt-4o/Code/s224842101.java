import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] count = new int[4];
        
        for (int i = 0; i < 4; i++) {
            count[i] = 0;
        }
        
        for (int i = 0; i < 3; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            count[a - 1]++;
            count[b - 1]++;
        }
        
        int s = 1;
        for (int i = 0; i < 4; i++) {
            s *= count[i];
        }
        
        if (s == 4) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
