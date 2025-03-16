
int main()
{
    int A[4];
    int i;
    int sum = 0;

    for (i = 0; i < 4; i++)
    {
        scanf("%d", &A[i]);
    }

    if (A[1] <= A[2] || A[3] <= A[0])
    {
        printf("0");
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            sum += A[i];
        }
        printf("%d", sum);
    }

    return 0;
}

