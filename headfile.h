#include<stdio.h>
#include<stdlib.h>
//顺序表结构
typedef struct seqlist
{
	int n;
	int maxLength;
	int* element;
}SeqList;
//链表结构
typedef struct node
{
	int element;
	struct node* link;

}Node;
typedef struct headerlist
{
	Node* head;
	int n;
}HeaderList;
//多项式（带表头的单循环链表）
typedef struct pNode
{
	int coef;
	int exp;
	struct pNode* link;
}PNode;
typedef struct polynominal
{
	PNode* head;
}Polynominal;

//-------线性表运算
	//初始化
int InitSeqList(SeqList* L, int msize)
{
	L->maxLength = msize;
	L->n = 0;
	L->element = (int*)malloc(sizeof(int) * msize);
	if (!L->element)
		return 0;
	return 1;
}
//查找（下标为i）
int FindSeqList(SeqList L, int i, int* x)
{
	if (i<0 || i>L.n - 1)
		return 0;
	*x = L.element[i];
	return 1;
}
//插入（x成为下标为i+1的元素）
int InsertSeqList(SeqList* L, int i, int x)
{
	int j;
	if (i<-1 || i>L->n - 1)
		return 0;
	if (L->n == L->maxLength)
		return 0;
	for (j = L->n - 1; j > i; j--)
		L->element[j + 1] = L->element[j];
	L->element[i + 1] = x;
	L->n++;
	return 1;

}
//删除（下标为i）
int DeleteSeqList(SeqList* L, int i)
{
	int j;
	if (i<0 || i>L->n - 1)
		return 0;
	if (!L->n)
		return 0;
	for (j = i + 1; j < L->n; j++)
		L->element[j - 1] = L->element[j];
	L->n--;
	return 1;
}
//输出
int OutputSeqList(SeqList* L)
{
	int i;
	if (!L->n)
		return 0;
	for (i = 0; i < L->n; i++)
		printf("%d  ", L->element[i]);
	printf("\n");
	return 1;
}
//逆置顺序表
void Reverse(SeqList* L)
{
	int i = 0, j = L->n - 1;
	for (; (i != j) && (j > i); i++, j--)
	{
		int tmp = L->element[i];
		L->element[i] = L->element[j];
		L->element[j] = tmp;
	}
}
//撤销
int DestSeqList(SeqList* L)
{
	if (!L->element)
		return 0;
	L->maxLength = 0;
	L->n = 0;
	free(L->element);
}


//------带表头节点单链表运算
	//初始化
int InitHeaderList(HeaderList* h)
{
	h->head = (Node*)malloc(sizeof(Node));
	if (!h->head)
		return 0;
	h->head->link = NULL;
	h->n = 0;
	return 1;
}
//插入运算（x插入成为下标i+1的元素）
int InsertHeaderList(HeaderList* h, int i, int x)
{
	Node* p, * q;
	int j;
	if (i<-1 || i>h->n - 1)
		return 0;
	p = h->head;
	for (j = 0; j <= i; j++)
		p = p->link;
	q = (Node*)malloc(sizeof(Node));
	q->element = x;
	q->link = p->link;
	p->link = q;
	h->n++;
	return 1;
}
//删除下标为i的元素
int DeleteHeaderList(HeaderList* h, int i)
{
	int j;
	Node* p, * q;

	if (!h->n)
		return 0;
	if (i<0 || i>h->n - 1)
		return 0;

	q = h->head;
	for (j = 0; j < i; j++)//q的指向相比j滞后
		q = q->link;
	p = q->link;
	q->link = p->link;
	free(p);
	h->n--;
	return 1;



}
//查找下标为i的元素
int FindHeaderList(HeaderList* h, int i, int* x)
{
	Node* p = h->head->link;//保持一致
	int j;
	if (!h->n)
		return 0;
	if (i<0 || i>h->n - 1)
		return 0;


	for (j = 0; j < i; j++)
		p = p->link;
	*x = p->element;
	return 1;
}
//查找（递归法），pose指针指向目标元素下标
int Findtest(SeqList* a, int x, int* pose)
{
	if (a->element[*pose] == x)
		return 1;
	if (*pose == a->n - 1)
	{
		*pose = -1;
		return 0;
	}
	*pose += 1;
	return Findtest(a, x, pose);
}
//单链表排序  O(n^2)
 void SortHeaderList(HeaderList* h)  //升序
 {
	 Node* todo; //指向后面无序的链表
	 Node* p, * q;//用于遍历
	 Node* t;  //用于指向待排序的当前节点
	 todo = h->head->link->link; //保留第一个为有序节点
	 h->head->link->link = NULL;
	 p = q = NULL;
	 while (todo !=NULL)
	 {
		 t = todo;
		 p = h->head;
		 q = p->link; //p为q前置
		for (  ; (q != NULL) && (q->element < t->element); p = q, q = q->link);
		 //在假定有序链表中寻找待排序链表第一个元素的插入位置,即pq之间
		 todo = todo->link; //已找到插入位置的待排序元素离开原链表
		 p->link = t;
		 t->link = q;
	 }
}
//撤销
void DestHeaderList(HeaderList* h)
{
	Node* p;
	if (!h->n)
		return;

	while (h->head)
	{
		p = h->head->link;
		free(h->head);
		h->head = p;
	}

}
//输出
int OutputHeaderList(HeaderList* h)
{
	Node* p = h->head->link;

	if (!h->n)
		return 0;

	while (p)
	{
		printf("%d  ", p->element);
		p = p->link;
	}
	printf("\n");
	return 1;
}
//单链表逆置     O(n)
void InverseHeaderList(HeaderList* h)
{
	Node* p, * q, * r;
	if (!h->n)
		return;

	p = h->head->link;
	q = r = NULL;
	while (p)
	{
		r = p->link;//防止断链
		p->link = q;//p指向的反向指向前一个
		q = p;//q前进
		p = r;//p前进
	}
	h->head->link = q;
}




//-----多项式运算
	//构造多项式
void Create(Polynominal* p)
{
	PNode* pn, * pre, * q;//pn用来申请新的节点，pre与q进行链表遍历
	p->head = (PNode*)malloc(sizeof(PNode));
	p->head->exp = -1;
	p->head->link = p->head;//带表头的单循环
	for (;;)//结束条件在循环体内
	{
		pn = (PNode*)malloc(sizeof(PNode));
		printf("input coef and exp: \n");
		scanf_s("%d %d", &(pn->coef), &(pn->exp));
		if (pn->exp < 0)
		{
			//free(pn);
			break;
			//指数输入为负时break并撤销无用的临时动态空间
		}
		pre = p->head;
		q = p->head->link;
		while (q && (pn->exp < q->exp))//循环用于找第一个指数小于新节点指数的节点，找到后q指向它（无则q指向空的表头节点）
		{
			pre = q;
			q = q->link;
		}
		pn->link = q;
		pre->link = pn;
	}
}
//销毁多项式
void Destory(Polynominal* p)
{
	PNode* pn = p->head->link;
	if (p->head->link == p->head)//空表
		return;

	while (p->head->link != p->head)
	{
		p->head->link = pn->link;
		free(pn);
		pn = p->head->link;

	}
	pn = p->head;
	free(pn);
	return;
}
//多项式加法--->O(n)
void Add(Polynominal* px, Polynominal* qx)//px与qx相加，qx为结果表达式	
{
	PNode* q, * q1 = qx->head, * p, * tmp;//tmp用于生成新动态链表节点
	q = q1->link;      //q1为q的前驱，用于插入操作
	p = px->head->link;
	while (p->exp >= 0)
	{
		while (q->exp > p->exp)//跳过qx中不需要任何操作的较大项
		{
			q1 = q;
			q = q->link;

		}
		if (q->exp == p->exp) //指数相等时，相加操作
		{
			q->coef += p->coef;
			if (q->coef == 0)//相加为0，删去qx中的该节点
			{
				q1->link = q->link;
				free(q);
				q = q1->link;
				p = p->link;
			}
			else//不为0，正常后移
			{
				q1 = q;
				q = q->link;
				p = p->link;

			}

		}
		else//q->exp <p->exp  即px中存在qx没有的系数项，需新建,且新建项插入在q指向的前面
		{
			tmp = (PNode*)malloc(sizeof(PNode));
			tmp->coef = p->coef;
			tmp->exp = p->exp;
			tmp->link = q;  //插
			q1->link = tmp; //入
			q1 = q1->link;//q1保持为q的前驱
			p = p->link;

		}
	}

}
//多项式乘法
void Multip(Polynominal* px, Polynominal* qx, Polynominal* ans)//ans = px *qx
{
	PNode* p = px->head->link;//用于遍历px
	PNode* q = qx->head->link; //用于遍历qx
	PNode* tmp, * pn, * pre; // pn,pre用于ans链表遍历，tmp用于申请新节点
	 //初始化ans
	ans->head = (PNode*)malloc(sizeof(PNode));
	ans->head->exp = -1;
	ans->head->link = ans->head;
	//运算部分
	while (p->exp != -1)
	{
		while (q->exp != -1)
		{
			tmp = (PNode*)malloc(sizeof(PNode));
			tmp->coef = p->coef * q->coef;
			tmp->exp = p->exp + q->exp;
			pn = ans->head->link;
			pre = ans->head;//pre为pn前驱
			if (pn == ans->head)//为ans第一个插入节点
			{

				ans->head->link = tmp;
				tmp->link = ans->head;
				q = q->link;
			}

			else//以下操作思路参考多项式加法
			{
				while (tmp->exp < pn->exp) //跳过不需要处理的ans大项
				{
					pre = pn;
					pn = pn->link;
				}
				if (tmp->exp == pn->exp)
				{
					pn->coef += tmp->coef;
					if (pn->coef == 0)
					{
						pre->link = pn->link;
						free(pn);
						pn = pre->link;
						q = q->link;

					}
					else
						q = q->link;
				}
				else//tmp需要插入在pn前面
				{
					tmp->link = pn;
					pre->link = tmp;
					pre = pre->link;
					q = q->link;
				}


			}

		}
		p = p->link;
		q = qx->head->link;

	}

}
//打印多项式
void Printpoly(Polynominal* p)
{
	PNode* pn = p->head->link;
	int flag = 1;//标记第一项

	while (pn->exp != -1)
	{
		if (flag != 1 && pn->coef > 0) printf("+");     //不是第一项的正系数前“+”
		flag = 0;                                       //flag为0，表示不是第一项
		printf("%d", pn->coef);                         //打印系数
		switch (pn->exp) {
		case 0:break;
		case 1:printf("x"); break;
		default:printf("x^%d", pn->exp); break;
		}
		pn = pn->link;

	}
	printf("\n");
	return;


}

