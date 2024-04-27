/*******************************************************************
 *
 *	file name:	CircularLink.c
 *	author	 :  m17872844806@163.com
 *	date	 :  2024/04/27
 *	function :  单向循环链表的插，删
 * 	note	 :  None
 *
 *	CopyRight (c)  2023-2024   m17872844806@163.com  All Right Reseverd
 *
 * *****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 指的是单向循环链表中的结点有效数据类型，用户可以根据需要进行修改
typedef int DataType_t;

// 构造单向循环链表的结点,链表中所有结点的数据类型应该是相同的
typedef struct CircularLinkedList
{
	DataType_t data;				 // 结点的数据域
	struct CircularLinkedList *next; // 结点的指针域

} CircLList_t;

// 创建一个空单向循环链表，空链表应该有一个头结点，对链表进行初始化
CircLList_t *CircLList_Create(void)
{
	// 1.创建一个头结点并对头结点申请内存
	CircLList_t *Head = (CircLList_t *)calloc(1, sizeof(CircLList_t));
	if (NULL == Head)
	{
		perror("Calloc memory for Head is Failed");
		exit(-1);
	}

	// 2.对头结点进行初始化，头结点是不存储数据域，指针域指向自身，体现“循环”思想
	Head->next = Head;

	// 3.把头结点的地址返回即可
	return Head;
}

// 创建新的结点，并对新结点进行初始化（数据域 + 指针域）
CircLList_t *CircLList_NewNode(DataType_t data)
{
	// 1.创建一个新结点并对新结点申请内存
	CircLList_t *New = (CircLList_t *)calloc(1, sizeof(CircLList_t));
	if (NULL == New)
	{
		perror("Calloc memory for NewNode is Failed");
		return NULL;
	}

	// 2.对新结点的数据域和指针域进行初始化
	New->data = data;
	New->next = NULL;

	return New;
}

// 头插
/*******************************************************************
 *
 *	函数名称:	 CircLList_HeadInsert
 *	函数功能:   在单向循环链表头部插入新的结点
 * 	函数参数:
 *  				@a :CircLList_t *Head  头结点
 *  				@b :DataType_t data 新结点的数据域
 *   返回结果:
 * 	注意事项:   None
 * 	函数作者:  m17872844806@163.com
 *	创建日期:   2024/04/22
 *	修改历史:
 *	函数版本:	V1.0
 * *****************************************************************/
bool CircLList_HeadInsert(CircLList_t *Head, DataType_t data)
{
	CircLList_t *New = CircLList_NewNode(data);
	CircLList_t *Phead = Head;

	if (NULL == New)
	{
		printf("can not insert new node\n");
		return false;
	}
	if (Head->next == Head)
	{
		Head->next = New;
		New->next = New;
		return true;
	}
	while (Phead->next)
	{
		Phead = Phead->next;
		if (Phead->next == Head->next)
		{
			break;
		}
	}
	New->next = Head->next; // 改动
	Head->next = New;
	Phead->next = New;

	return true;
}

// 尾插
/*******************************************************************
 *
 *	函数名称:	 CircLList_TailInsert
 *	函数功能:   在单向循环链表尾部插入新的结点
 * 	函数参数:
 *  				@a :CircLList_t *Head  头结点
 *  				@b :DataType_t data 新结点的数据域
 *   返回结果:
 * 	注意事项:   None
 * 	函数作者:  m17872844806@163.com
 *	创建日期:   2024/04/22
 *	修改历史:
 *	函数版本:	V1.0
 * *****************************************************************/
bool CircLList_TailInsert(CircLList_t *Head, DataType_t data)
{
	CircLList_t *New = CircLList_NewNode(data);
	CircLList_t *Phead = Head;
	if (NULL == New)
	{
		printf("can not insert new node\n");
		return false;
	}
	if (Head->next == Head)
	{
		Head->next = New;
		New->next = New;
		return true;
	}
	while (Phead->next)
	{
		// 把头结点的直接后继作为新的头结点
		Phead = Phead->next;
		if (Phead->next == Head->next)
		{
			break;
		}
	}
	Phead->next = New;
	New->next = Head->next;
	return true;
}

// 指定位置插入
/*******************************************************************
 *
 *	函数名称:	 CircLList_DestInsert
 *	函数功能:   在单向循环链表指定部位插入新的结点
 * 	函数参数:
 *  				@a :CircLList_t *Head  头结点
 *  				@b :DataType_t data    新结点的数据域
 *  				@c :DataType_t destval 目标结点的数据域
 *   返回结果:
 * 	注意事项:   None
 * 	函数作者:  m17872844806@163.com
 *	创建日期:   2024/04/22
 *	修改历史:
 *	函数版本:	V1.0
 * *****************************************************************/
bool CircLList_DestInsert(CircLList_t *Head, DataType_t destval, DataType_t data)
{
	CircLList_t *New = CircLList_NewNode(data);
	CircLList_t *Phead = Head->next;
	;
	if (NULL == New)
	{
		printf("can not insert new node\n");
		return false;
	}
	// if (Head->next == Head)
	// {
	// 	Head->next = New;
	// 	New->next = New;
	// 	return true;
	// }
	while (Phead->next)
	{
		// 把头结点的直接后继作为新的头结点

		Phead = Phead->next;
		printf("1");
		if (Phead->data = destval)
		{
			break;
		}
	}
	New->next = Phead->next;
	Phead->next = New;
}

bool CircLList_HeadDel(CircLList_t *Head)
{
	printf("2");
	// 对单向循环链表的头结点的地址进行备份
	CircLList_t *Temp = Head;
	CircLList_t *Phead = Head->next;
	if (Head->next == Head)
	{
		printf("current linkeflist is empty!\n");
		printf("3");
		return false;
	}
	if (Head->next = Head->next->next)
	{
		Temp->next = NULL;
		Head->next = Head;
		free(Temp);
		return true;
	}
	// while(Temp->next)
	// {
	// 	//把头结点的直接后继作为新的头结点
	// 	Temp = Temp->next;
	// 	printf("1");
	// 	//判断是否到达尾结点，尾结点的next指针是指向首结点的地址
	// 	if (Temp->next == Head->next)
	// 	{
	// 		break;
	// 	}
	// }
	// printf("5");
	// Temp->next=Head->next->next;
	// Head->next=Head->next->next;
	// Phead->next=NULL;
	// free(Phead);
	return true;
}

// 遍历链表
bool CircLList_Print(CircLList_t *Head)
{
	// 对单向循环链表的头结点的地址进行备份
	CircLList_t *Phead = Head;

	// 判断当前链表是否为空，为空则直接退出
	if (Head->next == Head)
	{
		printf("current linkeflist is empty!\n");
		return false;
	}

	// 从首结点开始遍历
	while (Phead->next)
	{
		// 把头结点的直接后继作为新的头结点
		Phead = Phead->next;

		// 输出头结点的直接后继的数据域
		printf("data = %d\n", Phead->data);

		// 判断是否到达尾结点，尾结点的next指针是指向首结点的地址
		if (Phead->next == Head->next)
		{
			break;
		}
	}

	return true;
}

// 头删

int main(int argc, char const *argv[])
{
	CircLList_t *phe = CircLList_Create();
	CircLList_HeadInsert(phe, 30);
	CircLList_HeadInsert(phe, 20);
	CircLList_HeadInsert(phe, 10);
	CircLList_TailInsert(phe, 50);
	CircLList_DestInsert(phe, 30, 40);
	// CircLList_HeadDel(phe);
	CircLList_Print(phe);
	return 0;
}
