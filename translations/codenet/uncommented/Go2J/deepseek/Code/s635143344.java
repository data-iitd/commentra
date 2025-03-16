public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int[] in = new int[3];
        for (int i = 0; i < 3; i++) {
            in[i] = scanner.nextInt();
        }
        java.util.Arrays.sort(in);

        System.out.println(in[2] * 10 + in[1] + in[0]);
    }
}
