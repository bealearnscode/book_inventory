// Beatrix House
// CPSC 230 - 10 AM
// evanputten@live.esu.edu
// April 2, 2019

// The following program manages book inventory.
// It completes the following 

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAXIMUM = 1;

typedef string BookTitle[MAXIMUM];
typedef string ISBN_Number[MAXIMUM];
typedef string Author[MAXIMUM];
typedef string Publisher[MAXIMUM];
typedef string InventoryAddDate[MAXIMUM];
typedef string BookQuantity[MAXIMUM];
typedef string WholesaleCost[MAXIMUM];
typedef string RetailCost[MAXIMUM];

//Function Prototypes
void addBook(BookTitle, ISBN_Number, Author, Publisher, InventoryAddDate, BookQuantity, WholesaleCost, RetailCost, int);
void lookUpBook(BookTitle, ISBN_Number, Author, Publisher, InventoryAddDate, BookQuantity, WholesaleCost, RetailCost, int);
void editBook(BookTitle, ISBN_Number, Author, Publisher, InventoryAddDate, BookQuantity, WholesaleCost, RetailCost, int);
void deleteBook(BookTitle, ISBN_Number, Author, Publisher, InventoryAddDate, BookQuantity, WholesaleCost, RetailCost, int);
int bookSearch(BookTitle, ISBN_Number, Author, Publisher, InventoryAddDate, BookQuantity, WholesaleCost, RetailCost, int, string);

int main()
{
    // Initialize the arrays
    BookTitle bookTitle;
    ISBN_Number isbn;
    Author author;
    Publisher publisher;
    InventoryAddDate inventoryDate;
    BookQuantity bookQuantity;
    WholesaleCost wholesale;
    RetailCost retail;
    
    // amount of items in array
    int items = 0;
    
    // Main Menu
    int menu = -1;
    
    do
    {
        // reset menu to prevent infinite loop
        menu = -1;
        
        while (menu < 1 || menu > 2)
        {
            cout << "Serendipity Booksellers" << endl;
            cout << "\t Main Menu\n" << endl;
            
            cout << "1. Inventory Database Module" << endl;
            cout << "2. Exit" << endl;
            
            cout << "Enter your choice: ";
            cin >> menu;
            
            cout << "You selected item: " << menu << endl;
            cout << endl;
            
            if (menu != 1 && menu != 2)
            {
                cout << "Please enter a 1 to select a book funtion or a 2 to exit." << endl;
            }
        }
        
        if (menu == 2)
        {
            break;
        }
    
    
        // Inventory Menu
        
        // create variable to call appropriate book function
        int choice;
        
        do
        {
            cout << "Serendipity Booksellers" << endl;
            cout << "\t Inventory Database" << endl;
            cout << "1. Look Up a Book" << endl;
            cout << "2. Add a Book" << endl;
            cout << "3. Edit a Book's Record" << endl;
            cout << "4. Delete a Book" << endl;
            cout << "5. Return to the Main Menu\n" << endl;
            
            cout << "Enter Your Choice: ";
            cin >> choice;
            
            cout << "You selected item: " << choice << endl;
            
            switch (choice)
            {
                case 1: lookUpBook(bookTitle, isbn, author, publisher, inventoryDate, bookQuantity, wholesale, retail, items);
                    break;
                case 2: addBook(bookTitle, isbn, author, publisher, inventoryDate, bookQuantity, wholesale, retail, items);
                    items++;
                    break;
                case 3: editBook(bookTitle, isbn, author, publisher, inventoryDate, bookQuantity, wholesale, retail, items);
                    break;
                case 4: deleteBook(bookTitle, isbn, author, publisher, inventoryDate, bookQuantity, wholesale, retail, items);
                    items--;
                    break;
                case 5: break;
                default: cout << "Please enter a number between 1 and 5.";
                    break;
            }
            
        } while (choice != 5);
            
        cout << endl << endl;
        
    } while (menu == 1);
    
    return 0;
}


/*****  ADD BOOK FUNCTION *****/
void addBook(BookTitle bookTitle, ISBN_Number isbn, Author author, Publisher publisher, InventoryAddDate inventoryDate,
        BookQuantity bookQuantity, WholesaleCost wholesale, RetailCost retail, int i) 
{

    if (i == MAXIMUM)
    {
        cout << "No more books may be added to the inventory.\n" << endl;
    } 
    else
    {
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, bookTitle[i]);
        
        cout << "Enter ISBN(#-###-#####-#): ";
        getline(cin, isbn[i]);
        
        cout << "Enter Author: ";
        getline(cin, author[i]);
        
        cout << "Enter Publisher: ";
        getline(cin, publisher[i]);
        
        cout << "Enter Date Added to Inventory(MM/DD/YYYY): ";
        getline(cin, inventoryDate[i]);
        
        cout << "Enter Quantity Being Added: ";
        getline(cin, bookQuantity[i]);
        
        cout << "Enter Wholesale Cost: ";
        getline(cin, wholesale[i]);
        
        cout << "Enter Retail Price: ";
        getline(cin, retail[i]);

        cout << "\n Record was successfully entered.\n" << endl;
    }
}



/*****  LOOKUP BOOK FUNCTION *****/
void lookUpBook(BookTitle bookTitle, ISBN_Number isbn, Author author, Publisher publisher, InventoryAddDate inventoryDate,
        BookQuantity bookQuantity, WholesaleCost wholesale, RetailCost retail, int i)
{

    string lookUp = "";
    
    cout << "Enter the title of the book to search for: ";
    
    cin.ignore();
    
    getline(cin,lookUp);

    /// Search for title index
    int titleIndex = bookSearch(bookTitle, isbn, author, publisher, inventoryDate, bookQuantity, wholesale, retail, i, lookUp);

    cout << endl;
}



/*****  EDIT BOOK FUNCTION *****/
void editBook(BookTitle bookTitle, ISBN_Number isbn, Author author, Publisher publisher, InventoryAddDate inventoryDate,
        BookQuantity bookQuantity, WholesaleCost wholesale, RetailCost retail, int i)
{

    string lookUp = "";
    
    cout << "Enter the title of the book to edit: ";
    
    cin.ignore();
    
    getline(cin,lookUp);

    /// Search for title index
    int titleIndex = bookSearch(bookTitle, isbn, author, publisher, inventoryDate, bookQuantity, wholesale, retail, i, lookUp);

    if (titleIndex >= 0) 
    {
        
        // Menu option selector
        int editMenu = 0;
        do
        {
            editMenu = 0;

            cout << "\n\nYou may edit any of the following fields:" << endl;
            cout << "1. ISBN" << endl;
            cout << "2. Title" << endl;
            cout << "3. Author's Name" << endl;
            cout << "4. Publisher's Name" << endl;
            cout << "5. Date Book was Added to Inventory" << endl;
            cout << "6. Quantity On Hand" << endl;
            cout << "7. WholeSale" << endl;
            cout << "8. Retail" << endl;
            cout << "9. Exit \n" << endl;

            cout << "Enter Your Choice: ";
            cin >> editMenu;
            
            cout << "You Selected Item: " << editMenu << endl;


            string newTitle = "";
            
            cin.ignore();
            
            switch(editMenu) 
            {
                case 1:
                    cout << "Current ISBN:\t" << isbn[titleIndex] << endl;
                    cout << "Enter New ISBN:\t";
                    getline(cin, newTitle);
                    isbn[titleIndex] = newTitle;
                        break;
                case 2:
                    cout << "Current Title:\t" << bookTitle[titleIndex]  << endl;
                    cout << "Enter New Title:\t";
                    getline(cin, newTitle);
                    bookTitle[titleIndex] = newTitle;
                        break;
                case 3:
                    cout << "Current Author:\t" << author[titleIndex] << endl;
                    cout << "Enter New Author:\t";
                    getline(cin, newTitle);
                    author[titleIndex] = newTitle;
                        break;
                case 4:
                    cout << "Current Publisher:\t" << publisher[titleIndex]  << endl;
                    cout << "Enter New Publisher:\t";
                    getline(cin, newTitle);
                    publisher[titleIndex] = newTitle;
                        break;
                case 5:
                    cout << "Current Date Added:\t" << inventoryDate[titleIndex]  << endl;
                    cout << "Enter New Date Added:\t";
                    getline(cin, newTitle);
                    inventoryDate[titleIndex] = newTitle;
                        break;
                case 6:
                    cout << "Current Quantity:\t" << bookQuantity[titleIndex]  << endl;
                    cout << "Enter New Quantity:\t";
                    getline(cin, newTitle);
                    bookQuantity[titleIndex] = newTitle;
                        break;
                case 7:
                    cout << "Current WholeSale Price:\t" << wholesale[titleIndex]  << endl;
                    cout << "Enter New WholeSale Price:\t";
                    getline(cin, newTitle);
                    wholesale[titleIndex] = newTitle;
                        break;
                case 8:
                    cout << "Current Retail Price:\t" << retail[titleIndex]  << endl;
                    cout << "Enter New Retail Price:\t";
                    getline(cin, newTitle);
                    retail[titleIndex] = newTitle;
                        break;
                case 9:
                        break;
                default:
                    cout << "\tPlease Enter a Number Between 1 and 9\n";
                    break;
            }
        } while (editMenu != 9);
    }

    cout << endl;
}

/*****  DELETE BOOK FUNCTION *****/
void deleteBook(BookTitle bookTitle, ISBN_Number isbn, Author author, Publisher publisher, InventoryAddDate inventoryDate,
        BookQuantity bookQuantity, WholesaleCost wholesale, RetailCost retail, int i)
{

    string lookUp = "";
    
    cout << "Enter the title of the book to delete: ";
    
    cin.ignore();
    
    getline(cin,lookUp);

    
    int titleIndex = bookSearch(bookTitle, isbn, author, publisher, inventoryDate, bookQuantity, wholesale, retail, i, lookUp);

    if (titleIndex >= 0) 
    {
        string confirm = "";
        do 
        {
            cout << "Are you sure you want to delete this book? (Y/N): ";
            cin >> confirm;

            if (confirm != "Y" && confirm != "y" && confirm != "N" && confirm != "n") 
            {
                cout << "\tPlease enter a \'Y\' for yes, or \'N\' for no." << endl;
            }
        } while (confirm != "Y" && confirm != "y" && confirm != "N" && confirm != "n");
        
        if (confirm == "Y" && confirm == "y") {
            for (int index = titleIndex; index < i - 1; index++) {
                bookTitle[index] = bookTitle[index + 1];
                isbn[index] = isbn[index + 1];
                author[index] = author[index + 1];
                publisher[index] = publisher[index + 1];
                inventoryDate[index] = inventoryDate[index + 1];
                bookQuantity[index] = bookQuantity[index + 1];
                wholesale[index] = wholesale[index + 1];
                retail[index] = retail[index + 1];
            }

            cout << "The book has been deleted." << endl;
        }
    }
    cout << endl;
}



/*****  BOOKSEARCH BOOK FUNCTION *****/
int bookSearch(BookTitle bookTitle, ISBN_Number isbn, Author author, Publisher publisher, InventoryAddDate inventoryDate,
        BookQuantity bookQuantity, WholesaleCost wholesale, RetailCost retail, int i, string lookUp) {

    int titleIndex = -1;
    
    for (int index = 0; index < i; index++)
    {
        if (lookUp == bookTitle[index])
        {
            titleIndex = index;
            break;
        }
    }
    
    if (titleIndex == -1)
    { 
        cout << "The book you searched for is not in the inventory." << endl;
        
    }
    else
    {
        cout << "\t\tSerpendipity Booksellers" << endl;
        cout << "\t\tBook Information" << endl;
        cout << "ISBN: " << isbn[titleIndex] << endl;
        cout << "Title: " << bookTitle[titleIndex] << endl;
        cout << "Author: " << author[titleIndex] << endl;
        cout << "Publisher: " << publisher[titleIndex] << endl;
        cout << "Date Added: " << inventoryDate[titleIndex] << endl;
        cout << "Quantity: " << bookQuantity[titleIndex] << endl;
        cout << "Wholesale Cost: " << wholesale[titleIndex] << endl;
        cout << "Retail Price: " << retail[titleIndex] << endl;
    }

    return titleIndex;
}

