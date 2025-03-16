public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int h = scanner.nextInt();
        int r = scanner.nextInt();
        if (r > -h) {
            System.out.println("1");
        } else if (r == -h) {
            System.out.println("0");
        } else {
            System.out.println("-1");
        }
    }
}
