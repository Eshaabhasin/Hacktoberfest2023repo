#include<stdio.h>
void main(){
    int x=0b1000,y=0b0100,z=0;
    printf("%d\n",x);
    for(int a=0;a<10;a++){
        if(x!=1){
            x=x>>1;
            y=y<<1;
            printf("x=%d\n",x);
            printf("y=%d\n",y);
            if(x%2==0){
                z+=y;
                printf("%d",z);
            }
        }
    }
}