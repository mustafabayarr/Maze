#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 2

int matris[M][N];

int cozum[M][N];

void yazdir()
{
    int i,j;
    printf("-------------Solution--------------\n\n");
    printf(   "!!!! O ==>> YOL  1 ==>> DUVAR !!!!  \n\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d\t",cozum[i][j]);
        }
        printf("\n\n");
    }
}
	

int recursionMatrix(int x, int y)
{
	
    
    if((x==M-1) && (y==N-1))
    {
        cozum[x][y] = 1;
        return 1;
    }
    
    if(x>=0 && y>=0 && x<M && y<N && cozum[x][y] == 0 && matris[x][y] == 0)
    {
        
        cozum[x][y] = 1;
       
        if(recursionMatrix(x, y+1))
            return 1;
            
        if(recursionMatrix(x+1, y))
            return 1;
        
        if(recursionMatrix(x-1, y))
            return 1;
        
        if(recursionMatrix(x, y-1))
            return 1;
        
        cozum[x][y] = 0;
        return 0;
    }
    return 0;

}

int main()
{
	int i,j;

	srand(time(NULL));
	
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            matris[i][j]=rand()%2;
        }
        printf("\n\n");
    }
    printf("--------Rastgele Dizi-------\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d\t",matris[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
   
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            cozum[i][j] = 1;
        }
    }
    if (recursionMatrix(0,0))
        yazdir();
    else
        printf("Yol bulunamadi.. Tekrar Calistir!!\n");
    
    return 0;
}
