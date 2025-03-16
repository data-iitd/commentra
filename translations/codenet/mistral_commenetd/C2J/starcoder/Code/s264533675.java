
class HelloWorld
{
    public static void main(String[] args)
    {
        String str = new String(args[0]);
        str.replace(5, 6, " ");
        str.replace(13, 14, " ");
        System.out.println(str);
    }
}

