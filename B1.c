#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void MaxEtMinA(int *arr, int n, int *max_out, int *min_out){
    int i;

    // Find maximum
    int mx = arr[0];
    for(i = 1; i < n; i++){
        if(arr[i] > mx) mx = arr[i];
    }

    // Find minimum
    int mn = arr[0];
    for(i = 1; i < n; i++){
        if(arr[i] < mn) mn = arr[i];
    }

    *max_out = mx;
    *min_out = mn;
}


int main() {
    clock_t start, end;
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

    printf("Enter %d numeric values (distinct values assumed):\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    int max_val = 0, min_val = 0;
    start = clock();
    MaxEtMinA(arr, n, &max_val, &min_val);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Maximum = %d\n", max_val);
    printf("Minimum = %d\n", min_val);
    printf("Execution time: %f seconds\n", time_taken);

    free(arr);
    return 0;
}

