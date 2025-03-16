import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] fd = new int[6];
    double height;
    int i, j;

    while(n-- > 0){
      height = sc.nextDouble();
      if(height >= 185.0) fd[5]++;
      else if(height >= 180.0) fd[4]++;
      else if(height >= 175.0) fd[3]++;
      else if(height >= 170.0) fd[2]++;
      else if(height >= 165.0) fd[1]++;
      else fd[0]++;
    }

    for(i = 0;i < 6;i++){
      System.out.print(i + 1 + ":");
      for(j = 0;j < fd[i];j++)
        System.out.print("*");
      System.out.println();
    }
  }
}
