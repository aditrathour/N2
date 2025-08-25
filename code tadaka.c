#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for ascending order sorting
int compareAscending(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to compare integers for descending order sorting
int compareDescending(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Function to remove duplicates from the list and print unique values
int removeDuplicates(int arr[], int n) {
    int uniqueIndex = 0;
    
    // Traverse through the list to remove duplicates
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < uniqueIndex; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            arr[uniqueIndex++] = arr[i];  // Add the unique element to the new array
        }
    }
    
    return uniqueIndex; // Return the new size of the array
}

int main() {
    int n;
    
    // Accept the number of elements in the list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Accept the list of integers from the user
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 1. Find and print the sum of all even numbers
    int evenSum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evenSum += arr[i];
        }
    }
    printf("Sum of even numbers: %d\n", evenSum);

    // 2. Find and print the sum of all odd numbers
    int oddSum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            oddSum += arr[i];
        }
    }
    printf("Sum of odd numbers: %d\n", oddSum);

    // 3. Sort the list in ascending order and print it
    qsort(arr, n, sizeof(int), compareAscending);
    printf("List in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 4. Sort the list in descending order and print it
    qsort(arr, n, sizeof(int), compareDescending);
    printf("List in descending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 5. Remove duplicates and print the unique values
    int uniqueSize = removeDuplicates(arr, n);
    printf("Unique values in the list: ");
    for (int i = 0; i < uniqueSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
