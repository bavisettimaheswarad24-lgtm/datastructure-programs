#include <stdio.h>

// Define a structure for a student
struct Student {
    char name[50];
    int marks;
};

int main() {
    struct Student s1, s2;

    // Input details for first student
    printf("Enter name of first student: ");
    scanf("%s", s1.name);
    printf("Enter marks of first student: ");
    scanf("%d", &s1.marks);

    // Input details for second student
    printf("Enter name of second student: ");
    scanf("%s", s2.name);
    printf("Enter marks of second student: ");
    scanf("%d", &s2.marks);

    // Compare and display who scored higher
    printf("\n--- Result ---\n");
    if (s1.marks > s2.marks) {
        printf("%s scored higher with %d marks.\n", s1.name, s1.marks);
    } else if (s2.marks > s1.marks) {
        printf("%s scored higher with %d marks.\n", s2.name, s2.marks);
    } else {
        printf("Both %s and %s scored the same marks: %d\n", s1.name, s2.name, s1.marks);
    }

    return 0;
}
