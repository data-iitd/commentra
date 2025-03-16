public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String S = scanner.next();
        scanner.close();

        boolean found = false;
        for (int i = 0; i < S.length() - 1; i++) {
            if (S.charAt(i) == 'A' && S.charAt(i + 1) == 'C') {
                found = true;
                break;
            }
        }

        if (found) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
