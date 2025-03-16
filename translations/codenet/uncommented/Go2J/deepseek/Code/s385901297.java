public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int[] ns = new int[4];
        String[] input = scanner.nextLine().split(" ");
        for (int i = 0; i < 4; i++) {
            ns[i] = Integer.parseInt(input[i]);
        }

        java.util.Arrays.sort(ns);
        if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
