public class Main {
    public static void main(String[] args) {
        int[] s = new int[10];
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        for (int i = 0; i < 10; i++) {
            s[i] = scanner.nextInt();
        }
        java.util.Arrays.sort(s);
        for (int i = 9; i > 6; i--) {
            System.out.println(s[i]);
        }
    }
}
