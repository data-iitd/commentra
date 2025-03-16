import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = Integer.parseInt(scanner.nextLine());
        String[] vInput = scanner.nextLine().split(" ");
        int[] V = new int[N];
        for (int i = 0; i < N; i++) {
            V[i] = Integer.parseInt(vInput[i]);
        }
        
        String[] cInput = scanner.nextLine().split(" ");
        int[] C = new int[N];
        for (int i = 0; i < N; i++) {
            C[i] = Integer.parseInt(cInput[i]);
        }
        
        int[] list = new int[N + 1];
        list[0] = 0;
        int ans = 0;
        int X = 0;
        int Y = 0;
        
        for (int i = 0; i < N; i++) {
            if (V[i] - C[i] > 0) {
                X = V[i];
                Y = C[i];
                list[i + 1] = X - Y;
            }
        }
        
        for (int i = 1; i < list.length; i++) {
            ans += list[i];
        }
        
        System.out.println(ans);
        scanner.close();
    }
}
// <END-OF-CODE>
