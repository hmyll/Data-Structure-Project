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
int tishi();
void projcet();
void banquan();
int daihao(char *name,int n);//把输入的名字化为结构体的序号 
int **creat_graph(int n,int m);//建立无向图，输入地点信息和路线 
int **Floyd(int **graph,int n);//运用弗洛伊德算法生成每两点之间的最短路径的距离 
int **Fpath(int **graph,int n);//运用弗洛伊德算法生成每两点之间的最短路径的路线 
void chaxun_luxian(int **graph,int **path,int n);//查询景点之间的一条最短的简单路径
void chaxun_jingdian(int n);//为来访客人提供图中任意景点相关信息的查询
void all_route(int **graph,int n);//提供图中任意景点之间的所有路径
void dfs(int **graph,int *stack,int *visited,int n,int a,int b,int top);//运用dfs算法求图中两点的所有路径 
int main()
{
	int i,j,choise,m,n;
	system("color F0");
	projcet();
	banquan();
	printf("请输入景点数量和路线数量：\n");
	scanf("%d %d",&n,&m);//n是景点数量 m是路线数量	
		
	int **graph=creat_graph(n,m);
	int **fgraph=Floyd(graph,n);
	int **path=Fpath(graph,n);
	
	choise=tishi();	
	while(choise){
		if(choise==1) chaxun_luxian(fgraph,path,n);
		else if(choise==2) chaxun_jingdian(n);
		else if(choise==3) all_route(graph,n);		
		else printf("\n请输入正确操作\n");
		system("pause");
		system("cls");		
		choise=tishi();
	}	

	return 0;	
	
}
int **Fpath(int **graph,int n){//运用弗洛伊德算法生成每两点之间的最短路径的路线 
	int i,k,j,g[maxn][maxn]={0};
	int **path=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++) 
		path[i]=(int *)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)  
		for(j=0;j<n;j++){
			g[i][j]=graph[i][j];
			path[i][j]=j;
		}
	
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				if(g[i][j]>g[i][k]+g[k][j]){
					g[i][j]=g[i][k]+g[k][j];
					path[i][j]=path[i][k];
				}				
			}			
	return path;	
}
void chaxun_luxian(int **graph,int **path,int n){	//查询景点之间的一条最短的简单路径
	char x[maxn],y[maxn]; 
	int i,a=-1,b=-1;
	printf("\n请输入查询景点：\n");
	scanf("%s %s",&x,&y);
	a=daihao(x,n);
	b=daihao(y,n);		
	if(a==-1||b==-1){
		printf("\n抱歉，您查询的地址有误。\n");return;
	}
	printf("\n%s 到 %s 的最短距离为：%d m\n",x,y,graph[a][b]);
	printf("\n%s 到 %s 的最短距离路线是：\n",x,y);	
	printf("%s-->",place[a].name);
	while(path[a][b]!=b){	
		printf("%s-->",place[path[a][b]].name);
		a=path[a][b];		
	}		 		
	printf("%s\n",place[path[a][b]].name);			
}

void all_route(int **graph,int n){//提供图中任意景点之间的所有路径
	char x[maxn],y[maxn]; 
	int i,j,a=-1,b=-1,top;	
	printf("\n请输入查询景点：\n");
	scanf("%s %s",&x,&y);
	a=daihao(x,n);
	b=daihao(y,n);		
	if(a==-1||b==-1){
		printf("\n抱歉，您查询的地址有误。");return;
	}
	top=0;
	int *stack=(int *)malloc(sizeof(int)*maxn);
	int *visited=(int *)malloc(sizeof(int)*maxn);
	memset(visited,0,sizeof(int)*maxn);
	printf("\n%s 到 %s 的所有路线是：\n",x,y);	
	dfs(graph,stack,visited,n,a,b,top);		
	
}
void dfs(int **graph,int *stack,int *visited,int n,int a,int b,int top){//运用dfs算法求图中两点的所有路径 
	int i,j;
	stack[top++]=a;
	visited[a]=1;//标记被访问过 
	for(i=0;i<n;i++){
		if(graph[a][i]<maxn){
									
			if(i==b){	// 找到终点	
				for(j=0;j<top;j++)
					printf("%s-->",place[stack[j]].name);	
				printf("%s\n",place[b].name);
				top--;
				visited[a]=0;
				break;
			}		
			if(!visited[i]) {// 未被访问过 
				dfs(graph,stack,visited,n,i,b,top);		
			}
		}
		
		if(i==n-1){// 如果该顶点无其它出度 
			top--;
			visited[a]=0;
		}
	}			
}


