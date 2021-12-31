/*
 * 活动安排问题
 * 方法：贪心算法(也可以使用动态规划)
 */
#include<stdio.h>
#define MAXSIZE 20

int plan[MAXSIZE];
void greedy(int a[],int b[],int c);

int main()
{
    int start_time[MAXSIZE];
    int end_time[MAXSIZE];
    int a_num, count=0;
    do{
        printf("Input number of activity(0<=num<%d): ", MAXSIZE);
        scanf("%d",&a_num);
    }while(a_num<=0 || a_num >MAXSIZE);
    printf("\nInput Format:start-time end-time\n\n");
    for(int i=0; i<a_num; i++){
        printf("Input %d activity: ", i+1);
        scanf("%d%d",&start_time[i],&end_time[i]);
    }
    greedy(start_time,end_time,a_num);
    // Output
    for(int i=0; i<a_num; i++)
        if(plan[i]==1){
            count++;
            printf("[Activity %d]from %d to %d\n",
                   i+1, start_time[i], end_time[i]);
        }
    if(count > 1) {
        printf("Total %d activities\n", count);
    }
    else {
        printf("Total %d activity\n", count);
    }
    return 0;
}
void greedy(int a[],int b[],int c)
{
    int temp = 0;
    for(int i=0; i<c; i++)
        plan[i]=0; // 初始化
    // 开始安排
    plan[0] = 1;
    for(int i=1;i<c;i++)
     {
        if(a[i] > b[temp])
        {
           plan[i] = 1;
           temp = i;
        }
     }
}
