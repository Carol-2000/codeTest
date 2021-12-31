/*
 * 流水作业调度
 * 方法：动态规划
 */
#include<stdio.h>
#include<stdlib.h>
#define N 100
struct job
{
    int index; // 作业序号
	int time; // 作业执行时间
	int machine; // 机器序号，1代表第一个机器，0代表第2个机器
};

int compare(const void* _n1, const void* _n2);
int main()
{
	int j,k,n;
	int machine1[N]={0},machine0[N]={0};
	int best[N]; // 预定义最优作业调度序列
	job input[N]; // 预定义输入作业调度序列
	printf("Input number of jobs:");
	scanf("%d",&n);
	printf("\nInput Format:M1-time M2-time\n\n");
	for(int i=0; i<n; i++)
	{
	    printf("Input %d job: ", i+1);
		scanf("%d%d",&machine1[i],&machine0[i]);
	}
	//n个作业中，每个作业的最小加工时间
	for(int i=0; i<n; i++)
	{
		input[i].time = (machine1[i]>machine0[i])?machine0[i]:machine1[i];
		input[i].index = i;
		//给符合条件a[i]<b[i]的放入到N1子集标记为1
		input[i].machine = (machine1[i]>machine0[i])?0:1;
	}
	//按照input[]中作业时间增序排序
	qsort(input,n,sizeof(job),compare);
	j=0,k=n-1;
	for(int i=0; i<n; i++) {
		//第一组，从i=0开始放入到best[]中
		if(input[i].machine)
		{
			best[j++]=input[i].index;//将排过序的数组c，取其中作业序号属于N1的从前面进入，实现N1的非减序排序
		}
		else
		{
			best[k--]=input[i].index;//将排过序的数组c，取其中作业序号属于N2的从后面进入，实现N2的非增序排序
		}
	}
	j=machine1[best[0]];//最优调度序列下的消耗总时间，第一个选取M1上的工作时间最少的
	k=j+machine0[best[0]];

	for(int i=1; i<n; i++){
		j+=machine1[best[i]];
		k=j<k?(k+machine0[best[i]]):j+machine0[best[i]];//消耗总时间的最大值
	}
	printf("%d\n",k);

	for(int i=0; i<n; i++){
		printf("%d ",best[i]+1);//输出最优序列
	}
	printf("\n");

	return 0;
}
int compare(const void* _j1, const void* _j2)
{
	// 升序排序
	return (*(job*)_j1).time - (*(job*)_j2).time;
}
