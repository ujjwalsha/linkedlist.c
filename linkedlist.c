#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* ptr;
};

struct node* START = NULL;

struct node* createNode(){
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    return n;
}

//insertion at the ending in linked list 
void insert_end(){
    struct node* temp, *t;

    temp = createNode();
    printf("enter your number : ");
    scanf("%d", &temp->info);

    temp->ptr = NULL;
    if(START == NULL)
        START = temp;
    else{
        t = START;
        while(t->ptr != NULL)
            t = t->ptr;
        t->ptr= temp;
    }
}

//insert the node at the beginning 
void insert_begin(){
    struct node* new;
    new = createNode();
    printf("enter your number to insert at beginning ");
    scanf("%d", &new->info);
    new->ptr = START;
    START = new;
}

//insert the node at specific position 
void insert_pos(){
    struct node* temp, *x;
    int i, pos;
    temp = createNode();
    printf("enter your position to insert the node\n");
    scanf("%d", &pos);

    printf("enter the info this node : ");
    scanf("%d", &temp->info);

    temp->ptr = NULL;
    
    if(pos == 1){
        temp->ptr = START;
        START = temp;
    }
    else if(pos == 0){
        printf("position does not found : ");
    }
    else{
        for(i=1, x=START; i<pos-1; i++){
            x= x->ptr;

        }
        temp->ptr = x->ptr;
        x->ptr = temp;
    }

}

//deletion at beginning in linked list 
void delete_begin(){
  struct node* r;
  if(START == NULL)
    printf("list is empty");

  else{
    r = START;
    START = START->ptr;
    printf("deleted node is %d", r->info);
    free(r);
  }

}


//deletion at ending in linked list 
void delete_end(){
    struct node* temp, *r;
    if(START == NULL){
        printf("list is empty");
        exit(0);
    }

    else if(START->ptr == NULL){
        r = START;
        printf("deleted element is %d", r->info);
        free(r);
    }
    else{
        r = START;
        while(r->ptr != NULL){
            temp = r;
            r = r->ptr;
        }
        temp->ptr = NULL;
        printf("deleted node is %d", r->info);
        free(r);
    }
}


//delete the node at specific position 

void delete_pos(){

    int i, pos;
    struct node*temp, *r;

    if(START == NULL){
        printf("the list is empty");
        exit(0);
    }
    else{
        printf("enter your position delete a node: ");
        scanf("%d", &pos);

        if(pos == 0){
            r = START;
            START = START->ptr;
            printf("deleted node is %d", r->info);
            free(r);
        }
        else{
            r = START;
            for(i=0; i<pos; i++){
                temp = r;
                r = r->ptr;
            }
            temp->ptr = r->ptr; 
            printf("deleted node is %d", r->info);
            free(r);
        }
    }

}

//traversing in the linked list
void viewList(){
    struct node* t;
    if(START == NULL)
     printf("list is empty");
    else{
        t = START;
        while(t!=NULL){
            printf(" %d", t->info);
            t = t->ptr;
        }
    }
}

int  menu(){
    int choice;
    printf("\n 1. insert value at end:  ");
    printf("\n 2. insert the value at begin :");
    printf("\n 3. insert the value at position : ");
    printf("\n 4. delete the value at begin : ");
    printf("\n 5. delete the value at end: ");
    printf("\n 6. delete the value at pos: ");
    printf("\n 7. view the list ");
    printf("\n 8. exiting the program ");
    printf("\n enter to choice ");
    scanf("%d", &choice);

    return choice;
}

void main(){
    while(1){
        switch(menu()){
            case 1:
                insert_end();
                break;
            case 2:
                insert_begin();
                break;

            case 3:
                insert_pos();
                break;

            case 4:
                delete_begin();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                delete_pos();
                break;
            case 7:
                viewList();
                break;
            case 8:
                exit(0);
            default:
                printf("invalid choice ");
        }
    }
}
