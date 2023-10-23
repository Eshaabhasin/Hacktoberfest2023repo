#include<stdio.h>
#include<time.h>
void main(){
    int n,a[3][3]={1,3,7,5,6,4,8,1,5},b[3][3]={6,8,4,2,5,6,3,1,7},c[3][3];
    //int n,a[2][2]={1,3,7,5},b[2][2]={6,8,4,2},c[2][2];

    clock_t t;
    t = clock();
    time_t start, end;
    start = time(NULL);

    printf("Enter the order of the matrix(within 5): ");
    scanf("%d",&n);
    /*printf("Enter Elements for matrix: \n");
    for (int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter Elements for 2nd matrix: \n");
    for (int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("b[%d][%d] = ",i,j);
            scanf("%d",&b[i][j]);
        }
    }*/

           int count=0;
    for (int i=0;i<n;i++){  //n time
        for(int j=0;j<n;j++){  //n time
            c[i][j]=0;
            //printf("a[%d][%d]\n",i,j);
            for(int x=0;x<n;x++){   //n time
                //printf("%d\n",a[0][x]*b[x][0]);
                c[i][j] += a[i][x]*b[x][j] ;   //n*n*n times
                count++;
            }
            printf("c[%d][%d]=%d\n",i,j,c[i][j]);
            //printf("%d",c[i][j]);
        }
    }
    printf("Counter = %d\n",count);

    end = time(NULL);
    printf("Time taken to matrixmultiple is %.2f seconds\n",
           difftime(end, start));
    t = clock() - t;
    printf("No. of clicks %ld clicks (%f seconds).\n",
           t, ((float)t) / CLOCKS_PER_SEC);
}