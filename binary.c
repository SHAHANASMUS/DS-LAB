#include <stdio.h>
#include <stdlib.h>
struct btnode
{
int value;
struct btnode *l;
struct btnode *r;
} *root = NULL, *temp = NULL, *t2, *t1, *tl;
void delete1();
void insert();
void delete();
void inorder(struct btnode *t);
void create();
void search(struct btnode *t);
void search1(struct btnode *t, int data);
void deletel(struct btnode *t);
int smallest(struct btnode *t);
int main()
{
int ch;
printf("\n----BST OPERATIONS ---");
printf("\n1 - Insert an element into tree\n");
printf("2 - Delete an element from the tree\n");
printf("3 - Inorder Traversal\n");
printf("4 - Exit\n");
while (1)
{
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
insert();
break;
case 2:
delete1();
break;
case 3:
inorder(root);
break;
case 4:
exit(0);
default:
printf("Wrong choice, Please enter correct choice ");
}
}
return 0;
}
void insert()
{
create();
if (root == NULL)
root = temp;
else
search(root);
}
void create()
{
int data;
printf("Enter data of node to be inserted : ");
scanf("%d", &data);
temp = (struct btnode *)malloc(1 * sizeof(struct btnode));
temp->value = data;
temp->l = temp->r = NULL;
}
void search(struct btnode *t)
{
if (t == NULL)
{
return;
}
if ((temp->value > t->value) && (t->r != NULL))
search(t->r);
else if ((temp->value > t->value) && (t->r == NULL))
t->r = temp;
else if ((temp->value < t->value) && (t->l != NULL))
search(t->l);
else if ((temp->value < t->value) && (t->l == NULL))
t->l =temp;
}
void inorder(struct btnode *t)
{
if (root == NULL)
{
printf("No elements in a tree to display");
return;
}
if (t->l != NULL)
inorder(t->l);
printf("%d -> ", t->value);
if (t->r != NULL)
inorder(t->r);
}
void delete1()
{
int data;
if (root == NULL)
{
printf("No elements in the tree to delete");
return;
}
printf("Enter the data to be deleted: ");
scanf("%d", &data);
t1 = NULL;
search1(root, data);
if (t1 == NULL)
{
printf("Element not found in the tree");
}
else
{
deletel(t1);
}
}
void search1(struct btnode *t, int data)
{
if (t == NULL)
{
return;
}
if (data > t->value)
{
tl = t;
search1(t->r, data);
}
else if (data < t->value)
{
tl = t;
search1(t->l, data);
}
else if (data == t->value)
{
t1 = t;
}
else
{
t1 = NULL;
}
}
void deletel(struct btnode *t)
{
int k;
if (t->l == NULL && t->r == NULL)
{
if (tl->l == t)
{
tl->l = NULL;
}
else
{
tl->r = NULL;
}
free(t);
return;
}
else if (t->r == NULL)
{
if (t1 == t)
{
root = t->l;
tl = root;
}
else if (tl->l == t)
{
tl->l = t->l;
}
else
{
tl->r = t->l;
}
free(t);
return;
}
else if (t->l == NULL)
{
if (t1 == t)
{
root = t->r;
tl = root;
}
else if (tl->r == t)
{
tl->r = t->r;
}
else
{
tl->l = t->r;
}
free(t);
return;
}
else if (t->l != NULL && t->r != NULL)
{
k = smallest(t->r);
deletel(t->r);
t->value = k;
}
}
int smallest(struct btnode *t)
{
if (t->l != NULL)
return (smallest(t->l));
else
return (t->value);
}
