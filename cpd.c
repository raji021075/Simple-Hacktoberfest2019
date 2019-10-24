#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}node;

int option();
struct node * InsertAtBeg(int, struct node *);
struct node * InsertAtEnd(int, struct node *);
struct node * InsertAfter(int, int, struct node *);
struct node * delNum(int, struct node *);
void display(struct node *);

int main()
{
  struct node *head = NULL;
  int opt, num, reqnum;
  opt = option();
  while(opt <= 6)
  {
    switch(opt)
    {
      case 1:
        printf("Enter the number\n");
        scanf("%d", &num);
        head = InsertAtBeg(num, head);
        printf("The list is as follows\n");
        break;

      case 2:
        printf("Enter the number\n");
        scanf("%d", &num);
        head = InsertAtEnd(num, head);
        break;
      
      case 3:
        printf("Enter the number\n");
	scanf("%d", &num);
        printf("Enter the number after which the above number will be inserted\n");
        scanf("%d", &reqnum);
        head = InsertAfter(num, reqnum, head);
        break;

      case 4 ... 6:
        printf("Enter the number\n");
        scanf("%d", &num);
        head = delNum(num, head);
        break;

      case 7:
	display(head);
        break;
      case 8:
        exit(0);	
    }
    opt = option();
  }
}

int option()
{
  int op;
  printf("1.Insert an element in the beginning of the list\n");
  printf("2.Insert at the end of the list\n");
  printf("3.Insert after an number in the list\n");
  printf("4.Delete beginning number from the list\n5.Delete end number \n6.Delete any number\n");
  printf("7.Display\n8.Exit\n");
  scanf("%d", &op);
  
  return op;
}

struct node * InsertAtBeg(int num, struct node *head)
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = num;

  if(head == NULL)
  {
    head = temp;
    head->next = NULL;
    return head;
  }
  else
  {
    temp->next = head;
    head = temp;
    return head;
  }
}

struct node * InsertAtEnd(int num, struct node *head)
{
  struct node *temp1, *temp2;
  temp1 = (struct node *)malloc(sizeof(struct node));
  temp1->data = num;

  temp2 = head;
  if(head == NULL)
  {
    head = temp1;
    head->next = NULL;
    return head;
  }
  else
  {
    while(temp2->next != NULL)
      temp2 = temp2->next;

    temp1->next = NULL;
    temp2->next = temp1;
    return head;
  }
}

struct node * InsertAfter(int num, int reqnum, struct node *head)
{
  if(head == NULL)
  {
    printf("The list is empty\n");
    return head;
  }
  else
  {
    struct node *temp1, *temp2;
    temp2 = head;
    do
    {
      if(temp2->data == reqnum)
      {
        temp1 = (struct node *)malloc(sizeof(struct node));
        temp1->data = num;
        temp1->next = temp2->next;
        temp2->next = temp1;
        return head;
      }
      temp2 = temp2->next;
    }while(temp2 != NULL);

    if(temp2 == NULL)
    {
      printf("The number given not found\n");
      return head;
    }
  }
  return head;
}

struct node * delNum(int num, struct node *head)
{
  if(head == NULL)
  {
    printf("The list is empty\n");
    return head;
  }
  else if(head->data == num)
  {
    head = head->next;
    printf("The element is deleted from the list\n");
    return head;
  }
  struct node *temp1, *temp2;
  temp2 = head;
  temp1 = head->next;
  while(temp1 != NULL)
  {
    if(temp1->data == num)
    {
      temp2->next = temp1->next;
      free(temp1);
      printf("The element is deleted from the list\n");
      return head;
    }
    temp2 = temp1;
    temp1 = temp1->next;
  }

  if(temp1 == NULL)
  {
    printf("The given element not found\n");
    return head;
  }
  return head;
}

void display(struct node *head)
{
  if(head == NULL)
  {
    printf("The list is empty\n");
    return;
  }
  struct node *temp;
  temp = head;
  while(temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
