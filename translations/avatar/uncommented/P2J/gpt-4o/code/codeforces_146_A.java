import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = Integer.parseInt(scanner.nextLine());
        String[] inputNumbers = scanner.nextLine().split(" ");
        int[] number = new int[n];
        
        for (int i = 0; i < n; i++) {
            number[i] = Integer.parseInt(inputNumbers[i]);
        }
        
        int h1 = 0;
        int h2 = 0;
        boolean isValid = true;
        
        for (int i = 0; i < n; i++) {
            if (number[i] != 4 && number[i] != 7) {
                System.out.println("NO");
                isValid = false;
                break;
            }
            if (i < n / 2) {
                h1 += number[i];
            } else {
                h2 += number[i];
            }
        }
        
        if (isValid) {
            if (h1 == h2) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
