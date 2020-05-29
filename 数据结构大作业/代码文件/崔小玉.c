#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define maxn 100
struct node{
	char name[maxn];
	int daihao;
	int renshu;
	int fonud_year;
	char introduce[maxn];	
}place[maxn];//地点信息用结构存  

int **Floyd(int **graph,int n){//运用弗洛伊德算法生成每两点之间的最短路径的距离 
		
	int i,k,j;
	int **g=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++) 
		g[i]=(int *)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)  
		for(j=0;j<n;j++){
			g[i][j]=graph[i][j];
		}
	
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				if(g[i][j]>g[i][k]+g[k][j]){
					g[i][j]=g[i][k]+g[k][j];
				}				
			}			
	return g;		
}
void chaxun_jingdian(int n){//为来访客人提供图中任意景点相关信息的查询
	char x[maxn]; 
	int i,a=-1;	
	printf("\n请输入查询景点：\n");
	scanf("%s",&x);
	a=daihao(x,n);	
	if(a==-1){
		printf("\n抱歉，您查询的地址有误。\n");return;
	}
	printf("\n景点代号：%d\n",place[a].daihao);
	printf("容纳人数：%d\n",place[a].renshu);	
	printf("建立时间：%d\n",place[a].fonud_year);
	printf("介绍：%s\n",place[a].introduce);	
}
