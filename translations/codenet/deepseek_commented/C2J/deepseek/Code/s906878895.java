public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextInt()) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int x = a + b;
            int w = 0;
            while (x != 0) {
                w++;
                x /= 10;
            }
            System.out.println(w);
        }
    }
}
