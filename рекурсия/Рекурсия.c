#include <stdlib.h>
#include <time.h>

double Rec_Fact_Up(int n){
    if (n<=1) return 1.0;
    else return	Rec_Fact_Up(n-1) * n;
}

unsigned long fib(int n){
    if (n==0 || n==1) return 1;
    else return fib(n-1)+fib(n-2);
}

double Rec_step(float a, int n){
    if (n <= 0) return 1.0;
    else return Rec_step(a,n-1)*a;
}

double rec_degree(double a, int n){
    double r;
    if (!n) return 1;
    if (!(n%2)) return r=rec_degree(a,n/2), r*r;
    else return a*rec_degree(a,n-1);
}

int NOD_rec(int a, int n){
    if (!(a%n)) return n;
    else return NOD_rec(n,a%n);
}

void printd(int k){
    if (k<0){
        putchar('-');
        k=-k;
    }
    if (k){ printd(k/10);
    putchar(k%10 + '0');
    }
}

void Reverse(){
    char ch;
    if ((ch= getch())!='\r'){
        Reverse();
        putchar(ch);}
}

int sum (int *s, int n){
    if (n==1) return s[0];
    else return sum(s, n-1)+s[n-1];
}

int main(){

    printf("n!=%f\n", Rec_Fact_Up(6));
    printf("fib=%d\n", fib(4));
    printf("Rec_step=%f\n", Rec_step(5, 3));
    printf("rec_degree=%f\n", rec_degree(2, 5));
    printf("NOD=%d\n", NOD_rec(21, 7));
    printf("printd=%d");
    printd(-459);
    printf("\n");
    printf("Reverse=");
    Reverse();
    printf("\n");
    printf("sum=\n", sum(7,3));

    return 0;
}
