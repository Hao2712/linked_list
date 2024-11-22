#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}node;


node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}


int empty(node* array)
{
    if(array == NULL)
      return 1;
   return 0;
}


int size(node* array)
{
    int i = 0;

     while (array->next != NULL)
    {
        array = array->next;
        i++;
    }

    return i+1;
}


void insert(node** array, int value, int pos)
{
    node* temp, * p;
    temp = createNode(value);
    int i = 0;

    

    p = *array;
    while (p->next != NULL && pos != i+1)
    {
        p = p->next;
        i++;
    }

    if(pos == 0)
    {
      printf("Error: Use font function\n");
    }
    else if (pos != i)
    {
        printf("Error: Can't insert new node, use back function\n");
    }

    temp->next = p->next;
    p->next = temp;
}


void node_delete(node** array, int pos)
{
    node* temp, * p;
    int i = 0;
    p = *array;

    while (p->next != NULL && pos != i+1)
    {
        p = p->next;
        i++;
    }

    if(pos == 0)
    {
      printf("Error: Use pop_font function\n");
    }
    else if (pos != i)
    {
        printf("Error: Can't delete node, use pop_back function\n");
    }
    if(pos != 0)
    { 
        temp = p->next;
        p->next = p->next->next;
        temp->next = NULL;
        free(temp);
    }
}


void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node
                              // temp = 0xa1

    
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}


void push_font(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node

    if(*array == NULL)
    {
         *array = temp;
    }
    else
    {
         temp->next = *array;
         *array = temp; // gan gia tri node moi vao list
    }
}


void pop_back(node** array)
{
    node* p, * temp;
    p = *array;
    int i = 0;  

    while (p->next->next != NULL)     // tim node cuoi cung cua list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);

}


void pop_font(node** array)
{
    node* temp, * p;
    temp = *array;
    p = temp->next;

    free(temp);
    *array = p;
}


int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}


int font(node* array)
{
    int value = array->value;
    return value;
}


int back(node* array)
{
   while(array->next != NULL)
   {
         array = array->next;
   }

   int value = array->value;
   return value;
}


int main()
{
    node* arr = NULL;
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);
    node_delete(&arr, 0);

    printf("Value test: %d\n", get(arr, 0));
    printf("Value test: %d\n", get(arr, 1));
    printf("Value test: %d\n", get(arr, 4));
    printf("Value first: %d\n", font(arr));
    printf("Value last: %d\n", back(arr));
    printf("Size of list: %d\n", size(arr));
    if (empty(arr))
        printf("List is NULL\n");
    else
        printf("List is unNULL\n");
    

	return 0;
}
