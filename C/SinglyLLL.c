#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ",first->data);
        first = first->next;
    }

    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

void InsertFirst(PPNODE first, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

void InsertAtPos(PPNODE first, int No, int Pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int i = 0, iCount = Count(*first);

    if((Pos < 1) || (Pos > iCount + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(Pos == 1)
    {
        InsertFirst(first, No);
    }
    else if(Pos == iCount + 1)
    {
        InsertLast(first, No);
    }
    else
    {
        temp = *first;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < Pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);

        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first)->next;

        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);

        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        
        temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE first, int Pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int i = 0, iCount = Count(*first);

    if((Pos < 1) || (Pos > iCount))
    {
        printf("Invalid Position\n");
        return;
    }

    if(Pos == 1)
    {
        DeleteFirst(first);
    }
    else if(Pos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(i = 1; i < Pos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;

        free(target);
    }
}

int main()
{
    PNODE head = NULL;
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    printf("\n=============================================================\n");
    printf("                     Singly Linear Linked List                \n");
    printf("=============================================================\n");

    while(1)
    {
        printf("\n-------------------------------------------------------------\n");
        printf(" Please select an option:\n");
        printf("-------------------------------------------------------------\n");
        printf(" 1 : Insert new node at first position\n");
        printf(" 2 : Insert new node at last position\n");
        printf(" 3 : Insert new node at given position\n");
        printf(" 4 : Delete the node at first position\n");
        printf(" 5 : Delete the node at last position\n");
        printf(" 6 : Delete the node at given position\n");
        printf(" 7 : Display all elements of LinkedList\n");
        printf(" 8 : Count all elements of LinkedList\n");
        printf(" 0 : Terminate the application\n");
        printf("-------------------------------------------------------------\n");
        
        printf("Enter your choice : ");
        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter the data you want to insert : \n");
            scanf("%d",&iValue);

            InsertFirst(&head, iValue);
        }
        else if(iChoice == 2)
        {
            printf("Enter the data you want to insert : \n");
            scanf("%d",&iValue);

            InsertLast(&head, iValue);
        }
        else if(iChoice == 3)
        {
            printf("Enter the data you want to insert : \n");
            scanf("%d",&iValue);

            printf("Enter the position at which you want to insert new node : \n");
            scanf("%d",&iPos);

            InsertAtPos(&head, iValue, iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first element form LinkedList\n");

            DeleteFirst(&head);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the last element form LinkedList\n");

            DeleteLast(&head);
        }
        else if(iChoice == 6)
        {
            printf("Deleting the element from given position form Linked List\n");

            printf("Enter the position at which you want to delete the node : \n");
            scanf("%d",&iPos);

            DeleteAtPos(&head, iPos);
        }
        else if(iChoice == 7)
        {
            printf("\nElements of the Linked List are : \n");

            Display(head);
        }
        else if(iChoice == 8)
        {
            iRet = Count(head);
            printf("\nNumber of elements in the Linked List are : %d\n",iRet);
        }
        else if(iChoice == 0)
        {
            printf("\nThank you for using our application\n");
            break;
        }
        else
        {
            printf("Invalid Choice\n");
        }

        printf("-------------------------------------------------------------\n");    
    
    }

    return 0;
}