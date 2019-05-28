#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
    
int flag = 0;
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

void print(node* root, tree *t)
{
    if (root) {
       
        if(root->left)print(root->left,t);
        if(root->right)print(root->right,t); 
        flag++;
        if(flag != t->count) printf("%d ", root->val);
        else printf("%d\n",root->val);
         
    }
}
    
int main()
{
      tree *t = malloc(sizeof(tree));
      init(t);
      for(int i = 0; i < 7; i++)
      {
        int a; scanf("%d",&a);
        insert(t,a);
      }
     print(t->root,t);
}

