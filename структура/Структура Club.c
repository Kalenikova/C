#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int N = 5;

typedef struct club{
char name[10];
int result;
} ski;


void makeArr(ski * m)
{
for(int i = 0; i < N; i++)
{
scanf("%s", m[i].name);
scanf("%d", &m[i].result);
}
}

void printArr(ski * m){
for (int i = 0; i < N; i++){
printf("Skier %s",m[i].name);
printf(" %d place\n",m[i].result);
}
}

void Select(ski * m){
char t2[100];
int i,j,im,t;
for(i=0;i<N-1;i++){
im=i;
for(j=i+1;j<N;j++){
if(m[j].result<m[im].result)
im=j;}
if(i!=im){
t = m[im].result;
m[im].result = m[i].result;
m[i].result = t;

}
}
}

int main(void){
ski clubs[N];
makeArr(clubs);
Select(clubs);
printArr(clubs);
}
