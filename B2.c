#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void MaxEtMinB(int *arr, int n, int *max_out, int *min_out){
    int pairCount = n / 2;             // number of full pairs
    int *big = malloc(pairCount * sizeof(int));
    int *small = malloc(pairCount * sizeof(int));

    int k = 0;
    for (int i = 0; i < n - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            big[k] = arr[i];
            small[k] = arr[i + 1];
        } else {
            big[k] = arr[i + 1];
            small[k] = arr[i];
        }
        k++;
    }

    // Find minimum among small[]
    int mn = small[0];
    for (int i = 1; i < pairCount; i++) {
        if (small[i] < mn) mn = small[i];
    }

    // Find maximum among big[]
    int mx = big[0];
    for (int i = 1; i < pairCount; i++) {
        if (big[i] > mx) mx = big[i];
    }

    // If odd number of elements, handle the last element
    if (n % 2 == 1) {
        int last = arr[n - 1];
        if (last < mn) mn = last;
        if (last > mx) mx = last;
    }

    *max_out = mx;
    *min_out = mn;

    free(big);
    free(small);
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
    MaxEtMinB(arr, n, &max_val, &min_val);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Maximum = %d\n", max_val);
    printf("Minimum = %d\n", min_val);
    printf("Execution time: %f seconds\n", time_taken);

    free(arr);
    return 0;
}

