public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int height = scanner.nextInt();
        int width = scanner.nextInt();
        char[] inputStr = new char[width + 1];
        for (int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();
        for (int i = 0; i < height; i++) {
            String input = scanner.next();
            System.out.println("#" + input + "#");
        }
        for (int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();
    }
}
