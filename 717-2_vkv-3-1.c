#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	struct node *head;
	struct node *tail;
} list;

typedef struct node
{
	int value;
	struct node *next;
} node;

//инициализация
static init(list* l)
{
	l->head = NULL;
	l->tail = l->head;
}

//очистить
void clear(list* l)
{
	node* tmp = l->head;
	node *tmp1;
	while (tmp != NULL)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
	}
	l->head = NULL;
	l->tail = NULL;
}

//проверить на пустоту
int isEmpty(list* l)
{
	if (l->head == NULL)
		return 1;
	else return 0;
}

//найти по значению
node* find(list* l, int value)
{
	node* tmp = l->head;
	while (tmp != NULL)
	{
		if (tmp->value == value)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

//втсавить в конец списка
int push_back(list* l, int value)
{
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	if (l->tail != NULL)
	{
		l->tail->next = new;
	}
	else
	{
		l->head = new;
	}
	l->tail = new;
	if (new != NULL)
	{
		return 0;
	}
}

//вставка в начало
int push_front(list* l, int value)
{
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	if (l->head == NULL)
	{
	    l->head = new;
		l->tail = new;
	}
		
	else
	{
		new->next = l->head;
		l->head = new;
	}
	if (new!= NULL)
	{
		return 0;
	}
}

//внедрение узла после указанного
int insertAfter(node* n, int value)
{
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	new->next = n->next;
	n->next = new;
}

// удалить первый элемент из списка с указанным значением
int removeNode(list* l, int value)
{
	node* f = find(l, value);
	node* tmp = l->head;
	if (f != NULL)
	{
		
		while (tmp->next != f)
		{
			tmp = tmp->next;
		}
		tmp->next = f->next;
		free(f);
		return 0;
	}
	else
	{
		return 1;
	}
}

// вывести все значения из списка в прямом порядке, через пробел, после окончания вывода перейти на новую строку
void print(list* l)
{
	if (isEmpty(l) == 0)
	{
		node* tmp = l->head;
		while (tmp != NULL)
		{
			if (tmp->next == NULL)
			{
				printf("%d", tmp->value);
				tmp = tmp->next;
			}
			else
			{
				printf("%d ", tmp->value);
				tmp = tmp->next;
			}
		}
		printf("\n");
	}
}

//ввод после j-того
void insertAfterNum(list* l, int num, int value)
{
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	node* tmp = l->head;
	int count = 1;
	while (count != num)
	{
		tmp = tmp->next;
		count++;
	}
	new->next = tmp->next;
	tmp->next = new;
}

int main()
{
	list* l = (list*)malloc(sizeof(list));
	init(l);
	int n, val;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		push_back(l, val);
	}
	print(l);
	for (int i=0; i<3; i++)
	{
	    scanf("%d", &val);
	    if (find(l, val)==NULL)
	    {
	        printf("%d", 0);
	    }
	    else 
	    {
	        printf("%d", 1);
	    }
	}
	printf("\n");
	scanf("%d", &val);
	push_back(l, val);
	print(l);
	scanf("%d", &val);
	push_front(l, val);
	print(l);
	int j;
	scanf("%d", &j);
	scanf("%d", &val);
	insertAfterNum(l, j, val);
	print(l);
	scanf("%d", &val);
	removeNode(l,val);
	print(l);
	clear(l);
}

