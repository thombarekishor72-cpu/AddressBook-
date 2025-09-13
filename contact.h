#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>
#include<ctype.h>

typedef struct {
    int sr;
    char name[50];
    char phone[20];
    char email[50];
} Contact;


typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void validate_name(AddressBook *addressBook, char []);
void validate_phone(AddressBook *addressBook, char []);
void validate_email(AddressBook *addressBook, char []);
void search_phone(AddressBook *addressBook, char []);
void search_email(AddressBook *addressBook, char []);
void save_file(AddressBook *addresBook);
void load_file(AddressBook *addresBook);



#endif
