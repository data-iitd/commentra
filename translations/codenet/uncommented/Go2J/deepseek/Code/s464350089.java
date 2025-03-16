public class Main {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int h = sc.nextInt();
        int n = sc.nextInt();
        int a = 0;

        for (int i = 0; i < n; i++) {
            a += sc.nextInt();
        }

        if (h > a) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}
