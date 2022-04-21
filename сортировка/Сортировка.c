#include <stdlib.h>
#include <time.h>

const int size=6;

void make_arr(int *m){
    srand(time(NULL));
    int i;
    for (i=0;i<size;i++)
    {
        m[i]=rand()%51;
    }
}

void print_arr(int *m){
    int i;
    for (i=0;i<size;i++)
        printf("%d ",m[i]);
    printf("\n");
}

void copy_arr(int *m, int *x){
    int i;
    for (i=0;i<size;i++)
        x[i]=m[i];
}

void bubble_sort(int *m){
    int i,j,t;
    for (i=0;i<size-1;i++){
        for (j=size-1;j>i;j--){
            if (m[j-1]>m[j]){
            t=m[j];
            m[j]=m[j-1];
            m[j-1]=t;
        }
        }

    }
}

void bubblesort_new(int *m){
    int i,j=0,t;
    do{size=j;
    for (i=size-1;i>size;i--){
        if (m[i-1]>m[i]){
            j=i;
            t=m[i];
            m[i]=m[i-1];
            m[i-1]=t;}
        }
    }
    while (j-size);
}

void shaker(int *m){
    int i,t,n1=0,n2=size-1,j;
    do{
        for (i=n2;i>n1;i--){
            if (m[i-1]>m[i]){
              t=m[i];
              m[i]=m[i-1];
              m[i-1]=t;
              j=i;
            }
        }
        n1=j;
        for(i=n1;i<=n2;i++){
            if (m[i-1]>m[i]){
              t=m[i];
              m[i]=m[i-1];
              m[i-1]=t;
              j=i;
            }
        }
        n2=j-1;
    }
    while (n1<n2);
}

void selectionsort (int *m){
int i,j,min,t;
for (i=0;i<size-1;i++)
  {
   min=i;
   for (j=i+1;j<size;j++)
    {
    if (m[j]<m[min])
    min=j;
    }
   t=m[i];
   m[i]=m[min];
   m[min]=t;
  }
}

void insertsort (int *m)
{
 int i,j, t;
 for (i=1;i<size;i++)
 {
  t=m[i];
  for (j=i-1; j>=0 &&m[j]>t; j--)
  m[j+1]=m[j];
  m[j+1]=t;
 }
}



int main(){
    int a[size],b[size];
    make_arr(a);
    print_arr(a);
    copy_arr(a,b);
    print_arr(b);
    bubble_sort(b);
    bubblesort_new(b);
    shaker(b);
    selectionsort(b);
    insertsort(b);
    print_arr(b);
}
