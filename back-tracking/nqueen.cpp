/*
 * N皇后问题：N个皇后两两不在同一行/同一列/同一对角线上，有多少种摆放方法及其具体摆法？
 * 方法：回溯法
 */
#include<stdio.h>
#define MAXSIZE 20

int N;
static int count = 0;
int chess[MAXSIZE][MAXSIZE];
void queen(int i,int j);
int check(int i,int j);
void output();

int main()
{
	printf("Input N:");
	scanf("%d",&N);
	queen(0,0); // N皇后问题的初值为(0,0)
	printf("%d皇后问题共有%d种解法\n", N, count);
	return 0;
}
void queen(int i,int j)
{
	if( i>=N || j>=N ) return;
	// 尝试在位置上摆放皇后
	if( check(i,j) )
	{
		// 摆放皇后
		chess[i][j] = 1;
		// 该次摆放到达最后一行，意味着一种摆法的诞生
		if( i==N-1 )
		{
			count++; // 计数加一
			output();// 输出该种摆法
		}
		else { // 该次摆放非最后一行，从下一行开头开始摆放
			queen(i+1,0);
		}
	}
	// 未成功摆放皇后
	chess[i][j] = 0;
	// 该次摆放不成功，从同一行的下一个位置开始摆放
	queen(i,j+1);
}
int check(int i,int j)
{
	int temp; // 遍历变量
	// 判断行
	for(int temp=0; temp<N; temp++){
		// 同一行有皇后则返回0
		if(chess[i][temp]==1) return 0;
	}
	// 判断列
	for(int temp=0; temp<N; temp++){
		// 同一列有皇后则返回0
		if(chess[temp][j]==1) return 0;
	}
	// 判断对角线
	for(int temp=-N; temp<=N; temp++){
		// 左上角到右下角有皇后则返回0
		if( (i+temp)>=0 && (i+temp)<N && (j+temp)>=0 && (j+temp)<N ){
			if(chess[i+temp][j+temp]==1) return 0;
		}
		// 左下角到右上角有皇后则返回0
		if( (i-temp)>=0 && (i-temp)<N && (j+temp)>=0 && (j+temp)<N ){
			if(chess[i-temp][j+temp]==1) return 0;
		}
	}
	// 未返回0则意味着可以摆放皇后
	return 1;
}
void output()
{
	FILE *fp;
	if( (fp = fopen("queen.txt","at")) != NULL )
	{
		fprintf(fp,"第%d种摆法\n", count);
		for(int a=0; a<N; a++)
			for(int b=0; b<N; b++)
			{
				fprintf(fp,"%d",chess[a][b]);
				if(b == N-1) fprintf(fp,"\n");
			}
		fprintf(fp,"\n");
	}
	fclose(fp);
}
