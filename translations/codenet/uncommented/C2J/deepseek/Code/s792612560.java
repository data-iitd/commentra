public class Factorial {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        long m = n;
        n--;
        for (; n > 1; n--) {
            m *= n;
        }
        System.out.println(m);
    }
}
