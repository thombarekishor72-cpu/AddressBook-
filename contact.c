#include "contact.h"
#include<ctype.h>

void listContacts(AddressBook *addressBook) 
{
    //define
    printf("Sr.\tName\t\tPhone\t\tEmail\t\t\t\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%d\t%s\t%s\t%s\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    
}

void createContact(AddressBook *addressBook) 
{
    char name[50],phone[20],email[50];
    printf("Enter the name: ");
    scanf(" %[^\n]",name);
    validate_name(addressBook,name);
    printf("Enter the phone: ");
    scanf(" %[^\n]",phone);
    validate_phone(addressBook,phone);
    search_phone(addressBook,phone);
    printf("Enter the email: ");
    scanf(" %[^\n]",email);
    validate_email(addressBook,email);
    search_email(addressBook,email);

    addressBook->contacts[addressBook->contactCount].sr=(addressBook->contactCount)+1;
    strcpy(addressBook->contacts[addressBook->contactCount].name,name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email,email);
      (addressBook->contactCount)++;
      printf("Successfully Contact create:\n");

}

void searchContact(AddressBook *addressBook) 
{
    char name[50],phone[20],email[50];
    int opt;
    do
    {
        printf("choose option to search:\n1.Search by Name\n2.Search by Phone\n3.search by Email\n4.Exit\nEnter the option: ");
        scanf("%d",&opt);
        switch (opt)
        {

        case 1:
           int flag1=0,i=0;
            printf("Enter the name to search: ");
            scanf(" %[^\n]",name);
            validate_name(addressBook,name);

            for ( i = 0; i<addressBook->contactCount; i++)
            {
                if(strcmp(name,addressBook->contacts[i].name)==0)
                {
                    printf("%d\t\t%s\t\t%s\t\t%s\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    flag1=1;
                }
                
            }

            if(flag1==0)
            {
                printf("Not Found.\n");
            }

            break;

        case 2:
            int flag2=0,j=0;
            printf("Enter the phone number to search: ");
            scanf(" %[^\n]",phone);
            validate_name(addressBook,phone);

            for ( j = 0; j<addressBook->contactCount; j++)
            {
                if (strcmp(phone,addressBook->contacts[j].phone)==0)
                {
                    printf("%d\t\t%s\t\t%s\t\t%s\n",addressBook->contacts[j].sr,addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
                    flag2=1;
                }
                
            }

            if(flag2==0)
            {
                printf("Not Found.\n");
            }

            break;

         case 3:
            int flag3=0,k=0;
            printf("Enter the email to search: ");
            scanf(" %[^\n]",email);
            validate_name(addressBook,email);
            for ( k = 0; k<addressBook->contactCount; k++)
            {
                if (strcmp(email,addressBook->contacts[k].email)==0)
                {
                    printf("%d\t\t%s\t\t%s\t\t%s\n",addressBook->contacts[k].sr,addressBook->contacts[k].name,addressBook->contacts[k].phone,addressBook->contacts[k].email);
                    flag3=1;
                }
                
            }

            if(flag3==0)
            {
                printf("Not Found.\n");
            }

            break;

         case 4:
            printf("Exiting Search Contact. Thankyou!\n");
            break;
        
        default:
            printf("Invalid input.\n");
            break;
        }
    } while (opt!=4);
    

}

void editContact(AddressBook *addressBook) 
{
    char name[50],phone[20],email[50],name1[50],phone1[20],email1[50];
    int flag=0,sr,op;
    do
    {
        printf("Choose option to Edit: \n1. Edit Name\n2. Edit Phone\n3. Edit Email\n4. Exit\nEnter the option: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            int count1=0;
            printf("Search Name to Edit: ");
            scanf(" %[^\n]",name);
            validate_name(addressBook,name);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strcmp(name,addressBook->contacts[i].name)==0){
                    count1++;
                }
            }
            if(count1==1){
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(strcmp(name,addressBook->contacts[i].name)==0){
                        printf("Contact found.\nContact data:\n");
                        printf("%d\t%s\t\t%s\t\t%s\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        printf("Enter Name to update: ");
                        scanf(" %[^\n]",name1);
                        validate_name(addressBook,name1);
                        strcpy(addressBook->contacts[i].name,name1);
                        printf("Data updated successflly.\nUpdated data.\n");
                        printf("%d\t%s\t\t%s\t\t%s\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        break;
                    }
                }
            }
            break;
        

        case 2:
            int count2=0;
            printf("Search Phone to Edit: ");
            scanf(" %[^\n]",phone);
            validate_phone(addressBook,phone);

            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strcmp(phone,addressBook->contacts[i].phone)==0){
                    count2++;
                }
            }
            if(count2==1){
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(strcmp(phone,addressBook->contacts[i].phone)==0){
                        printf("Contact found.\nContact data:\n");
                        printf("%d\t%s\t\t%s\t\t%s\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        printf("Enter Phone to update: ");
                        scanf(" %[^\n]",phone1);
                        validate_phone(addressBook,phone1);
                        search_phone(addressBook,phone1);
                        strcpy(addressBook->contacts[i].phone,phone1);
                        printf("Data updated successflly.\nUpdated data.\n");
                        printf("%d\t%s\t\t%s\t\t%s\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        break;
                    }
                }
            }
            break;
        
        case 3:
            int count3=0;
            printf("Search Email id to Edit: ");
            scanf(" %[^\n]",email);
            validate_email(addressBook,email);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strcmp(email,addressBook->contacts[i].email)==0){
                    count3++;
                }
            }
            if(count3==1){
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(strcmp(email,addressBook->contacts[i].email)==0){
                        printf("Contact found.\nContact data:\n");
                        printf("%d\t%s\t\t%s\t\t%s\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        printf("Enter Email id to update: ");
                        scanf(" %[^\n]",email1);
                        validate_email(addressBook,email1);
                         search_email(addressBook,email1);
                        strcpy(addressBook->contacts[i].email,email1);
                        printf("Data updated successflly.\nUpdated data.\n");
                        printf("%d\t%s\t\t%s\t\t%s\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        break;
                    }
                }
            }
            break;
        

        case 4:
            printf("Exiting Edit Contact. Thankyou!\n");
            break;

        default:
            printf("Invalid input.\n");
            break;
        }

    }while(op!=4);


}

void deleteContact(AddressBook *addressBook) 
{
     char name[50],phone[20],email[50];
     int opt;

     do
    {
        printf("choose option to Delete:\n1.Delete by Name\n2.Delete by Phone\n3.Delete by Email\n4.Exit\nEnter the option: ");
        scanf("%d",&opt);

                    if(opt==1){
                     printf("Enter name to delete: ");
                     scanf(" %[^\n]",name);}
                    

                     else if(opt==2){
                      printf("Enter the phone number to delete: ");
                      scanf(" %s",phone); } 
                        

                    else if(opt==3){
                       printf("Enter the email id to delete: ");
                       scanf(" %s",email);  }
                        

                    else {
                        printf("Invalid option.Try again\n");
                        continue;
                    }
        
        
        

        int count=0;
        for(int i=0; i<addressBook->contactCount; i++)
        {
                int found=0;
                    if(opt==1 && strcmp(name,addressBook->contacts[i].name)==0)
                    {
                         found=1;
                        
                    }
                    
                    else if(opt==2 && strcmp(phone,addressBook->contacts[i].phone)==0)
                    {
                       
                          found=1; 
                    }
                    
                    else if(opt==3 && strcmp(email,addressBook->contacts[i].email)==0)
                    {
                        
                        found=1;  
                    } 

                    if(found)
                        {
                            count=1;
                            printf("Contact Found:\n");
                            printf("%d\t\t%s\t\t%s\t\t%s\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            

                            for(int j = i; j<addressBook->contactCount-1; j++)
                            {
                                addressBook->contacts[j]=addressBook->contacts[j+1];
                            }

                            addressBook->contactCount--;

                         for (int k = 0; k < addressBook->contactCount; k++)
                        {
                            addressBook->contacts[k].sr = k + 1;
                        }

                        printf("Contact Deleted Successfully.\n");
                            break;
                        }
        }

                  if(count==0)
                    {
                        printf("Contact not Found.\n");
                        break;
                    }
        
     }while(opt!=4);
}

void validate_name(AddressBook *addressBook, char name[])
{
    int flag=0;

    for(int i=0;name[i]!='\0';i++)
    {
        if(isalpha(name[i])!=0 || name[i]==' ')
        {
            continue;
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("Enter the valid Name: ");
        scanf(" %[^\n]",name);
        validate_name(addressBook, name);
    }
}

void validate_phone(AddressBook *addressBook, char phone[])
{
    int count=0,flag=0;
    for(int i=0;phone[i]!='\0';i++)
    {
        if(phone[i]>='0' && phone[i]<='9' && phone[0]!='0')
        {
            count++;
            continue;
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==1 || count!=10){
        printf("Enter the valid Contact number: ");
        scanf(" %[^\n]",phone);
        validate_phone(addressBook,phone);
    }
}

void validate_email(AddressBook *addressBook, char email[])
{
    int flag1=0,flag=0,count=0,num=0,size,count2=0;
    if((email[0]>='a' && email[0]<='z'))
    {
        flag=1;
    }
    for(int i=0;email[i]!='\0';i++)
    {
        if(email[i]=='@' && (email[i+1]>='a' && email[i+1]<='z'))
        {
            count=1;
        }
        if(email[i]=='@'){
            count2++;
        }
        if(email[i]==' '){
            flag1 = 1;
        }
    }
    size=strlen(email);
    if(email[size-1]=='m' && email[size-2]=='o' && email[size-3]=='c' && email[size-4]=='.')
    {
        num=1;     
    }
    if(flag==1 && count == 1 && num == 1 && count2==1 && flag1 == 0)
    {
        return;
    }
    else
    {
        printf("Enter valid Email id: ");
        scanf(" %[^\n]",email);
        validate_email(addressBook,email);
    }
}


void search_phone(AddressBook *addressBook, char phone[])
{
    int flag=0;

        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(phone,addressBook->contacts[i].phone)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return;
        }
        else
        {
            printf("Contact number Already exists!\nEnter another Contact number: ");
            scanf(" %[^\n]",phone);
            validate_phone(addressBook,phone);
        }
}

void search_email(AddressBook *addressBook, char email[])
{
    int flag=0;
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(email,addressBook->contacts[i].email)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return;
        }
        else
        {
            printf("Email id Already exists!\nEnter another Email id: ");
            scanf(" %[^\n]",email);
            validate_email(addressBook,email);
        }
}

    void save_file(AddressBook *addressBook)
    {
        FILE *fptr = fopen("file.csv","w");
        if(fptr==NULL){
            printf("file is not found.\n");
        }
        fprintf(fptr,"#%d\n",addressBook->contactCount);
        for (int i = 0; i <addressBook->contactCount ; i++){
            fprintf(fptr, " %d %s,%s,%s\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        fclose(fptr);
    }



    void load_file(AddressBook *addressBook)
    {
        FILE *fptr = fopen("file.csv","r");
        if(fptr==NULL){
            printf("file is not found.\n");
        }
        fscanf(fptr,"#%d\n",&addressBook->contactCount);
        for (int i = 0; i <addressBook->contactCount ; i++){
            fscanf(fptr, " %d %[^,],%[^,],%[^\n]\n",&addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        fclose(fptr);
    }





