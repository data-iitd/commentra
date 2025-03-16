import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int c = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            // Read the line of integers
            while (scanner.hasNextInt()) {
                sum += scanner.nextInt();
                if (scanner.hasNextLine()) {
                    break; // Break if we reach the end of the line
                }
            }
            if (sum > 1) {
                c++;
            }
            scanner.nextLine(); // Move to the next line
        }
        System.out.println(c);
        scanner.close();
    }
}
// <END-OF-CODE>
