#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int split_count = 0; // Added to count the number of splits

// Function to perform Ternary Search
int ternary_search(int search_number, int left, int right, int array[])
{
    while (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (array[mid1] == search_number)
        {
            return mid1;
        }
        if (array[mid2] == search_number)
        {
            return mid2;
        }

        if (search_number < array[mid1])
        {
            right = mid1 - 1;
        }
        else if (search_number > array[mid2])
        {
            left = mid2 + 1;
        }
        else
        {
            left = mid1 + 1;
            right = mid2 - 1;
        }

        split_count++; // Increment the split count
    }

    return -1; // Element not found
}

int main()
{
    int size_of_array;
    int search_number;

    srand(time(NULL));

    printf("Give the size of the random array: ");
    scanf("%d", &size_of_array);

    int *random_array = (int *)malloc(size_of_array * sizeof(int));

    if (random_array == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    random_array[0] = rand();

    printf("The random, sorted array is: \n");
    for (int i = 0; i < size_of_array; i++)
    {
        random_array[i] = random_array[i - 1] + rand();
        printf("random_array[%d] = %d\n", i, random_array[i]);
    }

    printf("Give the number you want to search: ");
    scanf("%d", &search_number);

    int result = ternary_search(search_number, 0, size_of_array - 1, random_array);

    if (result == -1)
    {
        printf("Target number '%d' not found.\n", search_number);
    }
    else
    {
        printf("Target number '%d' found at index %d.\n", search_number, result);
    }

    printf("Number of splits during search: %d\n", split_count);

    free(random_array);

    return 0;
}
