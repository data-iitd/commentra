import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] parts = input.split(" ");
        int[] ABC = new int[parts.length];
        
        for (int i = 0; i < parts.length; i++) {
            ABC[i] = Integer.parseInt(parts[i]);
        }
        
        int countOfFive = 0;
        int sum = 0;
        
        for (int num : ABC) {
            if (num == 5) {
                countOfFive++;
            }
            sum += num;
        }
        
        if (countOfFive == 2) {
            System.out.println(sum == 17 ? "YES" : "NO");
        } else {
            System.out.println("NO");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
