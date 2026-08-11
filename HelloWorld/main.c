#include <stdio.h>

/* 爬楼梯：每次可以爬 1 或 2 阶，求爬到第 n 阶有多少种方法 */
int climbStairs(int n)
{
    if (n <= 2) return n;

    int prev2 = 1; /* dp[i-2] */
    int prev1 = 2; /* dp[i-1] */
    int curr;

    for (int i = 3; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    printf("请输入楼梯阶数 n: ");
    scanf("%d", &n);

    int ways = climbStairs(n);
    printf("爬到第 %d 阶有 %d 种方法\n", n, ways);

    /* 打印 DP 前 10 阶的结果 */
    printf("\nDP 表 (1~10 阶):\n");
    for (int i = 1; i <= 10; i++)
        printf("n=%d: %d\n", i, climbStairs(i));

    return 0;
}
