//Turbo C
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
struct Node{
  struct Node* prev;
  int data;
  struct Node* next;  
};
void traverseList(struct Node* head)
{
    struct Node* ptr=head;
    while (ptr !=NULL)
    {
        /* code */
        printf("\nElement : %d",ptr->data);
        delay(500);

        ptr=ptr->next;
    }
    
}
void revList(struct Node* head)
{
    struct Node* ptr=head;
    struct Node* follow;
    while (ptr !=NULL)
    {
        /* code */
        follow=ptr;
        ptr=ptr->next;
    }
    //printf("\n\nElement :%d",follow->data);
    
    while (follow != NULL)
    {
        printf("\nElement : %d",follow->data);
        delay(500);
        follow=follow->prev;
    }
    
    
}
struct Node* insertAtBegin(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->prev=NULL;
    ptr->next=head;
    head->prev=ptr;
    head=ptr;
    return head;
}
struct Node* insertAtEnd(struct Node* head,int data)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr=head;
    struct Node* follow;
    temp->data=data;
    temp->next=NULL;

    while (ptr !=NULL)
    {
        /* code */
        follow=ptr;
        ptr=ptr->next;
    }
    follow->next=temp;
    temp->prev=follow;
    return head;

}
struct Node* insertAfter(struct Node* head,int after,int data)
{
   struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
   struct Node* temp=head;
   struct Node* follow1;
   ptr->data=data;
   while (temp->data != after)
   {
       /* code */
       temp=temp->next;
   }
   follow1=temp->next;
   ptr->next=temp->next;
   follow1->prev=ptr;
   temp->next=ptr;
   ptr->prev=temp;
   //printf("\nElement : %d",temp->data);

   return head;
}
struct Node* delFrmBeg(struct Node* head)
{
    struct Node* ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    return head;
}
struct Node* delFrmEnd(struct Node* head)
{
    struct Node* ptr=head;
    struct Node* follow;
    struct Node* temp;
    
    while (ptr !=NULL)
    {
        /* code */
        follow=ptr;
        ptr=ptr->next;
    }
    temp=follow->prev;
    temp->next=NULL;
    free(follow);
    
    return head;
}
struct Node* delParticular(struct Node* head,int d_data)
{
    struct Node* ptr=head;
    struct Node* temp;
    struct Node* follow1;
    while (ptr->data != d_data)
    {
        temp=ptr;
        ptr=ptr->next;
    }
   // printf("\nElement : %d ",ptr->data);

   follow1=ptr->next;
   temp->next=ptr->next;
   follow1->prev=temp;
   free(ptr);
   return head;

}

int main()
{
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;

    clrscr();

    head=(struct Node*)malloc(sizeof(struct Node));
    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    fifth=(struct Node*)malloc(sizeof(struct Node));
    
    head->prev=NULL;
    head->data=0;
    head->next=first;


    first->prev=head;
    first->data=1;
    first->next=second;

    second->prev=first;
    second->data=2;
    second->next=third;

    third->prev=second;
    third->data=3;
    third->next=fourth;

    fourth->prev=third;
    fourth->data=4;
    fourth->next=fifth;

    fifth->prev=fourth;
    fifth->data=5;
    fifth->next=NULL;

    printf("\nPrinting Doubly Lineked List");
    traverseList(head);
 
    printf("\nReversing the Doubly Lineked List (printing in rev order)");
    revList(head);

    printf("\nInserting Data at beginning of DLL");
    head=insertAtBegin(head,-1);
    traverseList(head);

    printf("\nInserting Data at end of DLL");
    head=insertAtEnd(head,6);
    traverseList(head);
    
    printf("\nInserting Data after particular node of DLL");
    head=insertAfter(head,4,99);
    traverseList(head);

    printf("\nDeleting Node from beginning of the DLL");
    head=delFrmBeg(head);
    traverseList(head);

    printf("\nDeleting node form end of DLL");
    head=delFrmEnd(head);
    head=delFrmEnd(head);
    traverseList(head);
         
    printf("\nDeleting  particular node: ");
    head=delParticular(head,2);
    traverseList(head);

    getch();
    return 0;
}