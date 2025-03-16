public class Main {
    public static void main(String[] args) {
        int i, a, b, s;
        int[] count = new int[4];
        for(i = 0; i < 4; i++) count[i] = 0;
        for(i = 0; i < 3; i++) {
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            a = scanner.nextInt();
            b = scanner.nextInt();
            count[a - 1]++;
            count[b - 1]++;
        }
        s = 1;
        for(i = 0; i < 4; i++) s *= count[i];
        if(s == 4) System.out.println("YES");
        else System.out.println("NO");
    }
}
