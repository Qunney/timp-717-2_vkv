#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
    
typedef struct node
{
    int val;
    struct node* prev;
    struct node* left;
    struct node* right;
    int vst;
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
    int vst = (l->tail==NULL);
    return vst;
}

int push_front(list *l,node* val){
    list_node *tmp = malloc(sizeof(node));
    tmp->val = val;
    if(l->head==NULL && l->tail==NULL)
    {
        l->tail=tmp;
        l->head=tmp;
        tmp->next = NULL;
        return 0;
    }
    else
    {
       list_node *ptr = l->head;
       tmp->next = ptr;
       l->head = tmp;
       return 0;
    }
    return 1;
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

void init(tree *t)
    {
        t->count = 0;
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
                     n = nodeptr;
                     return 0;}
               }               
           }
       }
       return 1;
   }

int insert(tree *t,int val)
    {
            if (!t->root) 
            {
                node *tmp = malloc(sizeof(node));
                if(!tmp){return 2;}
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
                    else {ptr = ptr->left; 
                    continue;}
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

void printTree(tree *t, list *l)
{
      node *rootptr = t->root;
      int count = 0;
      push_front(l,t->root);
      while(!listEmpty(l))
      {
        node *tmp = removeFirst(l);
        count ++;
        if(count!=t->count) printf("%d ",tmp->val);
        else printf("%d\n",tmp->val);
        if(tmp->right){push_front(l,tmp->right);}
        if(tmp->left)push_front(l,tmp->left);
        } 
}
    
int main()
{
      tree *t = malloc(sizeof(tree));
      list *l = malloc(sizeof(list));
      init(t);
      listInit(l);
      for(int i = 0; i < 7; i++)
      {
        int a; scanf("%d",&a);
        insert(t,a);
      }
     printTree(t,l);
}

