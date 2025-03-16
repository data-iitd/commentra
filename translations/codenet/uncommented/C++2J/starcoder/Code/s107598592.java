import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] X = new int[N];
        int[] Y = new int[N];
        for(int i = 0; i < N; i++){
            X[i] = in.nextInt();
            Y[i] = X[i];
        }
        Arrays.sort(Y);
        int y = Y[N/2];
        for(int i = 0; i < N; i++){
            if(X[i] < y){
                System.out.println(y);
            }else{
                System.out.println(y - 1);
            }
            System.out.println();
        }
    }
}
