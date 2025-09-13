#include "contact.h"
// Dummy contact data
static Contact dummyContacts[] = {
    {1,"John Doe", "1234567890", "john@example.com"},
    {2,"Alice Smith", "0987654321", "alice@example.com"},
    {3,"Bob Johnson", "1112223333", "bob@company.com"},
    {4,"Carol White", "4445556666", "carol@company.com"},
    {5,"David Brown", "7778889999", "david@example.com"},
    {6,"Eve Davis", "6665554444", "eve@example.com"},
    {7,"Frank Miller", "3334445555", "frank@example.com"},
    {8,"Grace Wilson", "2223334444", "grace@example.com"},
    {9,"Hannah Clark", "5556667777", "hannah@example.com"},
    {10,"Ian Lewis", "8889990000", "ian@example.com"}
};

void initialize(AddressBook *addressBook) 
{
    // assign 0 to addressBook->contactCount
   // cal size of dummyContacts (10)
   //run a loop for size of dummyContacts (10 time)
        //1. copy dummyContacts[index] to addressbook->contacts[index]
        //2. inc (addressBook->contactCount)++   

        addressBook->contactCount=0;
        int size = (sizeof(dummyContacts))/sizeof(dummyContacts[0]);

        for (int i = 0; i < size; i++)
        {
            addressBook->contacts[i]=dummyContacts[i];
            (addressBook->contactCount)++;

        }
        
        
    
}