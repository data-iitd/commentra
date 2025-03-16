import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int height = scanner.nextInt();
        int width = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Print the top border
        for (int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();

        // Read and print each line with borders
        for (int i = 0; i < height; i++) {
            String inputStr = scanner.nextLine();
            System.out.println("#" + inputStr + "#");
        }

        // Print the bottom border
        for (int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();

        scanner.close();
    }
}

// <END-OF-CODE>
