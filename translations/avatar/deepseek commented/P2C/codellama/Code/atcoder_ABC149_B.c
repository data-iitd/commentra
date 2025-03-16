
int main()
{
    int cookies[3];
    int leftOver;
    int takahashi;
    int aoki;
    scanf("%d %d %d", &cookies[0], &cookies[1], &cookies[2]);
    leftOver = cookies[0] - cookies[2];
    takahashi = max(0, leftOver);
    aoki = max(0, cookies[1] - abs(leftOver));
    printf("%d %d", takahashi, aoki);
    return 0;
}
