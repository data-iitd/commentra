
int main()
{
    int n, i, sum = 0;
    scanf("%d", &n);
    int list[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
        sum += list[i] % 2;
    }
    if (sum == 1)
    {
        for (i = 0; i < n; i++)
        {
            if (list[i] == 1)
            {
                printf("%d", i + 1);
                break;
            }
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (list[i] == 0)
            {
                printf("%d", i + 1);
                break;
            }
        }
    }
    return 0;
}
