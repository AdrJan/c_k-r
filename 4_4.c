#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define MAXVAL 100

void push(double);
double pop(void);
double peek(void);
void push_dup(void);
void top_swap(void);

int sp = 0;
double val[MAXVAL];

int main()
{
    push(1.21);
    push(8.21);
    push(1.23);
    push(-2.89);

    assert(peek() == -2.89);
    assert(pop() == -2.89);
    top_swap();
    assert(peek() == 8.21);
    push_dup();
    assert(peek() == 8.21);

    return EXIT_SUCCESS;
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

void clear()
{
    val[0] = '\0';
    sp = 0;
}
