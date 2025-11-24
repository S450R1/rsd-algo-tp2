#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

bool rechElets_Dicho(int * arr, int n, int x){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == x) return true;
        else if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
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
    printf("Enter the element to search for (sorted array, binary search): ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    
    start = clock();
    bool found = rechElets_Dicho(arr, n, x);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Element %sfound. Time taken: %f seconds.\n", found ? "" : "not ", time_taken);

    free(arr);
    return 0;

}