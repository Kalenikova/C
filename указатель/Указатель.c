#include <stdlib.h>
#include <math.h>

/*typedef struct{
    int x;
    int y;
}Point;*/

typedef struct{
    int x;
    int y;
}Point,*pPoint;

double dist(Point *A, Point *B){
    /*return sqrt(pow((*A).x-(*B).x,2)+pow((*A).y-(*B).y,2));*/
    return sqrt(pow(A->x-B->x,2)+pow(A->y-B->y,2));
}

/*void main(){
    Point A={0,-3}, B={0,1};
    printf("d=%f",dist(&A,&B));
}*/

void main(){
    Point A={0,-3}, B={0,1};
    pPoint pA=&A;
    pPoint pB=&B;
    printf("d=%f",dist(pA,pB));
}
