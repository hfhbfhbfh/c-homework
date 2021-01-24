#include<stdio.h>
#include<stdlib.h>
//˳���ṹ
typedef struct seqlist
{
	int n;
	int maxLength;
	int* element;
}SeqList;
//����ṹ
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
//����ʽ������ͷ�ĵ�ѭ������
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

//-------���Ա�����
	//��ʼ��
int InitSeqList(SeqList* L, int msize)
{
	L->maxLength = msize;
	L->n = 0;
	L->element = (int*)malloc(sizeof(int) * msize);
	if (!L->element)
		return 0;
	return 1;
}
//���ң��±�Ϊi��
int FindSeqList(SeqList L, int i, int* x)
{
	if (i<0 || i>L.n - 1)
		return 0;
	*x = L.element[i];
	return 1;
}
//���루x��Ϊ�±�Ϊi+1��Ԫ�أ�
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
//ɾ�����±�Ϊi��
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
//���
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
//����˳���
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
//����
int DestSeqList(SeqList* L)
{
	if (!L->element)
		return 0;
	L->maxLength = 0;
	L->n = 0;
	free(L->element);
}


//------����ͷ�ڵ㵥��������
	//��ʼ��
int InitHeaderList(HeaderList* h)
{
	h->head = (Node*)malloc(sizeof(Node));
	if (!h->head)
		return 0;
	h->head->link = NULL;
	h->n = 0;
	return 1;
}
//�������㣨x�����Ϊ�±�i+1��Ԫ�أ�
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
//ɾ���±�Ϊi��Ԫ��
int DeleteHeaderList(HeaderList* h, int i)
{
	int j;
	Node* p, * q;

	if (!h->n)
		return 0;
	if (i<0 || i>h->n - 1)
		return 0;

	q = h->head;
	for (j = 0; j < i; j++)//q��ָ�����j�ͺ�
		q = q->link;
	p = q->link;
	q->link = p->link;
	free(p);
	h->n--;
	return 1;



}
//�����±�Ϊi��Ԫ��
int FindHeaderList(HeaderList* h, int i, int* x)
{
	Node* p = h->head->link;//����һ��
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
//���ң��ݹ鷨����poseָ��ָ��Ŀ��Ԫ���±�
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
//����������  O(n^2)
 void SortHeaderList(HeaderList* h)  //����
 {
	 Node* todo; //ָ��������������
	 Node* p, * q;//���ڱ���
	 Node* t;  //����ָ�������ĵ�ǰ�ڵ�
	 todo = h->head->link->link; //������һ��Ϊ����ڵ�
	 h->head->link->link = NULL;
	 p = q = NULL;
	 while (todo !=NULL)
	 {
		 t = todo;
		 p = h->head;
		 q = p->link; //pΪqǰ��
		for (  ; (q != NULL) && (q->element < t->element); p = q, q = q->link);
		 //�ڼٶ�����������Ѱ�Ҵ����������һ��Ԫ�صĲ���λ��,��pq֮��
		 todo = todo->link; //���ҵ�����λ�õĴ�����Ԫ���뿪ԭ����
		 p->link = t;
		 t->link = q;
	 }
}
//����
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
//���
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
//����������     O(n)
void InverseHeaderList(HeaderList* h)
{
	Node* p, * q, * r;
	if (!h->n)
		return;

	p = h->head->link;
	q = r = NULL;
	while (p)
	{
		r = p->link;//��ֹ����
		p->link = q;//pָ��ķ���ָ��ǰһ��
		q = p;//qǰ��
		p = r;//pǰ��
	}
	h->head->link = q;
}




//-----����ʽ����
	//�������ʽ
void Create(Polynominal* p)
{
	PNode* pn, * pre, * q;//pn���������µĽڵ㣬pre��q�����������
	p->head = (PNode*)malloc(sizeof(PNode));
	p->head->exp = -1;
	p->head->link = p->head;//����ͷ�ĵ�ѭ��
	for (;;)//����������ѭ������
	{
		pn = (PNode*)malloc(sizeof(PNode));
		printf("input coef and exp: \n");
		scanf_s("%d %d", &(pn->coef), &(pn->exp));
		if (pn->exp < 0)
		{
			//free(pn);
			break;
			//ָ������Ϊ��ʱbreak���������õ���ʱ��̬�ռ�
		}
		pre = p->head;
		q = p->head->link;
		while (q && (pn->exp < q->exp))//ѭ�������ҵ�һ��ָ��С���½ڵ�ָ���Ľڵ㣬�ҵ���qָ����������qָ��յı�ͷ�ڵ㣩
		{
			pre = q;
			q = q->link;
		}
		pn->link = q;
		pre->link = pn;
	}
}
//���ٶ���ʽ
void Destory(Polynominal* p)
{
	PNode* pn = p->head->link;
	if (p->head->link == p->head)//�ձ�
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
//����ʽ�ӷ�--->O(n)
void Add(Polynominal* px, Polynominal* qx)//px��qx��ӣ�qxΪ������ʽ	
{
	PNode* q, * q1 = qx->head, * p, * tmp;//tmp���������¶�̬����ڵ�
	q = q1->link;      //q1Ϊq��ǰ�������ڲ������
	p = px->head->link;
	while (p->exp >= 0)
	{
		while (q->exp > p->exp)//����qx�в���Ҫ�κβ����Ľϴ���
		{
			q1 = q;
			q = q->link;

		}
		if (q->exp == p->exp) //ָ�����ʱ����Ӳ���
		{
			q->coef += p->coef;
			if (q->coef == 0)//���Ϊ0��ɾȥqx�еĸýڵ�
			{
				q1->link = q->link;
				free(q);
				q = q1->link;
				p = p->link;
			}
			else//��Ϊ0����������
			{
				q1 = q;
				q = q->link;
				p = p->link;

			}

		}
		else//q->exp <p->exp  ��px�д���qxû�е�ϵ������½�,���½��������qָ���ǰ��
		{
			tmp = (PNode*)malloc(sizeof(PNode));
			tmp->coef = p->coef;
			tmp->exp = p->exp;
			tmp->link = q;  //��
			q1->link = tmp; //��
			q1 = q1->link;//q1����Ϊq��ǰ��
			p = p->link;

		}
	}

}
//����ʽ�˷�
void Multip(Polynominal* px, Polynominal* qx, Polynominal* ans)//ans = px *qx
{
	PNode* p = px->head->link;//���ڱ���px
	PNode* q = qx->head->link; //���ڱ���qx
	PNode* tmp, * pn, * pre; // pn,pre����ans���������tmp���������½ڵ�
	 //��ʼ��ans
	ans->head = (PNode*)malloc(sizeof(PNode));
	ans->head->exp = -1;
	ans->head->link = ans->head;
	//���㲿��
	while (p->exp != -1)
	{
		while (q->exp != -1)
		{
			tmp = (PNode*)malloc(sizeof(PNode));
			tmp->coef = p->coef * q->coef;
			tmp->exp = p->exp + q->exp;
			pn = ans->head->link;
			pre = ans->head;//preΪpnǰ��
			if (pn == ans->head)//Ϊans��һ������ڵ�
			{

				ans->head->link = tmp;
				tmp->link = ans->head;
				q = q->link;
			}

			else//���²���˼·�ο�����ʽ�ӷ�
			{
				while (tmp->exp < pn->exp) //��������Ҫ�����ans����
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
				else//tmp��Ҫ������pnǰ��
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
//��ӡ����ʽ
void Printpoly(Polynominal* p)
{
	PNode* pn = p->head->link;
	int flag = 1;//��ǵ�һ��

	while (pn->exp != -1)
	{
		if (flag != 1 && pn->coef > 0) printf("+");     //���ǵ�һ�����ϵ��ǰ��+��
		flag = 0;                                       //flagΪ0����ʾ���ǵ�һ��
		printf("%d", pn->coef);                         //��ӡϵ��
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

