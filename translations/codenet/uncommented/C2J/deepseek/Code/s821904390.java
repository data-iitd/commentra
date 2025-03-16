public class TimeConverter {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int in = scanner.nextInt();

        int h = in / 3600;
        in %= 3600;

        int m = in / 60;
        in %= 60;

        int s = in;

        System.out.printf("%d:%d:%d\n", h, m, s);
    }
}
