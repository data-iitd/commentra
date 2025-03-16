
import java.util.Scanner;

class Process
{
    String name;
    int t;

    Process(String name, int t)
    {
        this.name = name;
        this.t = t;
    }
}

class Queue
{
    Process[] Q;
    int head, tail, n;

    Queue(int n)
    {
        this.Q = new Process[n + 1];
        this.head = 0;
        this.tail = 0;
        this.n = n;
    }

    void enqueue(Process x)
    {
        Q[tail] = x;
        tail = (tail + 1) % (n + 1);
    }

    Process dequeue()
    {
        Process x = Q[head];
        head = (head + 1) % (n + 1);
        return x;
    }

    int min(int a, int b)
    {
        return a < b ? a : b;
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        Queue q1 = new Queue(n);
        for (int i = 1; i <= n; i++)
        {
            String name = sc.next();
            int t = sc.nextInt();
            Process p = new Process(name, t);
            q1.enqueue(p);
        }
        int elaps = 0, c;
        while (q1.head != q1.tail)
        {
            Process u = q1.dequeue();
            c = q1.min(q, u.t);
            u.t -= c;
            elaps += c;
            if (u.t > 0)
                q1.enqueue(u);
            else
                System.out.println(u.name + " " + elaps);
        }
    }
}

