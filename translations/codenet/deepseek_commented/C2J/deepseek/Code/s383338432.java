public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int height = scanner.nextInt();
        int width = scanner.nextInt();
        scanner.nextLine();  // Consume the newline character after the integers
        char[] input_str = new char[width + 1];

        // Print the top border of the output
        for(int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();

        // Read and print each line of input with borders
        for(int i = 0; i < height; i++) {
            String line = scanner.nextLine();
            System.out.println("#" + line + "#");
        }

        // Print the bottom border of the output
        for(int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();
    }
}
