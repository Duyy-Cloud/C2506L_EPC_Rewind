
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

    printf("Enter your full name: ");
    fgets(full_name, sizeof(full_name), stdin);

   
    size_t len = strlen(full_name);
    if (len > 0 && full_name[len - 1] == '\n')
        full_name[len - 1] = '\0';

    normalize_name(full_name);

    printf("Normalized name: %s\n", full_name);
    return 0;
}
