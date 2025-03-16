
import java.util.*;
import java.lang.*;
import java.io.*;
class Ideone
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int P = sc.nextInt();
        int[] lis = new int[N];
        for(int i = 0; i < N; i++){
            lis[i] = sc.nextInt();
        }
        int[] ls = new int[N];
        for(int i = 0; i < N; i++){
            ls[i] = lis[i] % 2;
        }
        int one = 0;
        int zero = 0;
        for(int i = 0; i < N; i++){
            if(ls[i] == 1){
                one++;
            }
            else{
                zero++;
            }
        }
        int pattern_a = 0;
        int pattern_b = 0;
        for(int j = 0; j <= zero; j++){
            pattern_b += combi(zero, j);
        }
        int time = 0;
        while(time <= one){
            if(time % 2 == P){
                pattern_a += combi(one, time);
            }
            time++;
        }
        System.out.println(pattern_a * pattern_b);
    }
    public static int combi(int N, int K){
        int a = 1;
        for(int i = 0; i < K; i++){
            a *= N - i;
        }
        for(int j = 0; j < K; j++){
            a /= j + 1;
        }
        return a;
    }
}
