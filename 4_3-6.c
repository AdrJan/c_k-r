#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define VAR_S_LEN 1
#define MATH_S_LEN 3
#define MAX_ALPHABET 26

#define NUMBER '0'
#define MATH_OP '1'
#define VAR_OP '2'
#define STACK_OP '3'

#define IS_USED 1

int getop(char[]);
void push(double);
double pop(void);
double peek(void);
void push_dup(void);
void top_swap(void);
int getch(void);
void ungetch(int);
void math_fun_exec(char[]);
void stack_fun_exec(char[]);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;
double op2, op1;
char var_val[MAX_ALPHABET];
int var_used[MAX_ALPHABET];
int var_id;

int main()
{
    int type;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case MATH_OP:
            math_fun_exec(s);
            break;
        case STACK_OP:
            stack_fun_exec(s);
            break;
        case VAR_OP:
            var_id = s[0] - 'a';
            if (!var_used[var_id])
            {
                var_val[var_id] = pop();
                var_used[var_id] = IS_USED;
            }
            else
                push(var_val[var_id]);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 == 0.0)
                printf("ERROR: zero divisor");
            else
                push(pop() / op2);
            break;
        case '%':
            op2 = pop();
            push((int)pop() % (int)op2);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("ERROR: unknown command %s\n", s);
            break;
        }
    }
    return EXIT_SUCCESS;
}

void math_fun_exec(char s[])
{
    if (!strcmp(s, "exp"))
        push(exp(pop()));
    else if (!strcmp(s, "sin"))
        push(sin(pop()));
    else if (!strcmp(s, "pow"))
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("ERROR: unkown operation %s\n", s);
}

void stack_fun_exec(char s[])
{
    if (!strcmp(s, "peek"))
        peek();
    else if (!strcmp(s, "pdup"))
        push_dup();
    else if (!strcmp(s, "swap"))
        top_swap();
    else
        printf("ERROR: unkown operation %s\n", s);
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ERROR: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("ERROR: stack empty\n");
        return 0.0;
    }
}

double peek(void)
{
    if (sp > 0)
        return val[sp - 1];
    else
    {
        printf("ERROR: stack empty\n");
        return 0.0;
    }
}

void push_dup(void)
{
    if (sp < MAXVAL)
        val[sp++] = peek();
    else
        printf("ERROR: stack full, can't push %g\n", peek());
}

void top_swap()
{
    double el_1 = pop();
    double el_2 = pop();

    push(el_1);
    push(el_2);
}

int getop(char s[])
{
    int i, c, c_next;
    i = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (isalpha(c))
    {
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (i > MATH_S_LEN)
            return STACK_OP;
        if (i > VAR_S_LEN)
            return MATH_OP;
        else
            return VAR_OP;
    }

    if ((c == '+' || c == '-') && isdigit(c_next = getch()))
    {
        s[1] = c_next;
        c = c_next;
        i = 1;
    }
    else if (!isdigit(c) && c != '.')
        return c;

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
