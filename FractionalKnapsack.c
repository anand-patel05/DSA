#include <stdio.h>

int main()
{
    int n, i, P[10], W[10], j, M, select[10];
    float PWR[10], temp, profit = 0.0;

    printf("Enter the capacity of bagpack: ");
    scanf("%d", &M); // accept Knapsack capacity

    printf("Enter number of items: ");
    scanf("%d", &n); //  accept no. of items

    printf("\nEnter profits of,\n");
    for (i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &P[i]); // accept profit of item
    }

    printf("\nEnter weights of,\n");
    for (i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &W[i]); // accept weight of item
    }

    for (i = 0; i < n; i++)
        PWR[i] = P[i] * 1.0 / W[i]; // calculate P/W ratio

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (PWR[i] < PWR[j]) // Sorting the P/W ratio in descending order
            {
                temp = PWR[i];
                PWR[i] = PWR[j];
                PWR[j] = temp;

                temp = P[i];
                P[i] = P[j];
                P[j] = temp;

                temp = W[i];
                W[i] = W[j];
                W[j] = temp;
            }
        }
    }
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%d ", P[i]); //profit
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%d ", W[i]); //weigt
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%.2f ", PWR[i]); //ratio

    int c = 0; //
    for (i = 0; i < n; i++)
    {
        if (M > 0 && W[i] <= M)
        {
            select[c++] = i;
            M = M - W[i];
            profit = profit + P[i] * 1.0;
        } // -----------Logic------------
        else
            break;
    }
    printf("\n\nSelected items: ");
    for (i = 0; i < c; i++)
        printf("%d --> ", select[i] + 1);
    if (M > 0)
    {
        profit = profit + P[i] * (M * 1.0 / W[i]);
        select[c++] = i;
    }

    printf("%d * %.2f", select[i] + 1, M * 1.0 / W[i]);
    printf("\nProfit = %.2f\n", profit); //
    return 0;
}