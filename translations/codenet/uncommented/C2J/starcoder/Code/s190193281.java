import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n,S[] = new int[N],T[] = new int[Q],c=0;
    
    n = sc.nextInt();
    for(int i=0;i<n;i++){
      S[i] = sc.nextInt();
    }
    
    int q = sc.nextInt();
    for(int i=0;i<q;i++){
      T[i] = sc.nextInt();
      if(binarySearch(T[i])==1) c++;
    }
    System.out.println(c);
  }
  
  public static int binarySearch(int key){
    int left = 0,right = n,mid;
    while(left < right){
      mid = (left+right)/2;
      if(S[mid] == key) return 1;
      else if(key < S[mid]) right = mid;
      else left = mid+1;
    }
    return 0;
  }
}
