/*Write C program that:
Accepts an array of integers from the user.
Finds and displays the maximum and minimum values in the array. */

#include<stdio.h>

int main() {
    int n;

    // Accept the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Accept the array elements from the user
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0], min = arr[0];

    // Find the maximum and minimum values
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // Display the maximum and minimum values
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}
