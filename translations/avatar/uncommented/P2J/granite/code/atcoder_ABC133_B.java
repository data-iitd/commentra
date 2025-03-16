
import java.util.*;
import java.lang.*;
import java.io.*;

class Ideone
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        int[][] points = new int[n][d];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < d; j++){
                points[i][j] = sc.nextInt();
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                double dist = 0;
                for(int k = 0; k < d; k++){
                    dist += Math.pow(points[i][k] - points[j][k], 2);
                }
                if(Math.sqrt(dist) == (int)Math.sqrt(dist)){
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}

Translate the above Python code to C++ and end with comment "