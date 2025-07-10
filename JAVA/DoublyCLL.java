import java.util.*;

class node
{
    public int data;
    public node next;
    public node prev;
}

class DoublyCL
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    void InsertFirst(int no)
    {
        node newn = null;

        newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;

            last.next = first;
            first.prev = last;
        }
        else
        {
            newn.next = first;
            first.prev = newn;

            first = newn;

            last.next = first;
            first.prev = last;
        }

        iCount++;
    }

    void InsertLast(int no)
    {
        node newn = null;

        newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;

            last.next = first;
            first.prev = last;
        }
        else
        {
            last.next = newn;
            newn.prev = last;

            last = newn;

            last.next = first;
            first.prev = last;
        }

        iCount++;
    }

    void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;
        int iCnt = 0;

        if((pos < 1) || (pos > iCount + 1))
        {
            System.out.println("Invalid Position");
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
            newn = new node();

            newn.data = no;
            newn.next = null;
            newn.prev = null;

            temp = first;
            
            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;

            iCount++;
        }
    }

    void DeleteFirst()
    {
        if((first == null) && (last == null))
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;

            last.next = first;
            first.prev = last;
        }

        iCount--;
    }

    void DeleteLast()
    {
       if((first == null) && (last == null))
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            last = last.prev;

            last.next = first;
            first.prev = last;
        } 

        iCount--;
    }

    void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0;

        if((pos < 1) || (pos > iCount))
        {
            System.out.println("Invalid Position");
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
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            iCount--;
        }
        
    }

    void Display()
    {
        node temp = null;

        if((first == null) && (last == null))
        {
            return;
        }

        temp = first;

        System.out.print("<=> ");  

        do
        {
            System.out.print("| "+temp.data+" | <=> ");
            temp = temp.next;
        }while(temp != first);

        System.out.println();  
    }

    int Count()
    {
        return iCount;
    }
}

class DoublyCLL
{
    public static void main(String A[])
    {
        DoublyCL obj = new DoublyCL();

        Scanner sc = new Scanner(System.in);
        int iChoice = 0;
        int iValue = 0;
        int iPos = 0;
        int iRet = 0;

        System.out.println("\n=============================================================");
        System.out.println("                     Doubly Circular Linked List                 ");
        System.out.println("=============================================================");

        while (true) 
        {
            System.out.println("\n-------------------------------------------------------------");
            System.out.println(" Please select an option:");
            System.out.println("-------------------------------------------------------------");
            System.out.println(" 1 : Insert new node at first position");
            System.out.println(" 2 : Insert new node at last position");
            System.out.println(" 3 : Insert new node at given position");
            System.out.println(" 4 : Delete the node at first position");
            System.out.println(" 5 : Delete the node at last position");
            System.out.println(" 6 : Delete the node at given position");
            System.out.println(" 7 : Display all elements of LinkedList");
            System.out.println(" 8 : Count all elements of LinkedList");
            System.out.println(" 0 : Terminate the application");
            System.out.println("-------------------------------------------------------------");

            System.out.print("Enter your choice : ");
            iChoice = sc.nextInt();

            if (iChoice == 1) 
            {
                System.out.println("Enter the data you want to insert : ");
                iValue = sc.nextInt();
                obj.InsertFirst(iValue);
            }
            else if (iChoice == 2) 
            {
                System.out.println("Enter the data you want to insert : ");
                iValue = sc.nextInt();
                obj.InsertLast(iValue);
            }
            else if (iChoice == 3) 
            {
                System.out.println("Enter the data you want to insert : ");
                iValue = sc.nextInt();
                System.out.println("Enter the position at which you want to insert new node : ");
                iPos = sc.nextInt();
                obj.InsertAtPos(iValue, iPos);
            }
            else if (iChoice == 4) 
            {
                System.out.println("Deleting the first element form LinkedList");
                obj.DeleteFirst();
            }
            else if (iChoice == 5) 
            {
                System.out.println("Deleting the last element form LinkedList");
                obj.DeleteLast();
            }
            else if (iChoice == 6) 
            {
                System.out.println("Deleting the element from given position form Linked List");
                System.out.println("Enter the position at which you want to delete the node : ");
                iPos = sc.nextInt();
                obj.DeleteAtPos(iPos);
            }
            else if (iChoice == 7) 
            {
                System.out.println("\nElements of the Linked List are : ");
                obj.Display();
            }
            else if (iChoice == 8) 
            {
                iRet = obj.Count();
                System.out.println("\nNumber of elements in the Linked List are : " + iRet);
            }
            else if (iChoice == 0) 
            {
                System.out.println("\nThank you for using our application");
                break;
            }
            else 
            {
                System.out.println("Invalid Choice");
            }

            System.out.println("-------------------------------------------------------------");
        }
    }
}