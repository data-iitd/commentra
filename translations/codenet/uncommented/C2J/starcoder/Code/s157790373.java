import java.util.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    int n, A[] = new int[LEN];
    int q, M;
    int i, j, k;

    n = in.nextInt();
    for(i=0; i<n; i++)A[i] = in.nextInt();

    q = in.nextInt();
    for(i=0; i<q; i++)
      {
        M = in.nextInt();
        flag=FALSE;

        solve(-1, M);
        if(flag==TRUE)System.out.println("yes");
        else System.out.println("no");
      }
  }

  public static int solve(int i, int m)
  {
    if(i>n)return FALSE;
    else if(m<0)return FALSE;
    else if(m==0 || m-A[i+1]==0)
      {
        flag=TRUE;
        return TRUE;
      }
    else
      {
        //not use A[i]
        solve(i+1, m);
        //use A[i]
        solve(i+1, m-A[i]);
      }
  }
}

