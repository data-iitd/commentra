import java.util.*;

public class McmSolver
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        if(n == 1){
            System.out.println(0);
            return;
        }
        ArrayList<TSize> Chain = new ArrayList<TSize>(n);
        for(int i = 0; i < n; ++i){
            Chain.add(new TSize(in.nextInt(), in.nextInt()));
        }
        TMcmSolver Solver = new TMcmSolver(Chain);
        System.out.println(Solver.Answer());
    }
}

class TSize
{
    int r;
    int c;
    TSize() : r(0), c(0) {}
    TSize(int Ar, int Ac)
     : r(Ar), c(Ac)
    {}
}

class TMcmSolver
{
    ArrayList<TSize> FChain;
    int[][] FMemo;

    static int Count(TSize Left, TSize Right)
    {
        return Left.r * Right.c * Left.c;
    }
    TMcmSolver(ArrayList<TSize> Chain)
     : FChain(Chain)
    {
        FMemo = new int[Chain.size()][Chain.size()];
    }
    int Solve(int s, int l)
    {
        assert(s <= l);
        if(s == l) return 0;
        if(FMemo[s][l]!= 0) return FMemo[s][l];
        if(s + 1 == l){
            FMemo[s][l] = Count(FChain.get(s), FChain.get(l));
        }else{
            int min = Integer.MAX_VALUE;
            for(int i = s; i < l; ++i){
                int c = Solve(s, i) + Count(new TSize(FChain.get(s).r, FChain.get(i).c), new TSize(FChain.get(i+1).r, FChain.get(l).c)) + Solve(i+1, l);
                min = Math.min(min, c);
            }
            FMemo[s][l] = min;
        }
        // System.out.println("Solve! [" + s + "], [" + l + "]"); 
        return FMemo[s][l];
    }
    int Answer()
    {
        return Solve(0, FMemo.length-1);
    }
}

