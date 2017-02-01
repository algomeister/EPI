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
    void addNode(struct node* b)
        {
        b->next = head;
        head = b;
        if(curr == NULL)
            curr = head;
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
    int forkCheck(struct node* b)
        {
        node *h1, *h2;
        int len1=1,len2=1;
        h1 = head;
        h2 = b;
        rewind();
        while(h1->next)
            {
            len1++;
            h1 = h1->next;
        }
        while(h2->next)
            {
            len2++;
            h2 = h2->next;
        }
        if(h1==h2)
            {
            if(len1 <= len2)
                {
                while(len2-len1)
                    {
                    b = b->next;
                    len2--;
                }
                while(curr!=b)
                    {
                    next();
                    b = b->next;
                }
            }
            else
                {
                while(len1-len2)
                    {
                    next();
                    len1--;
                }
                while(curr!=b)
                    {
                    next();
                    b = b->next;
                }
            }
            return 1;
        }
        else
            return 0;
    }
};



int main()
    {
    LinkedList<int> L, M;
    L.addValue(12);
    L.addValue(10);
    L.addValue(9);
    M.addValue(8);
    L.addNode(M.head);
    L.addValue(7);
    L.addValue(5);
    L.addValue(2);
    M.addValue(6);
    M.addValue(5);
    M.addValue(3);
    M.addValue(1);

    if(L.forkCheck(M.head))
        cout << L.getValue() << endl;
    else
        cout << "0" << endl;
    return 0;
}
