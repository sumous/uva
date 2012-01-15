/*10010 - Where's Waldorf?
*/
#include<stdio.h>
#include<string.h>
//int flag;
char s[51][51];
const int rd[]={-1,-1,0,1,1,1,0,-1},cd[]={0,1,1,1,0,-1,-1,-1};
int col, row;  

void Search(char *w, int &x, int &y)
{
	int i, j, t, xx, yy, pos;
	for(i = 0;i < row;i ++)
		for(j = 0;j < col;j ++)
		{
			if(w[0] == s[i][j])
				for(t = 0;t < 8;t ++)
				{
					pos = 0;xx = i; yy = j;
					while(w[pos]&&w[pos] == s[xx][yy])
					{
						xx += rd[t]; yy += cd[t];pos++;
					}
					if(w[pos] == '\0')
					{
						x = i;y = j;return;
					}
					
				
				}
		}
}


int main()
{
    int i, j, n, k;
    freopen("data.txt", "r", stdin);
    scanf("%d", &n);  //���������������
	getchar();
    for(k = 0;k < n;k ++)
    {
        
        
		if(k>=1) printf("\n");
        char  ch;
        scanf("%d%d", &row, &col);

        getchar();
        for(i = 0;i < row;i ++)//���뱻�����ַ���,��ת��ΪСд��ĸ
        {
            for(j = 0;j < col;j ++)
            {
                ch = getchar();
                if(ch <= 'Z') s[i][j] = ch-'A'+'a';
                else s[i][j] = ch;
                
            }
            s[i][j] = '\0';
          // puts(s[i]);
            getchar();
        
        }
        
        int k,  nflag;
        //int nrow=&temp_nrow, *ncol=&temp_ncol;
        
        scanf("%d", &k);
		getchar();
        while(k--)//��������ҵ��ַ���,Ҳ��ת��ΪСд��ĸ
        {
            i = 0;
			char w[51];
			ch = getchar();
             while(ch != '\n')//����һ���ַ�����ע��س�����ȥ�� 
             {
                  if(ch <= 'Z') w[i] = ch-'A'+'a';
                  else w[i] = ch;
                  i++;
				  ch = getchar();
             }
      		 
      		 w[i] = '\0';
      		  
			 int x, y;
			 Search(w, x, y);
             printf("%d %d\n", x+1, y+1);
             
        }
        
        //getchar();
    }
    return 0;
}
