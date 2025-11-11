#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    printf("enter numbers of elements ");
    scanf("%d", &n);

    int a[100];
    printf("Please enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    printf("\nThe largest number is: %d\n", max);

    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    printf("The smallest number is: %d\n", min);

    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    float avg = sum / n;
    printf("The average value is: %.2f\n", avg);

    printf("\nPrime numbers in the list: ");
    int primeCount = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            printf("%d ", a[i]);
            primeCount++;
        }
    }
    printf("\nTotal number of primes %d\n", primeCount);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nNumbers in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int V, k;
    printf("\nNew number to insert ");
    scanf("%d", &V);
    printf("Enter the position to insert it (0 to %d) ", n);
    scanf("%d", &k);

    if (k < 0 || k > n) {
        printf("Invalid position\n");
    } else {
        for (int i = n; i > k; i--) {
            a[i] = a[i - 1];
        }
        a[k] = V;
        n++;

        printf("Array after  %d at position %d:\n", V, k);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;
}
