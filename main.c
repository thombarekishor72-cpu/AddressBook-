#include "contact.h"

int main()
{
    AddressBook addressbook;
    load_file(&addressbook);
    // initialize(&addressbook);
    int option;

    do
    {
        
        printf("Addressbook Menu :\n1.for Listcontact\n2.for Createcontact\n3.for Searchcontact\n4.for Editcontact\n5.for Deletecontact\n6.Exit\n");
        printf("Enter the option: ");
        scanf(" %d",&option);

        switch (option)
        {
        case 1:
            listContacts(&addressbook);
            break;
        case 2:
            createContact(&addressbook);
            break;
        case 3:
            searchContact(&addressbook);
            break;
        case 4:
            editContact(&addressbook);
            break;
        case 5:
            deleteContact(&addressbook);   
            break;
        case 6:
            save_file(&addressbook);
            break;
        case 7:
            printf("Exiting the Addressbook..Thankyou!\n");
            break;     

        default:
            printf("Enter the Valid option\n");
            break;
        }
    } while (option!=6);

    return 0;
    

}
