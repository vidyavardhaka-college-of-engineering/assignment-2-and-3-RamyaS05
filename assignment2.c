#include<stdio.h>
long long int assign(int n, int preference[][n])
{
    int mx = 1 << n;
    int i, j;
    int s;
    long long int dp[mx];
    dp[mx - 1] = 1;
    for (int mask = mx - 1; mask >= 0; mask--)
    {
        j = mask;
        s = 0;
        while (j)
        {
            s += (j & 1);
            j /= 2;
        }
        for (i = 0; i < n; i++)
        {
            if (preference[s][i] &&!(mask & (1 << i)))
            {
                dp[mask] += dp[mask | (1 << i)];
            }
        }
    }
    return dp[0];
}
int main()
{
    int i, n, j;
    printf("How many students are there?\n");
    scanf("%d", &n);
    int preference[n][n];
    printf("\nEnter the preferences of each of %d students for %d subjects\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &preference[i][j]);
        }
    }
    printf("\nTotal number of assignments that can be prepared are \n");
    printf("%lld\n", assign(n, preference));
    return 0;
}



