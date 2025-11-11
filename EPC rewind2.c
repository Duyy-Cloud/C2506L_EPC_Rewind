//1 
#include <stdio.h>

int main() {
    int i = 1;
    while (i <= 10) {
        printf("%d ", i);
        i++;
    }
    return 0;
}

//2 

int main() {
    int a, b, sum = 0;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++) {
        sum += i;
    }

    printf("Sum from %d to %d = %d\n", a, b, sum);
    return 0;
}

//3 

int main () {
    int a,b, sum = 0;
    printf("Enter a and b:");
    scanf ("%d %d", &a, &b);
    for (int  i = a; i <=b; i++){
        if (i % 2 == 0)
        sum += i;
    }

    printf("Sum from %d to %d = %d\n" , a, b, sum);
    return 0;

}

//4

int main() {
    int n;
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    printf("divisors of %d : ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && i % 2 != 0)
            printf("%d ", i);
    }
    return 0;
}

//5 

int main() {
    int n;
    int i;
    int factorial = 1;

    printf("positive integer: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        factorial = factorial * i;
    }
    printf("The factorial of %d is %d\n", n, factorial);

    return 0;
}


//6 
int main() {
    int n, reversed = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    printf("Reversed number = %d\n", reversed);
    return 0;
}

//7 
int main() {
    int n, temp, reversed = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;

    while (temp != 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    if (reversed == n)
        printf("%d palindrome number\n", n);
    else
        printf("%d not a palindrome number\n", n);

    return 0;
}

//8 
int main() {
    int n;
    printf("height of the triangle ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

