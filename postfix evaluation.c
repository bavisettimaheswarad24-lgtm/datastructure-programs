#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

void infixToPostfix(char exp[]) {
    char *e, x;
    e = exp;

    printf("\nPostfix Expression: ");
    while (*e != '\0') {
        if (isalnum(*e))  // if operand
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else { // operator
            while (top != -1 && precedence(stack[top]) >= precedence(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }

    while (top != -1)
        printf("%c", pop());
}

int main() {
    char exp[50];
    printf("Enter Infix Expression: ");
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}
