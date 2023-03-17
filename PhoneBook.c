#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

void options(void)
{
    printf("1. Create contact\n2. Delete Contact\n3. Show All Contact\n4. Search Contact\n5. Exit\n");
}

void write()
{
    char name[30];
    char number[11];

    FILE *fp = fopen("Contacts.txt", "a+");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }

    fflush(stdin);
    printf("Enter number : ");
    scanf("%s", number);

    fflush(stdin);
    printf("Enter Name: ");
    scanf("%s", name);

    if (strlen(number) == 10)
    {
        fprintf(fp, "%s %s\n", name, number);
        printf("Creating Please wait!\n");
        Sleep(2000);
        printf("Contact created succesfully\n");
    }
    else
    {
        printf("Phone number should be of 10 digits\n");
    }

    fclose(fp);
}

void display()
{
    char name[30];
    char number[11];

    FILE *fp = fopen("Contacts.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }

    printf("loading...\n\n");
    Sleep(2000);

    while (fscanf(fp, "%s %s\n", name, number) != EOF)
    {
        printf("%s\t%s\n", name, number);
    }
    fclose(fp);
    printf("\n\n");
}

void search()
{
    int choice;
    char sear_name[30];
    char sear_number[11];
    char name[30];
    char number[11];

    FILE *fp = fopen("Contacts.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }

    printf("1) Search by number\n2) Search by name\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        int flag = 0;
        printf("Enter the number: ");
        scanf("%s", sear_number);

        if (strlen(sear_number) == 10)
        {
            printf("Searching please wait!\n\n");
            Sleep(2000);

            while (!feof(fp))
            {
                fscanf(fp, "%s %s\n", name, number);

                if (strcmp(number, sear_number) == 0)
                {
                    printf("%s\t%s\n", name, number);
                    flag = 1;
                    break;
                }
            }
        }
        else
        {
            printf("Please enter valid phone number! try again\n");
            main();
        }

        if (flag == 0)
        {
            printf("Not found\n");
        }
        break;

        fclose(fp);
    }

    case 2:
    {
        int flag = 0;
        printf("Enter the name: ");
        scanf("%s", sear_name);

        printf("Searching please wait!\n\n");
        Sleep(2000);

        while (!feof(fp))
        {
            fscanf(fp, "%s %s\n", name, number);

            if (strcmp(name, sear_name) == 0)
            {
                printf("%s\t%s\n", name, number);
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            printf("Not found\n");
        }
        fclose(fp);
        break;
    }

    default:
    {
        printf("Wrong Input\n");
        fclose(fp);
        break;
    }
    }
}
void delete()
{
    char delName[30];
    char delNum[11];
    char name[30];
    char number[11];
    int flag = 0;

    FILE *fp = fopen("Contacts.txt", "r");
    FILE *fp2 = fopen("Copy.txt", "w");

    if (fp == NULL)
    {
        printf("error Opening file");
        exit(0);
    }
    if (fp2 == NULL)
    {
        printf("error Opening file");
        exit(0);
    }

    printf("Enter the Name:");
    scanf("%s", delName);

    while(fscanf(fp,"%s %s\n",name,number) != EOF){
        if(strcmp(name,delName) == 0){
            continue;
        }
        else{
            fprintf(fp2,"%s %s\n",name,number);
        }
    }
    
    fclose(fp);
    fclose(fp2);

    remove("Contacts.txt");
    rename("Copy.txt", "Contacts.txt");
    printf("Deleting please wait!\n\n");
    Sleep(1000);
    printf("Deleted Successfully!\n\n");
    
}

void main()
{
    int opt;
    char again = 'y';
    printf("\n\n\n.....Welcome....\n\n");
    while (again == 'y')
    {
        options();

        printf("\nEnter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
        {
            write();
            break;
        }
        case 2:
        {
            delete ();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            search();
            break;
        }
        case 5:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("Wrong choice!Try again\n");
        }
        }

        fflush(stdin);

        printf("Want to run again y/n: ");
        scanf("%c", &again);
    }
}