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

void projcet(){
	printf("******************\n");
	printf("*  校园导游咨询  *\n");
	printf("******************\n\n");
}
void banquan(){
	printf("软工一班\n");
	printf("\t184804013 马海力\n"); 
	printf("\t184804005 崔小玉\n"); 
	printf("\t184804010 李倬斌\n\n"); 	
}
int tishi(){
	int choise;
	projcet();				
	printf("\n请选择您的操作：\n");
	printf("|=============================|\n");
	printf("|(1) 查询两个景点最短路径-----|\n");
	printf("|(2) 查询景点信息-------------|\n");
	printf("|(3) 查询两个景点所有路线-----|\n");	
	printf("|(0) 退出---------------------|\n");
	printf("|=============================|\n\n");
	scanf("%d",&choise);
	return choise;
}
int daihao(char *name,int n){ //把输入的名字化为结构体的序号
	int i,a; 
	for(i=0;i<n;i++){
		if(!strcmp(name,place[i].name)) 
			a=i;	
	}
	return a;
}
int **creat_graph(int n,int m){//建立无向图，输入地点信息和路线 
	int i,j,t,f,x,y,k,distance;				
	
	int **graph=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++) 
		graph[i]=(int *)malloc(n*sizeof(int));
		
	for(i=0;i<n;i++)  
		for(j=0;j<n;j++){ 
			graph[i][j]=maxn;
		}	//初始化
	
	printf("\n请输入地点信息\n");	
	for(i=0;i<n;i++){
		scanf("%s %d %d %d %s",&place[i].name,&place[i].daihao,&place[i].renshu,&place[i].fonud_year,&place[i].introduce);
	}	//输入地点信息	
	printf("\n请输入可连通路线\n");
	for(i=0;i<m;i++){
		scanf("%d %d %d",&x,&y,&distance);
		graph[x][y]=graph[y][x]=distance;
	} 	//输入路线信息 
	
	system("pause");
	system("cls");
	return graph;	
			
}
