
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    int id;
    char name[50];
    char gender[10];
    float math, physics, chemistry;
} Student;

Student s[MAX];
int n = 0;

float getGPA(Student st)
{
    return (st.math + st.physics + st.chemistry) / 3;
}

void inputAll()
{
    printf("Number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Gender: ");
        scanf("%s", s[i].gender);
        printf("Math Physics Chemistry: ");
        scanf("%f %f %f", &s[i].math, &s[i].physics, &s[i].chemistry);
    }
}

void printAll()
{
    for (int i = 0; i < n; i++)
    {
        printf("ID:%d | Name:%s | Gender:%s | GPA:%.2f\n",
               s[i].id, s[i].name, s[i].gender, getGPA(s[i]));
    }
}

void highestGPA()
{
    float max = getGPA(s[0]);
    for (int i = 1; i < n; i++)
        if (getGPA(s[i]) > max)
            max = getGPA(s[i]);
    printf("Highest GPA = %.2f\n", max);
    for (int i = 0; i < n; i++)
        if (getGPA(s[i]) == max)
            printf("ID:%d Name:%s GPA:%.2f\n", s[i].id, s[i].name, getGPA(s[i]));
}

void lowestGPA()
{
    float min = getGPA(s[0]);
    for (int i = 1; i < n; i++)
        if (getGPA(s[i]) < min)
            min = getGPA(s[i]);
    printf("Lowest GPA = %.2f\n", min);
    for (int i = 0; i < n; i++)
        if (getGPA(s[i]) == min)
            printf("ID:%d Name:%s GPA:%.2f\n", s[i].id, s[i].name, getGPA(s[i]));
}

void findId123()
{
    for (int i = 0; i < n; i++)
        if (s[i].id == 123)
        {
            printf("Found ID=123: %s GPA=%.2f\n", s[i].name, getGPA(s[i]));
            return;
        }
    printf("No student with ID=123\n");
}

void findNameNam()
{
    int found = 0;
    for (int i = 0; i < n; i++)
        if (strcmp(s[i].name, "Nam") == 0)
        {
            printf("Found Nam -> ID:%d GPA:%.2f\n", s[i].id, getGPA(s[i]));
            found = 1;
        }
    if (!found)
        printf("No student named Nam\n");
}

void sortByGPA()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (getGPA(s[i]) < getGPA(s[j]))
            {
                Student tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
    printf("Sorted by GPA (descending):\n");
    printAll();
}

void updateId123()
{
    for (int i = 0; i < n; i++)
        if (s[i].id == 123)
        {
            printf("Update student 123:\n");
            printf("Name: ");
            scanf("%s", s[i].name);
            printf("Gender: ");
            scanf("%s", s[i].gender);
            printf("Math Physics Chemistry: ");
            scanf("%f %f %f", &s[i].math, &s[i].physics, &s[i].chemistry);
            return;
        }
    printf("No student with ID=123\n");
}

void deleteId123()
{
    for (int i = 0; i < n; i++)
        if (s[i].id == 123)
        {
            for (int j = i; j < n - 1; j++)
                s[j] = s[j + 1];
            n--;
            printf("Deleted student ID=123\n");
            return;
        }
    printf("No student with ID=123\n");
}

void insertAt()
{
    int pos;
    printf("Insert position: ");
    scanf("%d", &pos);
    if (pos < 0)
        pos = 0;
    if (pos > n)
        pos = n;
    for (int i = n; i > pos; i--)
        s[i] = s[i - 1];
    printf("Enter new student:\n");
    printf("ID: ");
    scanf("%d", &s[pos].id);
    printf("Name: ");
    scanf("%s", s[pos].name);
    printf("Gender: ");
    scanf("%s", s[pos].gender);
    printf("Math Physics Chemistry: ");
    scanf("%f %f %f", &s[pos].math, &s[pos].physics, &s[pos].chemistry);
    n++;
}

void deleteAllMales()
{
    int i = 0, count = 0;
    while (i < n)
    {
        if (strcmp(s[i].gender, "Male") == 0)
        {
            for (int j = i; j < n - 1; j++)
                s[j] = s[j + 1];
            n--;
            count++;
        }
        else
            i++;
    }
    printf("Deleted %d male student(s)\n", count);
}

int main()
{
    int choice;
    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Input & print all students\n");
        printf("2. Student with highest GPA\n");
        printf("3. Student with lowest GPA\n");
        printf("4. Find student with ID=123\n");
        printf("5. Find students named Nam\n");
        printf("6. Sort students by GPA (desc)\n");
        printf("7. Update student with ID=123\n");
        printf("8. Delete student with ID=123\n");
        printf("9. Insert student at position i\n");
        printf("10. Delete all male students\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputAll();
            printAll();
            break;
        case 2:
            highestGPA();
            break;
        case 3:
            lowestGPA();
            break;
        case 4:
            findId123();
            break;
        case 5:
            findNameNam();
            break;
        case 6:
            sortByGPA();
            break;
        case 7:
            updateId123();
            break;
        case 8:
            deleteId123();
            break;
        case 9:
            insertAt();
            break;
        case 10:
            deleteAllMales();
            break;
        case 0:
            printf("\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}