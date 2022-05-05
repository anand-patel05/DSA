#include <stdio.h>

int max, min;
int a[100];

void maxmin(int i, int j)
{
    int max1, min1, mid;
    if (i == j)
    {
        max = min = a[i];
    }
    else
    {
        if (i == j - 1)
        {
            if (a[i] < a[j])
            {
                max = a[j];
                min = a[i];
            }

            else
            {
                max = a[i];
                min = a[j];
            }
        }
        else
        {
            mid = (i + j) / 2;
            maxmin(i, mid);
            max1 = max;
            min1 = min;
            maxmin(mid + 1, j);
            if (max < max1)
            {
                max = max1;
            }
        }
        if (min > min1)
        {
            min = min1;
        }
    }
}

int main()
{
    int num;
    printf("\n--------Max-Min Algorithm using Divide and Conquer Approach--------\n\n");
    printf("Enter the total count of numbers : ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter the value of %d element: ", i + 1);
        scanf("%d", &a[i]);
    }

    max = a[0];
    min = a[0];
    maxmin(1, num);

    printf("\nThe Minimum Element of an array is: %d\n", min);
    printf("The Maximum Element of an array is: %d\n", max);
    return 0;
}