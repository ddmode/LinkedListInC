#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 16 // max size of name and surname

typedef struct Athlete
{
    int id;
    char name[ARRAY_SIZE];
    char surName[ARRAY_SIZE];
    float height;
    float weight;
    struct Athlete *next;

} Athlete;



void menu(Athlete *);
int getOption();
Athlete *getInfo();
int getID();
void push(Athlete *, Athlete *);
void pop(Athlete *, int );
void display(Athlete *);



int main()
{

    Athlete *head = malloc(sizeof(Athlete)); // Start Node of List
    head->next = NULL;

    menu(head);



    return 0;
}

void menu(Athlete *head) // Menu
{
    int option;

    do
    {

        switch(option=getOption())
        {
        case 1:
            push(head, getInfo());
            break;
        case 2:
            pop(head, getID());
            break;
        case 3:
            display(head);
            break;
        default:
            printf("Option must be between 1 and 4 ! \n");
            break;
        }


    }
    while(option!=4);

    return;
}




int getOption() // Show options
{
    int option;

    printf("Choose an option \n");
    printf("1. Add an Athlete to the List \n ");
    printf("2. Delete an Athlete from the List \n ");
    printf("3. Display Information for all Athletes in the List \n");
    printf("4. Exit \n");
    scanf("%d",&option);

    return option;
}

Athlete *getInfo() // Get Information from user for an Athlete and returns a pointer
{
    Athlete *newAthlete = malloc(sizeof(Athlete));

    fflush(stdin);

    printf(" Enter ID : ");
    scanf("%d", &newAthlete->id);
    fflush(stdin);

    printf("\n Enter Name : ");
    gets(newAthlete->name);
    fflush(stdin);

    printf("\n Enter Surname : ");
    gets(newAthlete->surName);
    fflush(stdin);

    printf("\n Enter Height : ");
    scanf("%f", &newAthlete->height);
    fflush(stdin);

    printf("\n Enter Weight : ");
    scanf("%f", &newAthlete->weight);



    return newAthlete;

}

int getID() // Get ID from user to remove an athlete from the list
{
    int id;

    fflush(stdin);
    printf("\n Enter ID to Remove an Athlete from the List : ");
    scanf("%d",&id);

    return id;

}

void push(Athlete *head, Athlete *newAthlete) // this function add an item ( Athlete struct ) to end of the list
{
    Athlete *temp = head;

    while ( temp->next != NULL)
    {
        temp = temp->next;
    }


    temp->next = newAthlete;
    newAthlete->next = NULL;

    return;
}


void pop(Athlete *head, int popId) // remove an item ( Athlete struct ) from the list
{
    Athlete *temp = head;

    if(temp->next==NULL) // if list is empty
        printf("List is empty ! \n");

    else if (temp->next->id == popId) // if item first of the list
    {
        head = head->next->next;
        free(temp->next);
    }

    else // if item in middle or end of the list
    {
        while(temp->next->id!=popId && temp->next!=NULL)
            temp=temp->next;

        temp->next = temp->next->next;
        free(temp->next);

    }

    return;
}


void display(Athlete *head) // displays all the lists
{
    Athlete *temp = head;

    while ( temp->next != NULL)
    {
        temp = temp->next;

        printf("ID      : %d \n", temp->id);
        printf("Name    : %s \n", temp->name);
        printf("Surname : %s \n", temp->surName);
        printf("Height  : %.2f \n", temp->height);
        printf("Weight  : %.2f \n\n", temp->weight);


    }

    return;

}
