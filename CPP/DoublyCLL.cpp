#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        
        DoublyCLL()
        {
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if((first == NULL) && (last == NULL))
            {
                first = newn;
                last = newn;

                last->next = first;
                first->prev = last;
            }
            else
            {
                newn->next = first;
                first->prev = newn;

                first = newn;

                last->next = first;
                first->prev = last;
            }

            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if((first == NULL) && (last == NULL))
            {
                first = newn;
                last = newn;

                last->next = first;
                first->prev = last;
            }
            else
            {
                last->next = newn;
                newn->prev = last;

                last = newn;

                last->next = first;
                first->prev = last;
            }

            iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            int iCnt = 0;

            if((pos < 1) || (pos > iCount + 1))
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(pos == 1)
            {   
                InsertFirst(no);
            }
            else if(pos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                newn->next->prev = newn;
                temp->next = newn;
                newn->prev = temp;

                iCount++;
            }
        }

        void DeleteFirst()
        {
            if((first == NULL) && (last == NULL))
            {
                return;
            }
            else if(first == last)
            {
                delete first;

                first = NULL;
                last = NULL;
            }
            else
            {
                first = first->next;
                delete first->prev;
    
                last->next = first;
                first->prev = last;
            }

            iCount--;
        }

        void DeleteLast()
        {
            if((first == NULL) && (last == NULL))
            {
                return;
            }
            else if(first == last)
            {
                delete first;

                first = NULL;
                last = NULL;
            }
            else
            {
                last = last->prev;

                delete last->next;

                last->next = first;
                first->prev = last;
            }

            iCount--;
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;
            int iCnt = 0;

            if((pos < 1) || (pos > iCount))
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(pos == 1)
            {   
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp->next;
                }

                target = temp->next;

                temp->next = target->next;
                target->next->prev = temp;

                delete target;
                
                iCount--;
            }
        }

        void Display()
        {
            PNODE temp = NULL;
            temp = first;

            if((first == NULL) && (last == NULL))
            {
                return;
            }

            cout<<" <=>";
            do
            {
                cout<<" | "<<temp->data<<" | <=> ";
                temp = temp->next;

            }while(temp != last->next);

            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    DoublyCLL obj;

    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    cout<<"\n=============================================================\n";
    cout<<"                    Doubly Circular Linked List                \n";
    cout<<"=============================================================\n";

    while(1)
    {
        cout<<"\n-------------------------------------------------------------\n";
        cout<<" Please select an option:\n";
        cout<<"-------------------------------------------------------------\n";
        cout<<" 1 : Insert new node at first position\n";
        cout<<" 2 : Insert new node at last position\n";
        cout<<" 3 : Insert new node at given position\n";
        cout<<" 4 : Delete the node at first position\n";
        cout<<" 5 : Delete the node at last position\n";
        cout<<" 6 : Delete the node at given position\n";
        cout<<" 7 : Display all elements of LinkedList\n";
        cout<<" 8 : Count all elements of LinkedList\n";
        cout<<" 0 : Terminate the application\n";
        cout<<"-------------------------------------------------------------\n";

        cout<<"Enter your choice : ";
        cin>>iChoice;

        if(iChoice == 1)
        {
            cout<<"Enter the data you want to insert : \n";
            cin>>iValue;

            obj.InsertFirst(iValue);
        }
        else if(iChoice == 2)
        {
            cout<<"Enter the data you want to insert : \n";
            cin>>iValue;

            obj.InsertLast(iValue);
        }
        else if(iChoice == 3)
        {
            cout<<"Enter the data you want to insert : \n";
            cin>>iValue;

            cout<<"Enter the position at which you want to insert new node : \n";
            cin>>iPos;

            obj.InsertAtPos(iValue, iPos);
        }
        else if(iChoice == 4)
        {
            cout<<"Deleting the first element form LinkedList\n";

            obj.DeleteFirst();
        }
        else if(iChoice == 5)
        {
            cout<<"Deleting the last element form LinkedList\n";

            obj.DeleteLast();
        }
        else if(iChoice == 6)
        {
            cout<<"Deleting the element from given position form Linked List\n";

            cout<<"Enter the position at which you want to delete the node : \n";
            cin>>iPos;

            obj.DeleteAtPos(iPos);
        }
        else if(iChoice == 7)
        {
            cout<<"\nElements of the Linked List are : \n";

            obj.Display();
        }
        else if(iChoice == 8)
        {
            iRet = obj.Count();
            cout<<"\nNumber of elements in the Linked List are : "<<iRet<<"\n";
        }
        else if(iChoice == 0)
        {
            cout<<"\nThank you for using our application\n";
            break;
        }
        else
        {
            cout<<"Invalid Choice\n";
        }

        cout<<"-------------------------------------------------------------\n";
    }

    return 0;
}