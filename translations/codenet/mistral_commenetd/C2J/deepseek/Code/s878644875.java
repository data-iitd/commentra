public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        char[] s = new char[4];
        char[] t = new char[4];
        String sInput = scanner.next();
        String tInput = scanner.next();
        int hit = 0;
        for (int i = 0; i < 3; i++) {
            if (sInput.charAt(i) == tInput.charAt(i)) hit++;
        }
        System.out.println(hit);
    }
}
