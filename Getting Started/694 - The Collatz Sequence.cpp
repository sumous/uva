/*694 - The Collatz Sequence
*/
#include<stdio.h>
void Term(long A, long lim, long* terms)
{
      if(A == 1) {
          (*terms)++;

          return;
      }
      if(A > lim) return;
      if(A % 2==0){
          (*terms)++;
          Term(A/2, lim, terms);
      }
      else{
          (*terms)++;
          Term(3*A+1, lim, terms);
      }
}

int main()
{
    long A, lim, i = 1, temp;

    while(scanf("%ld%ld", &A, &lim)&&A != -1)
    {
        temp = 0;
        long* terms = &temp;
        Term(A, lim, terms);
        printf("Case %ld: A = %ld, limit = %ld, number of terms = %ld\n", i, A, lim, *terms);
        i++;
    }
    return 0;
}
