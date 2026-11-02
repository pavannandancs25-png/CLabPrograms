#include <stdio.h>
#include <string.h>
#define MAX 50

int F(char symbol) {
    switch(symbol) {
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 4;
    case '^':
    case '$': return 5;
    case '(': return 0;
    case '#': return -1;
    default: return 8;
    }
}

int G(char symbol) {
    switch(symbol) {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 3;
    case '^':
    case '$': return 6;
    case '(': return 9;
    case ')': return 0;
    default: return 7;
    }
}

int main(void) {
    char s[MAX],infix[MAX],postfix[MAX],symbol;
    int top=-1,j=-1;

    printf("Enter the infix string : ");
    scanf("%s",infix);
    s[++top] = '#';
    int i=0;

    while(infix[i] != '\0') {
        symbol = infix[i];
        while(F(s[top]) > G(symbol) && top != -1) {
            postfix[++j] = s[top--];
        }
        if(F(s[top]) != G(symbol) && top != -1 ) {
            s[++top] = symbol;
        } else {
            top--;
        }
        i++;
    }
    while(top != -1 && s[top] != '#') {
        postfix[++j] = s[top--];
    }
    postfix[++j] = '\0';

    printf("Postfix Expression : %s",postfix);

    return 0;


}
