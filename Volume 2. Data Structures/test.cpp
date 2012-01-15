#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
double random()  
{  
    return (double) rand() / RAND_MAX;  
}  
  
int rando(int m)  
{  
    return (int)(random() * (m-1) + 0.5);  
}  
int main()  
{  
    int n, i, m, ci;  
    freopen("data.txt", "w", stdout);  
    srand(time(NULL));  
    scanf("%d", &n);  
    printf("%d %d %d\n",n,rando(10000),rando(10000));   
    printf("0 0 0");
    return 0;  
}  

