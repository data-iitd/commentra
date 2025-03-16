import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] list = new int[n];
        
        for (int i = 0; i < n; i++) {
            list[i] = scanner.nextInt() % 2;
        }
        
        int sum = 0;
        for (int value : list) {
            sum += value;
        }
        
        if (sum == 1) {
            for (int i = 0; i < n; i++) {
                if (list[i] == 1) {
                    System.out.println(i + 1);
                    break;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (list[i] == 0) {
                    System.out.println(i + 1);
                    break;
                }
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
