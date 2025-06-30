#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE first, PNODE last)
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }

    printf(" <=> ");
    do
    {
        printf("| %d | <=> ",first->data);
        first = first->next;
    }while(first != last->next);

    printf("\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    if((first == NULL) && (last == NULL))
    {
        return iCount;
    }
    
    do
    {
        iCount++;
        first = first->next;

    }while(first != last->next);

    return iCount;
}

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;
        (*first)->prev = *last;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;

        *first = newn;

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;
        (*first)->prev = *last;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;

        *last = newn;

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0, iCount = 0;

    iCount = Count(*first, *last);

    if((pos < 1) || (pos > iCount + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, last, no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(first, last, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

void DeleteFirst(PPNODE first, PPNODE last)
{
    if((*first == NULL) && (*last == NULL))
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
    if((*first == NULL) && (*last == NULL))
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else
    {
        *last = (*last)->prev;
        free((*last)->next);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int iCnt = 0, iCount = 0;

    iCount = Count(*first, *last);

    if((pos < 1) || (pos > iCount))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if(pos == iCount)
    {
        DeleteLast(first, last);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }


        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        free(target);
    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    printf("\n=============================================================\n");
    printf("                     Doubly Circular Linked List              \n");
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

            InsertFirst(&head, &tail, iValue);
        }
        else if(iChoice == 2)
        {
            printf("Enter the data you want to insert : \n");
            scanf("%d",&iValue);

            InsertLast(&head, &tail, iValue);
        }
        else if(iChoice == 3)
        {
            printf("Enter the data you want to insert : \n");
            scanf("%d",&iValue);

            printf("Enter the position at which you want to insert new node : \n");
            scanf("%d",&iPos);

            InsertAtPos(&head, &tail, iValue, iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first element form LinkedList\n");

            DeleteFirst(&head, &tail);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the last element form LinkedList\n");

            DeleteLast(&head, &tail);
        }
        else if(iChoice == 6)
        {
            printf("Deleting the element from given position form Linked List\n");

            printf("Enter the position at which you want to delete the node : \n");
            scanf("%d",&iPos);

            DeleteAtPos(&head, &tail, iPos);
        }
        else if(iChoice == 7)
        {
            printf("\nElements of the Linked List are : \n");

            Display(head, tail);
        }
        else if(iChoice == 8)
        {
            iRet = Count(head, tail);
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