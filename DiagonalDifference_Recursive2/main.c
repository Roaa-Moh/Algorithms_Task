#include <stdio.h>

int diagonalDifferenceRecursive(int n, int arr[n][n], int i, int leftDiagonalSum, int rightDiagonalSum) {
    if (i == -1) {
        int difference = leftDiagonalSum - rightDiagonalSum;
        // Make sure the difference is positive
        if (difference < 0) {
            difference = -difference;
        }
        return difference;
    }

    leftDiagonalSum += arr[i][i];
    rightDiagonalSum += arr[i][n - 1 - i];
    return diagonalDifferenceRecursive(n, arr, i - 1, leftDiagonalSum, rightDiagonalSum);
}

int main() {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int arr[n][n];

    // Input the matrix
     printf("\nEnter the elements of the square matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] < -100 || arr[i][j] > 100) {
                printf("Invalid input: Element at row %d, column %d is out of range[-100,100].\n", i + 1, j + 1);
                return 1;
            }
        }
    }

    printf("\nThe absolute difference between the sums of the diagonals is: %d\n", diagonalDifferenceRecursive(n, arr, n-1, 0, 0));

    return 0;
}

