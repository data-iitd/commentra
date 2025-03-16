public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        int X = scanner.nextInt();
        
        int cnt = 0;
        for (int a = 0; a <= A; a++) {
            for (int b = 0; b <= B; b++) {
                for (int c = 0; c <= C; c++) {
                    int total = 500*a + 100*b + 50*c;
                    if (total == X) cnt++;
                }
            }
        }
        System.out.println(cnt);
    }
}
