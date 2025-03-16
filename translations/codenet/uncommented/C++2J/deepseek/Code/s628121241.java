public class Main {
    public static int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int R = scanner.nextInt();
        if (R < 1200) System.out.println("ABC");
        else if (R >= 2800) System.out.println("AGC");
        else System.out.println("ARC");
    }
}
