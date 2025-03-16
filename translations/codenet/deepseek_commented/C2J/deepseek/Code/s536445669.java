public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        if (n % k == 0)
            System.out.println("0");
        else
            System.out.println("1");
    }
}
