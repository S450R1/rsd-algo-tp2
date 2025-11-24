#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

bool rechElets_TabNonTries(int * arr, int n, int x){
    for(int i = 0; i < n; i++){
        if(arr[i] == x) return true;
    }
    return false;
}

int main() {
    clock_t start, end;
    //Filling the array with user input
    int n;
    printf("Enter the number of elements (should be >= 2): ");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Invalid input.\n");
        return 1;
    }
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter %d numeric values:\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    //Searching for an element
    int x;
    printf("Enter the element to search for (unsorted array): ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    
    start = clock();
    bool found = rechElets_TabNonTries(arr, n, x);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Element %sfound. Time taken: %f seconds.\n", found ? "" : "not ", time_taken);

    free(arr);
    return 0;

}