public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String S = scanner.next();
        String T = scanner.next();
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        String U = scanner.next();

        if (S.equals(U)) {
            A -= 1;
        } else if (T.equals(U)) {
            B -= 1;
        }

        System.out.println(A + " " + B);
    }
}
