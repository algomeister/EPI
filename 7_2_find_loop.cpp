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
    int loopCheck()
        {
        node *a, *b;
        int i=0,j=0;
        a = head;
        b = head;
        while(b!=NULL || b->next!=NULL || b!=head || b->next!=head || a!=b)
            {
            a = a->next;
            b = b->next;
            if(b->next == NULL)
                break;
            else
                b = b->next;
        }
        if(b==NULL || b->next==NULL)
            return 0;
        else if(b==head || b->next==head)
            {
            curr = head;
            return -1;
        }
        else
            {
            a = a->next;
            while(a!=b)
                {
                a = a->next;
                i++;
            }
            a = head;
            b = head;
            while(i>0)
                b = b->next;
            while(a!=b)
                {
                a = a->next;
                b = b->next;
                j++;
            }
            curr = a;
            return j;
        }
    }
    
    private:
    node *head;
    node *curr;
};



int main()
    {
    LinkedList<int> L;
    L.addValue(12);
    L.addValue(10);
    L.addValue(9);
    L.addValue(7);
    L.addValue(5);
    L.addValue(2);
    
    if(L.loopCheck() == 0)
        cout << "0" << endl;
    else
        cout << L.getValue();
    return 0;
}
