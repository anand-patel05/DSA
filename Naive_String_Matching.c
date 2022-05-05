#include <stdio.h>
#include <string.h>

int length_of_string(char x[50])
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
    char s[50], pat[50];
    int M, N;

    printf("----------Program to Implement Navie String Matching Algorithm----------\nEnter the string: ");
    gets(s);

    printf("\nEnter the pattern: ");
    gets(pat);

    M = length_of_string(pat);
    N = length_of_string(s);

    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
        {
            if (s[i + j] != pat[j])
            {
                break;
            }
        }
        if (j == M)
        {
            printf("Pattern matches at index: %d\n", i + 1);
        }
    }

    printf("\n");
    return 0;
}
















