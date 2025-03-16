import java.util.Scanner;

class CodeforcesTask397BSolution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            if (a % b == 0) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}
