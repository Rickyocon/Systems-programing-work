#include <stdio.h>
#include <stdlib.h>
//--------------------


//Function Protyping
//------------------------------------------------------------------------------------------------------

//A structure to create a linked list 
typedef struct node
{
    int data;
    struct node * next;
}Node; //struct node


//Function to create list 
Node * createLinkedList(int n);


//Function to display linked list
void print_list(Node * head);


//Function to delete a node at the desired position
void Delete_Node(struct node **head, int pos);


//Function to add to the end of the linked list
void Add_At_End(struct node **head, int val);


//Function to serach for a data member in a linked list
int searchNode(struct node *head,int key);


//Function to delete linked list
void delete_list(struct node** head);


//Function to get the current size of linked list(used for inserting a node in a desired position)
int getCurrSize(struct node* node);


//Function to insert a node in a desired position
int Insert_Node(struct node** head, int position, int data);

//Function to print a nodes value and position based on value given
int print_node(struct node *head,int position2);

//------------------------------------------------------------------------------------------------------



//Main
int main(int argc,char **argv) 
{
    int n = 0; //create linked list
    int pos = 0; //delete node
    int val = 0; //add at end
    int key = 0; //search node
    int data = 0; //insert node
    int position = 0; //insert node
    int position2 = 0; //print node
    Node * HEAD = NULL;  //store the items of first node

    printf("\nCreate a Linked List- How Many nodes do you want?: ");
    scanf("%d",&n);
    HEAD = createLinkedList(n);

    //Menu to preform on linked list
    int choice = 0; //to take input for user on menu
    while (1)
    {
        printf("\n----------------------------------\n");
        printf("Menu:\n");
        printf("----------------------------------\n");
        printf("1. Display Linked List \n");
        printf("2. Delete a desired node \n");
        printf("3. Add to the end of linked list \n");
        printf("4. insert a Node \n");
        printf("5. serach data for a desired Node \n");
        printf("6. Print a Node \n");
        printf("7. Delete Linked List \n");
        printf("8. Create a new linked list \n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);
        

        switch(choice)
        {
            case 1: 
                printf("\nHere is your Linked List\n");
                print_list(HEAD);
                break;
            case 2:
                Delete_Node(&HEAD,pos);
                break;
            case 3:
                Add_At_End(&HEAD,val);
                break;
            case 5:
                if(searchNode(HEAD,key) == 1)
                    printf("Search Found :)\n");
                else
                    printf("Search Not Found :(\n");
                break;
            case 7:
                delete_list(&HEAD);
                printf("The Linked list was deleted\n");
                break;
            case 8:
                printf("\nCreate a Linked List- How Many nodes do you want?:");
                scanf("%d",&n);
                HEAD = createLinkedList(n);
                break;
            case 4:
                Insert_Node(&HEAD,position,data);
                printf("Successfully inserted node! :)\n");
                break;
            case 6:
                print_node(HEAD,position2);
                break;
        }//switch Choice

    }//while loop

    return 0;
}//main


Node * createLinkedList(int n)
{
    int i = 0;
    Node * head = NULL;  //store items of first node
    Node * temp = NULL;  //Create a tempary node
    Node * current = NULL;     //to iterate linked list 

    for(i=0;i<n;i++)
    {
        //create individual node (not attached to list (isolated))
        temp = (Node*)malloc(sizeof(Node)); //allocate space for node
        printf("\nEnter data for node number %d:",i+1);
        scanf("%d",&(temp->data));
        temp->next = NULL;

        if(head == NULL) //if list is currently empty, Then make temp first node
        {
            head = temp;
        }
        else
        {
            current = head;
            while(current->next !=NULL) //to iterate list to last data member (NULL-1)
            {
                current = current->next;
            }
            current->next = temp;
        }

    }//for loop

    return head;

} //createLinkedList


void print_list(Node * head)
{
    Node * current = head;
    if(current == NULL)
    {
        printf("**The Linked list doesnt exist or was it was deleted**\n");
    }
    else
        while(current !=NULL)
        {
            printf("\t%d->",current->data);
            current = current->next;
        }
     
}//print_list


void Delete_Node(struct node **head, int pos)
{

    printf("\nType the value/data of the node that you want to delete: ");
    scanf("%d",&pos);

    //temp is used to freeing the memory
    struct node *temp;

    //key found on the head node.
    //move to head node to the next and free the head.
    if((*head)->data == pos)
    {  
        temp = *head;    //backup to free the memory
        *head = (*head)->next;
        free(temp);
    }
    else
    {
        struct node *current  = *head;
        while(current->next != NULL)
        {
            //if yes, we need to delete the current->next node
            if(current->next->data == pos)
            {
                temp = current->next;
                //node will be disconnected from the linked list.
                current->next = current->next->next;
                free(temp);
                break;
              }
              //Otherwise, move the current node and proceed
              else
                  current = current->next;
          }
      }
}//delete node



void Add_At_End(struct node **head, int val)
{
    printf("\nWhat number would you like to set this new node to?: ");
    scanf("%d",&val);

    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    //if head is NULL, it is an empty list
    if(*head == NULL)
        *head = newNode;
    //Otherwise, find the last node and add the newNode
    else
    {
        struct node *lastNode = *head;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }   
}//Add_At_End


int searchNode(struct node *head,int key)
{

    printf("\nType a data member you would like to know if its in the linked list or not: ");
    scanf("%d",&key);    
    struct node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         //key found return 1.
         if(temp->data == key)
             return 1;
         temp = temp->next;
    }
    //key not found
    return -1;
}//search node


void delete_list(struct node** head)
{
   struct node* current = *head;
   struct node* next;
 
   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }
   
   *head = NULL;
}//delete list

int getCurrSize(struct node* node)
{
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}//getCurrSize


int Insert_Node(struct node** head, int position, int data)
{

    printf("\nType the position/index of where you would like to insert: ");
    scanf("%d",&position);

    printf("\nType the value you would like to assign to this new node: ");
    scanf("%d",&data);

    int size = getCurrSize(*head);

    struct node* newNode = (struct node*) malloc(sizeof(struct node)); 
    newNode->data = data;
    newNode->next = NULL;
 
    if(position < 0 || position > size) 
        printf("Invalid position to insert\n"); 
        
    // inserting first node
    else if(position == 0){
        newNode->next = *head; 
        *head = newNode;
    }
    
    else 
    {
        // temp used to traverse the Linked List
        struct node* temp = *head; 
        
        // traverse till the nth node
        while(--position)
            temp=temp->next;
        
        newNode->next= temp->next;
        temp->next = newNode;
    }
}//insert node



int print_node(struct node *head,int position2)
{

    printf("\nType the value/data of the node you want to print: ");
    scanf("%d",&position2);

    int index;
    struct node *newnode;
    index = 0;
    newnode = head;
    while (newnode != NULL && newnode->data != position2)
    {
        index++;
        newnode = newnode->next;
    }
    if (index >= 0)
        printf("%d found at position %d\n", position2, index);
    else
        printf("not found in the list\n");

    return (newnode != NULL) ? index : -1;


}//print_node