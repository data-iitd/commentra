public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.next();
        int a = -1, z = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A') {
                a = i;
                break;
            }
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == 'Z') {
                z = i;
                break;
            }
        }
        System.out.println(z - a + 1);
    }
}
