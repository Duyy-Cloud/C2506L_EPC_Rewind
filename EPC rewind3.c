
//POINTER, ARRAY 

#include <stdio.h>

void add10(int *p) {
    *p += 10;
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main() {
    int a, b, *p;

    printf("Enter a: ");
    scanf("%d", &a);

    p = &a;

    printf("\n&a = %p\np = %p\n", &a, p);
    printf("a = %d, *p = %d\n", a, *p);

    *p = 100;
    printf("\nAfter pointer update: a = %d\n", a);

    add10(p);
    printf("After adding 10: a = %d\n", a);

    printf("\nEnter b: ");
    scanf("%d", &b);

    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}

///


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



//STRING, STRTOK, STRCAT, POINTER
#include <stdio.h>

int main() {
    char str[100];  

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  

    printf("Output: %s", str);

    return 0;
}


#include <stdio.h>
#include <ctype.h>  

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("\nUppercase: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", toupper(str[i]));
    }

    printf("\nLowercase: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", tolower(str[i]));
    }

    return 0;
}

//

#include <stdio.h>
#include <string.h> 

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    printf("Reversed string: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");
    return 0;
}



///// 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void normalize_name(char *name) {
    char word[50];
    char result[200] = "";
    int index = 0;

    while (sscanf(name + index, "%s", word) == 1) {
       
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        
        word[0] = toupper(word[0]);

        strcat(result, word);
        strcat(result, " ");

        
        while (name[index] && !isspace(name[index])) index++;
        while (name[index] && isspace(name[index])) index++;
    }

    
    int len = strlen(result);
    if (len > 0 && result[len - 1] == ' ')
        result[len - 1] = '\0';

    strcpy(name, result);
}

int main() {
    char full_name[200];

    printf("full name: ");
    fgets(full_name, sizeof(full_name), stdin);

   
    size_t len = strlen(full_name);
    if (len > 0 && full_name[len - 1] == '\n')
        full_name[len - 1] = '\0';

    normalize_name(full_name);

    printf("Normalized name: %s\n", full_name);
    return 0;
}
