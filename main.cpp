#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node()
    {
        this->data=NULL;
        this->next=NULL;
    }

};

class LinkedList
{
    Node* head;

public:
    LinkedList()
    {
        this->head=NULL;

    }
    bool IsEmpty()
    {
        return head==NULL;
    }

    void IsnsertMiddelAndFirst(int NewItem,int NodeOffSet)
    {
        if(NodeOffSet<1)
        {
            cout << "Invalid index. Must be >= 1." << endl;
            return;
        }
        Node* newnode=new Node();
        newnode->data=NewItem;
        if(NodeOffSet==1)
        {
            newnode->next=head;
            head=newnode;
            return;
        }

        Node* temp=head;

        while(temp!=NULL&&temp->data!=NodeOffSet-1)
        {
            temp=temp->next;

        }
        if (temp==NULL)
        {
            cout << "Index out of range." << endl;
            delete newnode;
        }
        else
        {
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }


    void InsertLast(int NewItem)
    {
        if(IsEmpty())
        {
            Node* newnode=new Node();
            newnode->data=NewItem;
            head=newnode;
            return;
        }
        Node* newnode=new Node();
        newnode->data=NewItem;
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }

    void Display()
    {
        Node* current = head;

        if (IsEmpty())
        {
            cout << "List empty" << endl;
            return;
        }

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout<<endl;
    }

    int counterLength()
    {
        int Length=0;
        Node* current = head;
        while (current != NULL)
        {
            Length++;
            current = current->next;
        }
        return Length;
    }

    //Reverse code
    void Reverse()
    {
        Node* temp=head;
        Node* temp2=head->next;
        int r;
        int stop=counterLength();

        for(int i=1; i<counterLength(); i++)//i=1
        {
            for(int j=1; j<stop; j++)//j=1
            {
                r=temp2->data;
                temp2->data=temp->data;
                temp->data=r;
                temp=temp->next;
                temp2=temp2->next;

            }
            stop--;
            temp=head;
            temp2=head->next;
        }

    }


    //Merge code
    LinkedList Merge(LinkedList &obList1,LinkedList &obList2)
    {
        LinkedList obMerge;

        Node* temp1=obList1.head;
        Node* temp2=obList2.head;
        while(temp1!=NULL)
        {
            obMerge.InsertLast(temp1->data);
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            obMerge.InsertLast(temp2->data);
            temp2=temp2->next;
        }

        return obMerge;

    }
    //Equal code
    bool Equal(LinkedList &obList1,LinkedList &obList2)
    {
        if(obList1.counterLength()!=obList2.counterLength())
        {
            return false;
        }
        Node* temp1=obList1.head;
        Node* temp2=obList2.head;
        bool h=true;
        while(temp1->next!=NULL&&temp2->next!=NULL)
        {
            if(temp1->data!=temp2->data)
            {
                h=false;
                break;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return h;
    }
    //Intersection code
    LinkedList Intersection(LinkedList &obList1,LinkedList &obList2)
    {
        LinkedList InterOb;

        Node* temp1=obList1.head;
        while(temp1!=NULL)
        {
            Node* temp2=obList2.head;
            while(temp2!=NULL)
            {
                if(temp1->data==temp2->data)
                {
                    InterOb.InsertLast(temp1->data);
                    break;
                }
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
        return InterOb;

    }

    //Difference code
    LinkedList Difference(LinkedList &obList1,LinkedList &obList2)
    {
        LinkedList defOb;

        Node* temp1=obList1.head;
        while(temp1!=NULL)
        {
            bool IsFound=true;
            Node* temp2=obList2.head;
            while(temp2!=NULL)
            {
                if(temp1->data==temp2->data)
                {
                    IsFound=false;
                    break;
                }
                temp2=temp2->next;
            }
            if(IsFound)
            {
                defOb.InsertLast(temp1->data);
            }
            temp1=temp1->next;
        }
        return defOb;
    }
    //Union code
    LinkedList Union(LinkedList &obList1,LinkedList &obList2)
    {
        LinkedList UNIob;
        UNIob=UNIob.Merge(obList1,obList2);
        Node* temp1=UNIob.head;
        while(temp1!=NULL)
        {
            Node* temp2=temp1;
            while(temp2->next!=NULL)
            {
                if(temp1->data==temp2->next->data)
                {
                    Node* duplicate=temp2->next;
                    temp2->next=temp2->next->next;
                    delete duplicate;
                }
                else
                {
                    temp2=temp2->next;
                }
            }
            temp1=temp1->next;
        }
        return UNIob;

    }


};

int main()
{
    LinkedList obList1,obList2,obList3;
    //List 1
    int n1;
    cout<<"Enter count of number List 1 : ";
    cin>>n1;
    cout<<"\nEnter the Element of LinkedList 1 : ";
    for(int i=0; i<n1; i++)
    {
        int num;
        cin>>num;
        obList1.InsertLast(num);
    }
    cout<<"\nElement of LinkedList 1 : ";
    obList1.Display();
    cout<<endl;
    //List 2
    int n2;
    cout<<"Enter count of number List 2 : ";
    cin>>n2;
    cout<<"\nEnter the Element of LinkedList 2 : ";
    for(int i=0; i<n2; i++)
    {
        int num;
        cin>>num;
        obList2.InsertLast(num);
    }
    cout<<"\nElement of LinkedList 2 : ";
    obList2.Display();
    cout<<endl;

    /*
    //First Code
    obList1.Reverse();
    cout<<"\nElement of LinkedList After Reverse : ";
    obList1.Display();
    */

    //Bouns code
    /*
    //1-merge that merges two linked lists .
    obList3=obList3.Merge(obList1, obList2);
    cout << "\nElement of LinkedList After Merge: ";
    obList3.Display();
    */

    /*
    //2-equals that returns true if the two lists consist of the same elements .
    if(obList3.Equal(obList1,obList2))
    {
        cout<<"Is Equal"<<endl;
    }
    else
    {
        cout<<"Is Not Equal"<<endl;
    }
    */

    /*
    //3-intersection that returns the intersection of two linked lists.
    obList3=obList3.Intersection(obList1, obList2);
    cout << "\nElement of LinkedList After Intersection: ";
    obList3.Display();
    */

    /*
    //4-difference that returns the difference of two linked lists.
    obList3=obList3.Difference(obList1, obList2);
    cout << "\nElement of LinkedList After difference: ";
    obList3.Display();
    */

     /*
    //5-union that returns the union of two linked lists.
    obList3=obList3.Union(obList1, obList2);
    cout << "\nElement of LinkedList After Union: ";
    obList3.Display();
    */



    return 0;
}
