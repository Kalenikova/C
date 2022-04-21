#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Node{
  int val;
  struct Node *next;
}NODE,*pNODE;

typedef struct queue{
  NODE *beg, *end;
  int len;
}QUEUE,*pQUEUE;

int isempty(pQUEUE pQ){
  if(pQ->beg == NULL) return 1;
  return 0;
}

void show(pQUEUE pQ){
  pNODE p = pQ->beg;
    if(isempty(pQ))puts("empty");
    while(p){
      printf("%d", p->val);
      p = p->next;
    }
    printf("\n");
}

pQUEUE create(){
  pQUEUE pQ;
  pQ = (pQUEUE)malloc(sizeof(QUEUE));
  pQ->beg = NULL;
  pQ->end = NULL;
  pQ->len = 0;
  return pQ;
}

void put(pQUEUE pQ, float value){
  pNODE pn;
  pn = (pNODE)malloc(sizeof(NODE));
  pn->next = NULL;
  pn->val = value;
  if(pQ->end != NULL) pQ->end->next = pn;
  else pQ->beg = pn;
  pQ->end = pn;
  pQ->len++;
}

float take(pQUEUE pQ){
  pNODE p = pQ->beg;
  float c=p->val;
  pQ->beg = p->next;
  free(p);
  pQ->len--;
  return c;
}

void ClearQueue(pQUEUE pQ){
  while(!isempty(pQ)){
    take(pQ);
  }
  free(pQ);
}

int main(void){
  pQUEUE pQ = create();
  int i;
  for(i = 1; i < 11;i++){
    put(pQ,i);
  }
  show(pQ);
  while(!isempty(pQ)){
    take(pQ);
    show(pQ);
  }
}
