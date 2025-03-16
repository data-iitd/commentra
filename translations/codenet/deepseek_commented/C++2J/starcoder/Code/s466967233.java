import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] A = new int[N+1];
        int[] B = new int[200100];
        for(int i = 0; i < N; i++){
            A[i+1] = sc.nextInt();
        }
        for(int i = 0; i < 200100; i++){
            B[i] = -1;
        }
        B[1] = 0;
        int now = 1;
        int cnt = 0;
        for(int j = 1; j <= K; j++){
            now = A[now];
            if(B[now] == -1){
                B[now] = j;
            }else{
                cnt = j;
                break;
            }
        }
        if(j < K){
            int tmp = (K - B[now]) % (cnt - B[now]);
            for(int j = 0; j < tmp; j++){
                now = A[now];
            }
        }
        System.out.println(now);
    }
}
