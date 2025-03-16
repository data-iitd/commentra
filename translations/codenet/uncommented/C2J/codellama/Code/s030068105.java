#include <stdio.h>
#include <stdlib.h>
public class Main {
  public static void main(String[] args) {
    int n;
    int[] data;
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    data = new int[n];
    for(int i=0; i<n; i++) data[i] = sc.nextInt();
    int max = 0, index;
    for(int i=0; i<n; i++) if(data[i] > max) {max = data[i];index=i;}
    int a = 0;
    for(int i=0; i<n; i++) if(i != index) a += data[i];
    if(a > max)System.out.println("Yes");
    else System.out.println("No");
  }
}
