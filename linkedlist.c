#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL;

// for creating linked list
void create(int a[], int n)
{
    int i;
    struct node *t, *last;
    first = new node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// for creating linked list for second
void create2(int a[], int n)
{
    int i;
    struct node *t, *last;
    second = new node;
    second->data = a[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// for creating linked list for third
void create3(int a[], int n)
{
    int i;
    struct node *t, *last;
    third = new node;
    third->data = a[0];
    third->next = NULL;
    last = third;

    for (i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// for displaying linked list using iterative method
void display(struct node *p)
{
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->next;
    }
}

// for displaying linked list using recursive method
void rdisplay(struct node *p)
{
    if (p != NULL)
    {

        rdisplay(p->next);
        printf("%d ", p->data);
    }
}

// for counting no. element using iterative method
int count(struct node *p)
{
    int c = 0;
    while (p != 0)
    {
        c++;
        p = p->next;
    }
    return c;
}

// for counting no. element using recursive method
int rcount(struct node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
    {
        return 1 + count(p->next);
    }
}

// for adding all element using iterative method
int add(struct node *p)
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

// for adding all element using recursive method
int radd(struct node *p)
{
    if (p == 0)
    {
        return (0);
    }
    else
    {
        return add(p->next) + p->data;
    }
}

// for finding maximum in list using iterative method
int max(struct node *p)
{
    int m = -32768;
    while (p)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

// for finding maximum in list using recursive method
int rmax(struct node *p)
{
    int x = 0;

    if (p == 0)
    {
        return INT32_MIN;
    }

    else
    {
        x = max(p->next);
        if (x > p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}

// for finding minimum in list using iterative method
int min(struct node *p)
{
    int m = 32768;
    while (p)
    {
        if (p->data < m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

// for finding minimum in list using recursive method
int rmin(struct node *p)
{
    int x = 0;

    if (p == 0)
    {
        return INT32_MAX;
    }

    else
    {
        x = max(p->next);
        if (x < p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}

// searching in linked list using linear search(binary search is not suitable)
struct node *search(struct node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return (p);
        }
        p = p->next;
    }
    return NULL;
}

// searching in linked list using linear search with recursive method (binary search is not suitable)
struct node *rsearch(struct node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    else if (key == p->data)
    {
        return p;
    }
    else
    {
        return search(p->next, key);
    }
}

// searching in linked list using linear search by head method (binary search is not suitable)
struct node *search2(struct node *p, int key)
{
    node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
}

// inserting new node
/*
inserting before first node
inserting after given position
*/
struct node *insert(struct node *p, int pos, int integer)
{
    struct node *t;
    if (pos < 0 || pos > count(p))
        return NULL;
    t = new struct node;
    t->data = integer;

    if (pos == 0)
    {

        t->next = first;
        first = t;
    }
    else
    {

        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            struct node *t = new node;
            t->data = integer;
            t->next = p->next;
            p->next = t;
        }
    }
}

struct node *insertlast(int integer)
{
    struct node *t = new node;
    t->data = integer;
    t->next = NULL;
    struct node *last = new node;

    if (first == NULL)
    {
        first = last = t;
    }
}

// insert element in sorted manner
void sortedinsert(struct node *p, int integer)
{
    struct node *t, *q = NULL;
    t = new struct node;
    t->data = integer;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < integer)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// deleting first node
int Delete(struct node *p, int pos)
{

    struct node *q = NULL;
    int x = -1, i;

    if (pos < 1 || pos > count(p))
    {
        return -1;
    }
    if (pos == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

// given linked list is sorted or not
int sorted(struct node *p)
{
    int x = -32768;

    while (p != NULL)
    {
        if (p->data < x)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

void removeduplicate(struct node *p)
{
    struct node *q = p->next;

    while (q != nullptr)
    {

        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

// reversing element in linked list
void reverse1(struct node *p)
{
    int *a, i = 0;
    struct node *q;
    a = new int[count(p)];
    q = p;
    while (q != NULL)
    {
        a[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = a[i];
        q = q->next;
        i--;
    }
}

// reversing linked list using sliding pointer
void reverse2(struct node *p)
{
    struct node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// reversing linked list using recursion
void reverse3(struct node *q, struct node *p)
{
    if (p)
    {
        reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

// concatenating // joining two linked list

void concatenating(struct node *p, struct node *q)
{
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q = NULL;
}

// MERGING TWO SORTED LINKED LIST
void merge(struct node *p, struct node *q)
{
    struct node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

// function for wheather linked list is loop or not
int isloop(struct node *p)
{
    struct node *r, *q;
    r = q = p;
    do
    {
        r = r->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;

    } while (r && q && r != q);
    if (r == q)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*
for finding middle term of the linked list

1. by finding length of linked list and then devide by 2 and if it is odd in length then we with 2 and take its integer value +1
2. by moving q odes by two nodes and p by one node
{
p = q= first;
while(q){
q = q->next;
if(q) q= q->next;
if(q) p = p->next;
}

cout<<p->data;
}
*/

int middleterm(struct node *p){
    struct node *q;
    p= q =first;
    while(q){
        q= q->next;
        if(q) q=q->next;
        if(q) p = p->next;
    }
    return p->data;
}

int main()
{
   

    return 0;
}
