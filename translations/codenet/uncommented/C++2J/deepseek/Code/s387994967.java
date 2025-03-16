public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        if (A < 13 && A >= 6) {
            System.out.println(B / 2);
        }
        if (A < 6) {
            System.out.println(0);
        }
        if (A >= 13) {
            System.out.println(B);
        }
    }
}
