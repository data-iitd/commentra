
import java.util.*;
import java.io.*;

class s466967233 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] A = new int[N+1];
        int[] B = new int[N+1];
        int now = 1;
        int cnt = 0;
        for(int i = 1; i <= N; i++){
            A[i] = sc.nextInt();
        }
        Arrays.fill(B, -1);
        B[1] = 0;
        for(int j = 1; j <= K; j++){
            //System.out.println(now + " -> " + A[now]);
            now = A[now];
            if(B[now] == -1){
                //System.out.println("未到達だった");
                B[now] = j;
            }else{
                //System.out.println("到達済みだった");
                //System.out.println("B[now] = " + B[now]);
                cnt = j;
                //System.out.println("cnt = " + cnt);
                break;
            }
        }
        if(j < K){
            int tmp;
            tmp = (K - B[now]) % (cnt -B[now]);
            //System.out.println("あと " + tmp + "回移動すればいい");
            //B[now]からtmp回ワープしたところが終着点
            for (int j = 0; j < tmp; j++)
            {
                now = A[now];
            }
        }
        System.out.println(now);
    }
}

