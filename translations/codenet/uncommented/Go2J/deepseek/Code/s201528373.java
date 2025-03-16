public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        int tmpSum = 0;
        int rs = 0;
        for (int i = 0; i < n; i++) {
            tmpSum += l[i];
            if (tmpSum <= x) {
                rs = i + 1;
            } else {
                break;
            }
        }
        System.out.println(rs);
    }
}
