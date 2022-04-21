#include <stdlib.h>
#include <math.h>

/*typedef struct{
    int x,y;
}Point;

void main(){
    double d;
    Point A={0,-3},B={0,1};
    d=sqrt(((A.x-B.x)*(A.x-B.x))+((A.y-B.y)*(A.y-B.y)));
    printf("%f",d);
}*/

/*struct Point{
    int x;
    int y;
};

void main(){
    double d;
    struct Point A={0,-3},B={0,1};
    d=sqrt(((A.x-B.x)*(A.x-B.x))+((A.y-B.y)*(A.y-B.y)));
    printf("%f",d);
}*/


struct Point{
    int x,y;
}A,B;

void main(){
    double d;
    A.x=0;
    A.y=-3;
    B.x=0;
    B.y=1;
    d=sqrt(((A.x-B.x)*(A.x-B.x))+((A.y-B.y)*(A.y-B.y)));
    printf("%f",d);
}

/*struct Point{
    int x,y;
}A={0,-3},B={0,1};

void main(){
    double d;
    d=sqrt(((A.x-B.x)*(A.x-B.x))+((A.y-B.y)*(A.y-B.y)));
    printf("%f",d);
}*/
