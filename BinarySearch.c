#include <stdio.h>

int iterativeBinarySearch(int array[], int start_index, int end_index, int element)
{
    while (start_index <= end_index)
    {
        int middle = start_index + (end_index - start_index) / 2;
        if (array[middle] == element)
            return middle;
        if (array[middle] < element)
            start_index = middle + 1;
        else
            end_index = middle - 1;
    }
    
    return -1;
}
int main(void)
{
    int array[50], n, element;

    printf("Enter the length of an array: ");
    scanf("%d", &n);

    printf("Enter the elements of an array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("\nEnter the element you want to find: ");
    scanf("%d", &element);

    int found_index = iterativeBinarySearch(array, 0, n - 1, element);
    if (found_index == -1)
    {
        printf("\nElement not found in the array!!");
    }
    else
    {
        printf("\nElement found at index: %d", found_index);
    }

    printf("\n");
    return 0;
}