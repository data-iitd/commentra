public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long x = scanner.nextLong();
        long s = (b / x - a / x);
        if (a % x == 0) s++;
        System.out.println(s);
    }
}
