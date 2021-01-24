#include<stdio.h>
#include<stdlib.h>
#include"headfile.h"
int main()
{
	//查找 插入 逆置 删除--测试
 /*
	//顺序表
	SeqList L;
	int i,x,num,sum;
	printf("输入元素个数： \n");
	scanf_s("%d",&sum);
	InitSeqList(&L,sum);
	printf("输入顺序表元素：\n");
	for (i = 0; i < sum; i++)      // 插入构建
	{
		scanf_s("%d", &num);
		InsertSeqList(&L, i - 1, num);
	}
	printf("原顺序表为： \n");
	OutputSeqList(&L);
	printf("逆置后为： \n");
	Reverse(&L);
	OutputSeqList(&L);
	printf("请输入查找的下标值：\n");  //查找
	scanf_s("%d",&num);
	 if ( FindSeqList(L,num,&x) )
	   {printf("目标元素值为%d \n",x);
		DeleteSeqList(&L,num);
		printf("删去目标元素后原顺序表为： \n");   //删除
		OutputSeqList(&L);
	   }
	 else
		 printf("下标越界 \n");

	DestSeqList(&L); //撤销
	system("pause");
*/

//查找 插入 逆置 删除--测试
/*
	//单链表
	
	HeaderList h;
	int i,num,x,sum;
	InitHeaderList(&h);
	printf("输入单链表元素个数： \n");
	scanf_s("%d", &sum);
	printf("输入单链表个元素： \n");
	for(i=0;i<sum;i++)
	{
		scanf_s("%d",&num);
		InsertHeaderList(&h,i-1,num); //通过插入操作构造单链表
		
	}
	printf("原单链表： \n");
	OutputHeaderList(&h);
	printf("原链表排序后为：\n");   //排序
	SortHeaderList(&h);
	OutputHeaderList(&h);
	printf("原链表逆置后： \n");    //逆置
	InverseHeaderList(&h);
	OutputHeaderList(&h);
	printf("请输入查找的下标值：\n");
	scanf_s("%d",&num);
	if ( FindHeaderList(&h,num,&x) )   //查找
		 {
			printf("目标元素值为%d \n",x);
			DeleteHeaderList(&h,num);
			printf("删去目标元素后单链表为： \n");  // 删除
			OutputHeaderList(&h);
		  }
	else
			printf("下标越界 \n");
	DestHeaderList(&h);                //撤销
	system("pause");

*/


// 多项式测试

/* 
	//多项式乘法测试
 Polynominal p1,p2,p3;
 printf("构建p1指数幂降序表达式（以某负指数幂项作为结尾标志）：\n");
 Create(&p1);
 printf("p1(x)=");
 Printpoly(&p1);
 printf("构建p2指数幂降序表达式（以某负指数幂项作为结尾标志）：\n");
 Create(&p2);
 printf("p2(x)=");
 Printpoly(&p2);
 Multip(&p1,&p2,&p3);
 printf("ans(x)=p1(x) * p2(x) =");
 Printpoly(&p3);
 Destory(&p1);
 Destory(&p2);
 Destory(&p3);//撤销
 system("pause");
*/

 /* 
	 //多项式加法测试
  Polynominal p1,p2;
  printf("构建p1指数幂降序表达式（以某负指数幂项作为结尾标志）：\n");
  Create(&p1);
  printf("p1(x)=");
  Printpoly(&p1);
  printf("构建p2指数幂降序表达式（以某负指数幂项作为结尾标志）：\n");
  Create(&p2);
  printf("before add,p2(x)=");
  Printpoly(&p2);
  Add(&p1,&p2);
  printf("after add,p2(x)=");
  Printpoly(&p2);
  Destory(&p1);
  Destory(&p2);//撤销
  system("pause");
*/

	return 0;
}