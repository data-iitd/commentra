public class TimeConverter {
    public static void main(String[] args) {
        int in;
        int h, m, s;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        in = scanner.nextInt();

        h = in / 3600;
        in %= 3600;

        m = in / 60;
        in %= 60;

        s = in;

        System.out.println(h + ":" + m + ":" + s);
    }
}
