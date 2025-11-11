#include <stdio.h>

// Structure to store student details
struct Student {
    char name[50];
    int rollNo;
    float marks;
};

// Function to accept student details (passed by reference)
void acceptDetails(struct Student *s) {
    printf("Enter student's name: ");
    scanf(" %[^\n]", s->name);  // Reads full name with spaces

    printf("Enter roll number: ");
    scanf("%d", &s->rollNo);

    printf("Enter marks: ");
    scanf("%f", &s->marks);
}

// Function to display student details (passed by value)
void displayByValue(struct Student s) {
    printf("\n--- Student Details (By Value) ---\n");
    printf("Name: %s\n", s.name);
    printf("Roll Number: %d\n", s.rollNo);
    printf("Marks: %.2f\n", s.marks);
}

// Function to display student details (passed by reference)
void displayByReference(struct Student *s) {
    printf("\n--- Student Details (By Reference) ---\n");
    printf("Name: %s\n", s->name);
    printf("Roll Number: %d\n", s->rollNo);
    printf("Marks: %.2f\n", s->marks);
}

int main() {
    struct Student s;

    // Accept details from the user
    printf("Please enter the student details:\n");
    acceptDetails(&s);  // Passing by reference

    // Show details by value
    displayByValue(s);  // Passing by value

    // Show details by reference
    displayByReference(&s);  // Passing by reference

    return 0;
}
