#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <locale.h>

typedef struct Node{
    char val;
    struct Node *next;
}NODE, *pNODE;

typedef struct Stack{
    pNODE top;
    int len;
}STACK,*pSTACK;

pSTACK createstack(){
    pSTACK ps;
    ps=(pSTACK)malloc(sizeof(STACK));
        ps->top=NULL;
        ps->len=0;
        return ps;
}

int isempty(pSTACK ps){
    if (ps->top)return 0;
    return 1;
}

void push(pSTACK ps, char value){
    pNODE p=(pNODE)malloc(sizeof(NODE));
    p->val=value;
    p->next=ps->top;
    ps->top=p;
    ps->len++;
}

void show(pSTACK ps){
    pNODE p=ps->top;
    if (isempty(ps))puts("stack empty");
    else
        while (p){
            printf_s("%c",p->val);
            p=p->next;
        }
}

char pop(pSTACK ps){
    pNODE p=ps->top;
    int c=p->val;
    ps->top=p->next;
    free(p);
    ps->len--;
    return c;
}



void clearstack(pSTACK ps){
    while (!isempty(ps)) pop(ps);
        free(ps);
}

int main(){
    pSTACK ps=createstack();
    char c;
    for (c='a';c<='z';c++)
        push(ps,c);
    while(!isempty(ps)){
        pop(ps);
        show(ps);
        printf_s("\n");
    }
    _getch();
    return 0;
}
