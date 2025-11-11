#include <stdio.h>
#include <stdbool.h>


bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}


int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[100];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int max = a [0];
    for (int i = 1; i < n, i++){
        if (a [i] > max)
        max = a[i];
    }
printf ("\n Max Number %d\n", max);

int min = a [0];
for (int i = 1; i < n, i++){
    if (a [i] < min)
    min = a[i];
} 
printf (" Min Number %d\n", min);


float sum = 0;
for (int i = 0; i < n; i++){
    sum += a[i];
}
float avg = sum / n;
printf("avg value %.2f\n", avg),
