#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

typedef struct Node{
  int value;
  struct Node *next;
}NODE,*pNODE;

typedef struct List{
  pNODE top;
  int len;
}LIST,*pLIST;

pLIST create_list(){
  pLIST pL= (pLIST)malloc(sizeof(LIST));
    if(pL){
        pL->top = NULL;
        pL->len = 0;
    }
    return pL;
}

int isEmpty(pLIST pL){
  if(pL->top && pL->len) return 0;
    return 1;
}

void clearLIST(pLIST pL){
  while(pL->top->next) delNode(pL, pL->top);
  free(pL->top);
  pL->len--;
}

pNODE findNode(pLIST pL,int date){//date=13
  if(isEmpty(pL)) return NULL;
  pNODE temp = pL->top;
  if(temp->value==date) return temp;
  while(temp->next && temp->next->value!=date) temp = temp->next;
  if(temp->next) return temp;
  return NULL;
}

int addNodeAfter(pLIST pL,pNODE pN, int newdate){//date=8
  pNODE pnew = (pNODE)malloc(sizeof(NODE));
  if(pnew){
    pnew->value = newdate;
    if(!pN){
      pnew->next = NULL;
      pL->top = pnew;
    }
    else
    if(pN == pL->top && newdate>pL->top->value){
      pnew->next = pL->top;
      pL->top = pnew;
    }
    else{
      pNODE temp = pN->next;
      pnew->next = temp;
      pN->next = pnew;
    }
    pL->len++;
    return 1;
  }
  return 0;
}

int delNode(pLIST pL,pNODE pN){
  if(!pN) return 0;
  pNODE temp = pN->next;
  pN->next = temp->next;
  free(temp);
  pL->len--;
  return 1;
}

void deleteList(pLIST pL){
  if(!isEmpty(pL)) clearLIST(pL);
  free(pL);
}

void showList(pLIST pL){
  if(isEmpty(pL)) printf("List is empty!!\n");
  else{
    pNODE temp = pL->top;
    printf("Length List: %d\n",pL->len);
    while(temp){
      printf("adres: %p\t Value: %d\t next:%p\n", temp,temp->value,temp->next);
      temp=temp->next;
    }
  }
}

pNODE GetPointer(pLIST pL,int date){
  if(isEmpty(pL)) return NULL;
  pNODE temp = pL->top;
    if(temp->value<=date) return temp;
  while(temp->next && temp->next->value>date)
  temp=temp->next;
    return temp;
}

int main(){
    pLIST pL=create_list();
    pNODE p;
    char exit=0;
    int come;
    while (1){
        puts("1 - add element");
        puts("2 - find the element");
        puts("3 - delete the element");
        puts("4 - show list");
        puts("5 - clear list");
        puts("6 - auto list");
        puts("0 - end of work");
        scanf("%d", &come);
        switch(come){
            case 0: exit=1; break;
            case 1: printf("vvedite chislo:");
                    scanf("%d", &come);
                    addNodeAfter(pL, GetPointer(pL, come), come);
                    break;
            case 2: printf("Enter chislo:");
                    scanf("%d", &come);
                    p=findNode(pL, come);
                    if (p){
                        p=(p==pL->top&&come==pL->top->value)? p:p->next;
                        printf("chislo %d in list, address:%p\n", come);
                    }
                    else
                        printf("Chislo %d nod find in list!\n", come);
                    break;
            case 3: printf("Enter chislo:");
                    scanf("%d", &come);
                    p=findNode(pL, come);
                    if (p){
                        if (p==pL->top&&come==pL->top->value){
                            pL->top=p->next;
                            pL->len--;
                            free(p);
                            printf("Delete complete!\n\n");
                        }
                        else
                            if(delNode(pL,p))printf("Delete complete1\n\n");
                    }
                    else
                        printf("A integer %d doesn't contain in list!\n", come);
                    break;
            case 4: showList(pL); break;
            case 5: clearLIST(pL); break;
        };
        if (exit)break;
    }
    deleteList(pL);
    return 0;
}
