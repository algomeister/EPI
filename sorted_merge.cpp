#include <iostream>
using namespace std;

template <class T>
class LinkedList
    {
    struct node
        {
        T x;
        node *next;
    };
    public:
    node *head;
    node *curr;

    LinkedList()
        {
        head = NULL;
        curr = NULL;
    }

    void addValue(T a)
        {
        node *n = new node;
        n->x = a;
        n->next = head;
        head = n;
        if(curr == NULL)
            curr = head;
    }
    void rewind()
        {
        curr = head;
    }
    void next()
        {
        if( curr != NULL )
            curr = curr->next;
    }
    int getValue()
        {
        if( curr != NULL )
            return curr->x;
        return 0;
    }
    int hasValue()
        {
        return ( curr != NULL ? true : false );
    }
    void function(struct node* b)
        {
        sortMerge(head,b);
        rewind();
    }
    void sortMerge(struct node* a, struct node* b)
        {
        node *temp = new node;
        if(a==NULL && b!=NULL)
            a->next = b;
        else if(a!=NULL && b!=NULL)
            {
            if(a->x <= b->x)
                {
                if(a->next==NULL)
                    a->next = b;
                else
                    sortMerge(a->next,b);
            }
            else
                {
                temp->x = a->x;
                temp->next = a->next;
                a->x = b->x;
                a->next = b->next;
                sortMerge(a,temp);
            }
        }

    }
};



int main()
    {
    LinkedList<int> L, M;
    L.addValue(12);
    L.addValue(10);
    L.addValue(9);
    L.addValue(7);
    L.addValue(5);
    L.addValue(2);
    M.addValue(11);
    M.addValue(8);
    M.addValue(4);
    M.addValue(3);
    M.addValue(1);

    L.rewind();
    M.rewind();
    L.function(M.head);
    while(L.hasValue())
        {
        cout << "Value: " << L.getValue() << endl;
        L.next();
    }
    return 0;
}
