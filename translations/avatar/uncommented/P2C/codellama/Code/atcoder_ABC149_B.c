
int main()
{
    int cookies[3];
    int leftOver;
    int takahashi;
    scanf("%d %d %d", &cookies[0], &cookies[1], &cookies[2]);
    leftOver = cookies[0] - cookies[2];
    takahashi = max(0, leftOver);
    printf("%d %d\n", takahashi, (takahashi > 0 ? cookies[1] : max(0, cookies[1] - abs(leftOver))));
    return 0;
}

