import java.util.*;

class node
{
    public int data;
    public node next;
}

class SinglyLL
{
    private node first;
    private int iCount;

    public SinglyLL()
    {
        first = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node();

        newn.data = no;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }

        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node();

        newn.data = no;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {   
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }

        iCount++;
    }

    public void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;
        int iCnt = 0;

        if((pos  < 1) || (pos > iCount + 1))
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

            temp = first;

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }
    }

    void DeleteFirst()
    {
        node temp = null;

        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
        }

        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            temp = first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }

        iCount--;
    }

    public void DeleteAtPos(int pos)
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

            iCount--;
        }
    }

    public void Display()
    {
        node temp = null;

        temp = first;

        while(temp != null)
        {
            System.out.print("| "+temp.data+" | -> ");
            temp = temp.next;
        }

        System.out.println("null");
    }

    public int Count()
    {
        return iCount;
    }
}

class SinglyLLL
{
    public static void main(String A[])
    {
        SinglyLL obj = new SinglyLL();

        Scanner sc = new Scanner(System.in);
        int iChoice = 0;
        int iValue = 0;
        int iPos = 0;
        int iRet = 0;

        System.out.println("\n=============================================================");
        System.out.println("                     Singly Linear Linked List                 ");
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