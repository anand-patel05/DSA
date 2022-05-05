#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void findLCS(char *X, char *Y, int len_X, int len_Y)
{
    int L[len_X + 1][len_Y + 1];
    int r, c, i;

    for (r = 0; r <= len_X; r++)
    {

        for (c = 0; c <= len_Y; c++)
        {

            if (r == 0 || c == 0)
            {

                L[r][c] = 0;
            }
            else if (X[r - 1] == Y[c - 1])
            {

                L[r][c] = L[r - 1][c - 1] + 1;
            }
            else
            {

                L[r][c] = max(L[r - 1][c], L[r][c - 1]);
            }
        }
    }

    r = len_X;
    c = len_Y;
    i = L[r][c];

    char LCS[i + 1];
    LCS[i] = '\0';

    while (r > 0 && c > 0)
    {

        if (X[r - 1] == Y[c - 1])
        {

            LCS[i - 1] = X[r - 1];

            i--;
            r--;
            c--;
        }
        else if (L[r - 1][c] > L[r][c - 1])
        {

            r--;
        }
        else
        {

            c--;
        }
    }

    printf("\nThe Longest Common Subsequence is: %s\n", LCS);
    printf("The Length of the LCS is: %d\n", L[len_X][len_Y]);
}

int length_of_string(char x[])
{
    int length = 0;

    for (int i = 0; x[i] != '\0'; i++)
    {
        length++;
    }

    return length;
}

int main()
{
    char X[50], Y[30];
    int len_X = 0, len_Y = 0;

    printf("Enter the First String: ");
    gets(X);

    printf("Enter the Second String: ");
    gets(Y);

    len_X = length_of_string(X);
    len_Y = length_of_string(Y);

    findLCS(X, Y, len_X, len_Y);

    printf("\n");
    return 0;
}















