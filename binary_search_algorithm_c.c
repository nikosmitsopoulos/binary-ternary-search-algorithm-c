#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int binary_search(int search_number, int lower_point, int size_of_array, int array[]){

    int counter = 1;
    while(lower_point <= size_of_array){// while the lower point is bigger than the search number

        int mid_point = lower_point + (size_of_array-lower_point)/2;

        // Check if size_of_array is present at any mid
        if(array[mid_point] == search_number)
        {   
            printf("The number of iterations is: %d\n", counter);
            return mid_point;
        }

        // Since size_of_array is not present at mid,
        if(array[mid_point] < search_number)
        {   
            lower_point = mid_point +1;
        }

        // Check in which region it is present
        else size_of_array = mid_point - 1;

        counter++;
    }
    printf("The number of iterations is: %d\n", counter);
    printf("\n");
    return 1;
}

/* main function to call above defined function */
int main () {

    
    int size_of_array;
    int search_number;

    srand(time(NULL));

    printf("\n");
    printf("Give the size of random array: ");
    scanf("%d", &size_of_array);
    printf("\n");
    
    // count the speed of the algorithm
    int count01 = log(size_of_array)/log(2);

    
    int random_array[size_of_array];
    
    // create the random array
    random_array[0] = rand();
	
    printf("The random, shrted array is: \n");
    printf("\n");
    for(int i = 0; i < size_of_array; i++ )
    {
        random_array[i + 1] = random_array[i] + rand();
        printf("random_array[%d] = %d\n", i, random_array[i]);
    }

    printf("\n");
    printf("Give the number you want to seatch: ");
    scanf("%d", &search_number);
    printf("\n");

    int res = binary_search(search_number,0,size_of_array-1,random_array);// call the function

    if(res == 1) printf("Target number '%d' not found.", search_number);// print the result of the function 
    else printf("Target number '%d' found.", search_number);

    printf("\n");
    printf("the speed of the algorithm: %d\n", count01);


    return 0;
}