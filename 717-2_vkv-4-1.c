#include "stdio.h"
#include "stdlib.h"
    
typedef struct node
{
    int val;
    struct node* prev;
    struct node* left;
    struct node* right;
}node;
    
typedef struct tree
{
    struct node* root;
    int count;
}tree;
    
typedef struct list_node
{
    struct node *val;
    struct list_node *next;  
}list_node;
    
typedef struct list
{
    list_node *tail;
    list_node *head;   
}list;
     
void listInit(list* l)
{
    l->head = NULL;
    l->tail = NULL;
}
    
int listEmpty(list *l)
{
    int mark = (l->tail==NULL);
    return mark;
}

int push_back(list *l,node *val)
{
    list_node *tmp_l = malloc(sizeof(list_node));
    tmp_l->val = val;
    tmp_l->next = NULL;
    if(!listEmpty(l))
    {
     l->tail->next = tmp_l;
     l->tail = tmp_l;
    }
    else
    {
     l->head = l->tail = tmp_l;
    }
}

node* removeFirst(list *l)
{
    list_node *headptr = l->head;
    node *tmp = l->head->val;
    l->head = l->head->next;
    if (l->head==NULL)
        l->tail=NULL;
    free(headptr);
    return tmp;
}

int markEmpty(list *l)
{
    list_node *headptr = l->head;
    while(headptr!=NULL)
    {
        if (headptr->val!=NULL)
           return 0;
        headptr = headptr->next;
    }
    return 1;
}

void listPrint(list *l)
{
    list_node *headptr = l->head;
    while(headptr)
    {
      if(!headptr->val)
        printf("_");
      else 
        printf("%d",headptr->val->val);

      if(headptr->next)
        printf(" ");

      headptr = headptr->next;
    }
    printf("\n");
}

void init(tree *t)
    {
        t->count = 0;
        t->root = NULL;
    }
    
void clear(tree *t,list *l)
    {
      node *rootptr = t->root;
      node *tmp;
      push_back(l,rootptr);
      while(listEmpty(l))
      {
        tmp = rootptr;
        rootptr = removeFirst(l);
        free(tmp);
        if(tmp->left != NULL)
        {
            push_back(l,rootptr->left);
        }
        else if(tmp->right!=NULL) 
        {
            push_back(l,tmp->right);
        }
      }
        t->root = NULL;
    }

int find(tree *t,int val,node *n)
   {
       node *nodeptr = t->root;
       if(!nodeptr){return 1;}
       else
       {
           while(nodeptr!=NULL)
           {
               if(val > nodeptr->val)
               {
                 nodeptr = nodeptr->right;continue;
               }
               if(val < nodeptr->val)
               {
                 nodeptr = nodeptr->left; continue;
               }
               if (val == nodeptr->val)
               {
                   if(n == NULL){return 0;}
                   else {
                     printf("there");
                     n = nodeptr;
                     printf("in function find %p\n",n);
                       return 0;}
               }               
           }
       }
       return 1;
   }

void find_and_print(tree *t,int val)
   {
      node *nodeptr = t->root;
       if(!nodeptr){printf("_");}
       else
       {
           while(nodeptr!=NULL)
           {

               if(val > nodeptr->val)
               {
                 nodeptr = nodeptr->right;continue;
               }
               if(val < nodeptr->val)
               {
                 nodeptr = nodeptr->left; continue;
               }
               if (val == nodeptr->val)
               {
                 break;
               }               
           }
        if(!nodeptr->prev) printf("_ ");
        else
        {
          printf("%d ",nodeptr->prev->val);
        }
        if(!nodeptr->left) printf("_ ");
        else
        {
          printf("%d ",nodeptr->left->val);
        }
        if(!nodeptr->right)printf("_");
        else
        {
          printf("%d",nodeptr->right->val);
        }
       }
       printf("\n");
   }
void find_and_print1(tree *t,int val)
   {
      node *nodeptr = t->root;
       if(!nodeptr){printf("-");}
       else
       {
           while(nodeptr!=NULL)
           {

               if(val > nodeptr->val)
               {
                 nodeptr = nodeptr->right;continue;
               }
               if(val < nodeptr->val)
               {
                 nodeptr = nodeptr->left; continue;
               }
               if (val == nodeptr->val)
               {
                 break;
               }               
           }
        if(!nodeptr){printf("-\n"); return;}
        if(!nodeptr->prev) printf("_ ");
        else
        {
          printf("%d ",nodeptr->prev->val);
        }
        if(!nodeptr->left) printf("_ ");
        else
        {
          printf("%d ",nodeptr->left->val);
        }
        if(!nodeptr->right)printf("_");
        else
        {
          printf("%d",nodeptr->right->val);
        }
       }
       printf("\n");
  } 

int delete_tree(tree* t, int val)
    {
      node* tmp = t->root;
	  node* s;
	  node* q;
      while(tmp != NULL) 
      {
        if(tmp->val == val)
        break;

        if(val > tmp->val) 
        {
          if(tmp->right == NULL) 
             return 1;
          tmp = tmp->right;
        }
        else  
        {
          if(tmp->left == NULL) {
            return 1;
        }
          tmp = tmp->left;
        }
    }
        if(tmp->val == t->root->val) 
        {
          s = tmp;
          if(tmp->right != NULL) 
          {
            s = tmp->right;
            while(s->left != NULL) {
              s = s->left;
            }
          }
          s->prev = NULL;
          s->left = tmp->left;
          q = tmp;
          q = q->left;
          q->prev = s;
          
          t->root = s;
          free(tmp);
          t->count--;
          return 1;
        }

        return 0;
      }

int insert(tree *t,int val)
    {
            if (!t->root) 
            {
                node *tmp = malloc(sizeof(node));if(!tmp){return 2;}
                tmp->val = val;
                tmp->right = NULL;
                tmp->left = NULL;
                tmp->prev = NULL; 
                t->root = tmp;
                (t->count)++;
                return 0;   
            }
            if (!find(t,val,NULL)) return 1;
            else
            {
              node *prevptr;
              node *ptr = t->root;
              while(ptr)
              {
                 prevptr = ptr;
                  if( val < ptr->val) 
                  {
                    if(!ptr->left) 
                    {
                      node *tmp = malloc(sizeof(node));
                      if(!tmp){return 2;}
                      tmp->val = val;
                      tmp->left = NULL;
                      tmp->right = NULL;
                      tmp->prev = prevptr;
                      prevptr->left = tmp;
                      t->count ++;
                      return 0; 
                    }
                    else {ptr = ptr->left; continue;}
                  }
                  else
                  {
                    if(!ptr->right) 
                    {
                    node *tmp = malloc(sizeof(node));
                    tmp->val = val;
                    tmp->left =NULL;
                    tmp->right = NULL;
                    tmp->prev = prevptr;
                    prevptr->right = tmp;
                    t->count ++;
                    return 0; 
                    }
                    else {ptr = ptr->right; continue;}
                  }      
              }
            }
    return 1;
    }

void print (node *n,list *l)
    {
      node *rootptr = n;
      list *l_tmp = malloc(sizeof(list));
      if(!rootptr)
      {
        printf("-\n");
        return;
      }
      push_back(l,rootptr);
      listPrint(l);
      for(;;)
      {
        while(!listEmpty(l))
        {
          rootptr = removeFirst(l);
          push_back(l_tmp,rootptr);
        }
          while(!listEmpty(l_tmp))
          {
            rootptr = removeFirst(l_tmp);
            if(rootptr == NULL )
            {
              push_back(l,NULL);
              push_back(l,NULL);
            }
            else
            {
              push_back(l,rootptr->left);
              push_back(l,rootptr->right);
            }
            
          }
            if(markEmpty(l))
            {
              while(!listEmpty(l))
              removeFirst(l);   
              break;
            }
            listPrint(l);
        }
    }
 
void printTree(tree *t, list *l)
      {
        node *rootptr = t->root;
        list *l_tmp = malloc(sizeof(list));
        listInit(l_tmp);
        if(!rootptr)
        {
          printf("-\n");
          return;
        }
        push_back(l,rootptr);
        listPrint(l);
        for(;;) 
        {
          while(!listEmpty(l))
          { 
            rootptr = removeFirst(l);
            push_back(l_tmp,rootptr);
          }
            while(!listEmpty(l_tmp))
            {
              rootptr = removeFirst(l_tmp);
              if(!rootptr)
              {
                push_back(l,NULL);
                push_back(l,NULL);
              }
              else
              {
                push_back(l,rootptr->left);
                push_back(l,rootptr->right);
              }
              
            } 
              if(markEmpty(l))
              {
                while(!listEmpty(l))
                removeFirst(l);  
                break;
              }              
              listPrint(l); 
          }
      }
    
int rotateLeft(tree *t) 
    {
      node *parent = NULL,
          *C = NULL,
          *a = NULL, 
          *b = NULL;
      if (!t->root->right) return 1;
      while (t->root->right)
      {
      a = t->root;
      parent = a->prev;
      b = a->right;
      if (b == NULL) 
      {
          return 1;
      }
      C = b->left;
      b->left = a;
      a->right = C;
      if (C) 
      {
          C->prev = a;
      }
      b->prev = parent;
      if (parent) 
      {
          if (parent->left == a) 
          {
              parent->left = b;
          } 
          else 
          {
              parent->right = b;
          }
      }
      a->prev = b;
      if (!parent) 
      {
          t->root = (t->root)->prev;
      }
    }   
        return 0;
  } 

int rotareRight(tree *t) 
{
    node *parent = NULL,
    *C = NULL,
    *a = NULL, 
    *b = NULL;
    if(!t->root->left) return 1;
    while(t->root->left)
    {
          b = (t->root);
          parent = b->prev;
          a = b->left;
          if (a == NULL) 
          {
              return 1;
          }
          C = a->right;
          a->right = b;
          b->left = C;
          if (C) 
          {
              C->prev = b;
          }
          a->prev = parent;
          if (parent) 
          {
              if (parent->left == b) 
              {
                  parent->left = a;
              } 
              else 
              {
                  parent->right = a;
              }
          }
          b->prev = a;
          t->root = (t->root)->prev;
    }
   return 0;
}

void test(tree *t)
        {
          node *ptr = t->root;
          while(ptr)
          {
          printf("val :%d left:%p right:%p prev:%p\n",ptr->val,ptr->left,ptr->right,ptr->prev);
          ptr = ptr->right;
          }
        }

int main()
    {
      tree *t = malloc(sizeof(tree));
      list *l = malloc(sizeof(list));
      init(t);
      listInit(l);
      for(int i = 0; i < 4; i++)
      {
        int a; scanf("%d",&a);
        insert(t,a);
      }
     printTree(t,l);
     for(int i = 0; i < 3; i++)
     {
       int a;scanf("%d",&a);
       insert(t,a);
     }

      printTree(t,l);
     int M1;scanf("%d",&M1);
     find_and_print(t,M1);
     int M2; scanf("%d",&M2);
     find_and_print1(t,M2); 
     int M3; scanf("%d",&M3);
     delete_tree(t,M3);
     printTree(t,l);
     rotateLeft(t);
     printTree(t,l);
     rotareRight(t);
     printTree(t,l);
     printf("%d\n",t->count); 
     clear(t,l);
     printTree(t,l); 
    }

