
int main()
{
    int h, a;
    scanf("%d %d", &h, &a);
    int sho = h / a;
    int am = h % a;
    if (am != 0)
    {
        sho++;
    }
    printf("%d", sho);
    return 0;
}

