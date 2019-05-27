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
	struct node *prev;
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
	{
		return 1;
	}
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
	if (isEmpty(l))
	{
		l->head = new;
		l->tail = new;
	}
	else
	{
		new->prev = l->tail;
		new->next = NULL;
		l->tail->next = new;
			l->tail = new;
	}
}

//вставка в начало
int push_front(list* l, int value)
{
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	if (isEmpty(l))
	{
		l->head = new;
		l->tail = new;
	}
	else
	{
		new->next = l->head;
		new->prev = NULL;
		l->head->prev = new;
		l->head = new;
	}
}

//внедрение узла после указанного
int insertAfter(node* n, int value)
{
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	new->next = n->next;
	n->next = new;
	new->prev = n;
	new->next->prev = new;
}

int insertBefore(node* n, int value)
{
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	new->prev = n->prev;
	new->next = n;
	n->prev = new;
	new->prev->next = new;
}

int removeFirst(list* l, int value)
{
	node* f = find(l, value);
	if (f != NULL)
	{
		if (f == l->head)
		{
			l->head = l->head->next;
			l->head->prev = NULL;
		}
		else if (f == l->tail)
		{
			l->tail = l->tail->prev;
			l->tail->next = NULL;
		}
		else
		{
			f->prev->next = f->next;
			f->next->prev = f->prev;
		}
		free(f);
		return 0;
	}

}

node* findEnd(list* l, int value)
{
	node* tmp = l->tail;
	while (tmp != NULL)
	{
		if (tmp->value == value)
		{
			return tmp;
		}
		tmp = tmp->prev;
	}
	return NULL;
}

int removeLast(list* l, int value)
{
	node* f = findEnd(l, value);
	if (f != NULL)
	{
		if (f == l->head)
		{
			l->head = l->head->next;
			l->head->prev = NULL;
		}
		else if (f == l->tail)
		{
			l->tail = l->tail->prev;
			l->tail->next = NULL;
		}
		else
		{
			f->prev->next = f->next;
			f->next->prev = f->prev;
		}
		free(f);
		return 0;
	}

}

//вывод в прямом порядке
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

// вывести все значения из списка в обратном порядке, через пробел, после окончания вывода перейти на новую строку
void print_invers(list* l)  //1
{
	node* tmp = l->tail;
	while (tmp != NULL)
	{
		if (tmp->prev == NULL)
		{
			printf("%d", tmp->value);
		}
		else
		{
			printf("%d ", tmp->value);
		}

		tmp = tmp->prev;
	}
	printf("\n");
}

//поиск j-того элемента
node* findNum(list* l, int num)   //находит j-й узел
{
	node* tmp = l->head;
	int count = 1;
	while (count != num)
	{
		tmp = tmp->next;
		count++;
	}
	return tmp;
}

//ввод после j-того
void insertAfterNum(list* l, int num, int value)
{
	insertAfter(findNum(l, num), value);
}

void insertBeforeNum(list* l, int num, int value)
{
	insertBefore(findNum(l, num), value);
}

int main()
{
	list* l = (list*)malloc(sizeof(list));
	init(l);

	int n, a, k, m, t, j, x, u, y, z, r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		push_back(l, a);
	}
	print(l);

	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &k);
		if (find(l, k) != NULL)
		{
			printf("%d", 1);
		}
		else
		{
			printf("%d", 0);
		}
	}
	printf("\n");

	scanf("%d", &m);
	push_back(l, m);
	print_invers(l);

	scanf("%d", &t);
	push_front(l, t);
	print(l);

	scanf("%d%d", &j, &x);
	insertAfterNum(l, j, x);
	print_invers(l);

	scanf("%d%d", &u, &y);
	insertBeforeNum(l, u, y);
	print(l);
	scanf("%d", &z);

	removeFirst(l, z);
	print_invers(l);
	scanf("%d", &r);

	removeLast(l, r);
	print(l);

	clear(l);
	return 0;
}

