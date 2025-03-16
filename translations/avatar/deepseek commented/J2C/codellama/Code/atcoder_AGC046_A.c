
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create a FastReader object to read input
    FastReader sc = new FastReader();
    // Create a PrintWriter object to write output
    PrintWriter pw = new PrintWriter(System.out);

    // Read an integer input
    int x = sc.nextInt();
    // Initialize a counter to keep track of the number of iterations
    int count = 0;
    // Store the initial value of x in a temporary variable
    int tmp = x;

    // Initialize x to 0 to start the loop
    x = 0;

    // Loop until x becomes 360
    while (x != 360)
    {
        // Increment x by tmp
        x = x + tmp;
        // If x exceeds 360, adjust it by subtracting 360
        if (x > 360)
        {
            x = x - 360;
        }
        // Increment the counter
        count++;
    }

    // Print the final count
    System.out.println(count);

    // End of code
    return 0;
}

class FastReader
{
    BufferedReader br;
    StringTokenizer st;

    public FastReader()
    {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next()
    {
        while (st == null || !st.hasMoreElements())
        {
            try
            {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt()
    {
        return Integer.parseInt(next());
    }

    long nextLong()
    {
        return Long.parseLong(next());
    }

    double nextDouble()
    {
        return Double.parseDouble(next());
    }

    String nextLine()
    {
        String str = "";
        try
        {
            str = br.readLine();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        return str;
    }
}

class PrintWriter
{
    PrintWriter(OutputStream out)
    {
        // TODO: Implement this method
    }

    void println(int x)
    {
        // TODO: Implement this method
    }

    void println(long x)
    {
        // TODO: Implement this method
    }

    void println(double x)
    {
        // TODO: Implement this method
    }

    void println(String x)
    {
        // TODO: Implement this method
    }
}

class System
{
    static PrintWriter out;

    static PrintWriter getOut()
    {
        // TODO: Implement this method
        return null;
    }

    static void println(int x)
    {
        // TODO: Implement this method
    }

    static void println(long x)
    {
        // TODO: Implement this method
    }

    static void println(double x)
    {
        // TODO: Implement this method
    }

    static void println(String x)
    {
        // TODO: Implement this method
    }
}

class InputStreamReader
{
    InputStreamReader(InputStream in)
    {
        // TODO: Implement this method
    }
}

class BufferedReader
{
    BufferedReader(InputStreamReader in)
    {
        // TODO: Implement this method
    }

    String readLine()
    {
        // TODO: Implement this method
        return null;
    }
}

class IOException
{
    IOException()
    {
        // TODO: Implement this method
    }
}

class StringTokenizer
{
    StringTokenizer(String str)
    {
        // TODO: Implement this method
    }

    boolean hasMoreElements()
    {
        // TODO: Implement this method
        return false;
    }

    String nextToken()
    {
        // TODO: Implement this method
        return null;
    }
}

class Integer
{
    static int parseInt(String str)
    {
        // TODO: Implement this method
        return 0;
    }
}

class Long
{
    static long parseLong(String str)
    {
        // TODO: Implement this method
        return 0;
    }
}

class Double
{
    static double parseDouble(String str)
    {
        // TODO: Implement this method
        return 0;
    }
}

class OutputStream
{
    OutputStream()
    {
        // TODO: Implement this method
    }
}

class InputStream
{
    InputStream()
    {
        // TODO: Implement this method
    }
}

