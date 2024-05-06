#include <stdio.h>

int diagonalDifference(int n, int arr[n][n]) {
    int leftDiagonalSum = 0;
    int rightDiagonalSum = 0;

    for (int i = 0; i < n; i++) {
        leftDiagonalSum += arr[i][i];
        rightDiagonalSum += arr[i][n - 1 - i];
    }

    int difference = leftDiagonalSum - rightDiagonalSum;
        if (difference < 0) {
            difference = -difference;
        }
        return difference;
}

int main()
{
    int n;
    printf("Enter the number of Rows & Columns: ");
    scanf("%d", &n);
    int arr[n][n];
    for(int i = 0; i < n; i++){
      printf("Enter the row num #%d: ",i+1);
      for(int j = 0; j < n; j++){
          scanf("%d",&arr[i][j]);
          if(!(arr[i][j] > -100 && arr[i][j] < 100)){
            printf("Invalid input, Value must be bigger than -100 and smaller than 100 !\n");
            return 1;
          }
      }
    }

    printf("The diagonal difference is: %d",diagonalDifference(n, arr));

    return 0;
}
