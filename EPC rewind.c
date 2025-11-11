#include <stdio.h>

    //1 
int main() {
    int N, year, a, b, c;
    char ch, op;

    printf("Enter N: ");
    scanf("%d", &N);
    if (N % 2 == 0)
        printf("1\n");
    else
        printf("0\n");

    //2
    printf("Enter N: ");
    scanf("%d", &N);
    if (N % 3 == 0 && N % 5 == 0)
        printf("1\n");
    else
        printf("0\n");
    //3
    printf("Enter N: ");
    scanf("%d", &N);
    if (N >= 30 && (N % 2 == 0 || N % 3 == 0 || N % 5 == 0))
        printf("1\n");
    else
        printf("0\n");
    //4
    printf("Enter N: ");
    scanf("%d", &N);
    if (N < 10 || N > 20)
        printf("1\n");
    else
        printf("0\n");
    //5
    printf("Enter year: ");
    scanf("%d", &year);
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        printf("YES\n");
    else
        printf("NO\n");
        //6
    printf("Enter three sides (a b c): ");
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c)
        printf("1\n");
    else if (a == b || b == c || a == c)
        printf("2\n");
    else if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
        printf("3\n");
    else
        printf("4\n");

        //7
    printf("Enter a character: ");
    scanf(" %c", &ch);
    if (ch >= 'A' && ch <= 'Z')
        printf("Uppercase\n");
    else if (ch >= 'a' && ch <= 'z')
        printf("Lowercase\n");
    else
        printf("Not a letter\n");
//8
    printf("Enter a character: ");
    scanf(" %c", &ch);
    if (ch >= 'A' && ch <= 'Z')
        ch = ch + 32;
    else if (ch >= 'a' && ch <= 'z')
        ch = ch - 32;
    printf("%c\n", ch);
//9
    printf("Enter a character: ");
    scanf(" %c", &ch);
    if (ch >= 'a' && ch <= 'z')
        printf("%c\n", ch - 32);
    else if (ch >= 'A' && ch <= 'Z')
        printf("%c\n", ch);
    else
        printf("Error\n");
//10
    printf("Enter a, b and operator (+, -, *, /): ");
    scanf("%d %d %c", &a, &b, &op);
    if (op == '+')
        printf("%d + %d = %d\n", a, b, a + b);
    else if (op == '-')
        printf("%d - %d = %d\n", a, b, a - b);
    else if (op == '*')
        printf("%d * %d = %d\n", a, b, a * b);
    else if (op == '/')
    {
        if (b != 0)
            printf("%d / %d = %d\n", a, b, a / b);
        else
            printf("Error\n");
    }
    else
        printf("Invalid operator\n");

    return 0;
}
