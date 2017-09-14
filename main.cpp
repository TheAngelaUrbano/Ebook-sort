/*
Program to organize an e-book collection by entering book data, organizing the data, and calculating the total and average cost of the books
Input: Book data
Output: Book data in different orders; total and average cost of books
Processing:
 Create a menu for the following functions: entering book data, printing book data, sorting by author, title, page numbers, and cost, and calculating the total and average cost of the books.
 Create a structure with properties for the books
 Create a function to enter data into structure 
 Create a function to print data
 Create a function to sort by: author, title, cost, page number
 Create a function to calculate total and average cost, return values into a structure for cost total and average
 In a do-while loop, prompt the user for a choice from the menu. Run the function.
 After the function, ask if they want to make another selection. Keep asking while the answer is yes.
 Exit program when answer is not yes.
*/


#include <iostream>
#include <string>
using namespace std;

struct EBook
{
    string title;
    string author;
    string publisher;
    int copyrightYr;
    int pageNum;
    float cost;
};

struct Cost
{
    float total;
    float ave;
};

//Function Prototypes
EBook enterValue();
Cost calcCost(EBook[],int);
int fillArray(EBook[],int);
void printProperties(EBook);
void printArray(EBook[],int);
void sortAuthor(EBook[], int);
void sortTitle (EBook[], int);
void sortCost (EBook[], int);
void sortPage (EBook[], int);
//float calcCost (EBook[], int);

int main()
{
    const int NUM_BOOKS = 50;
    EBook bookList[NUM_BOOKS]; //array of eBooks
    int arrayCount;
    int ans;
    char selection;
    
   
    do
    {
        cout << "Menu:" << endl;
        cout << "1: Fill Array" << endl;
        cout << "2: Print Array" << endl;
        cout << "3: Sort by Author (Ascending)" << endl;
        cout << "4: Sort by Title (Ascending)" << endl;
        cout << "5: Sort by Cost (Descending)" << endl;
        cout << "6: Sort by Page Number (Descending)" << endl;
        cout << "7: Calculate total and average cost" << endl;
        cout << "Enter your selection: ";
        cin >> ans;
        switch (ans)
        {
            case 1:
                arrayCount = fillArray(bookList,NUM_BOOKS);
                break;
            case 2:
                printArray(bookList,arrayCount);
                break;
            case 3:
                sortAuthor(bookList,arrayCount);
                printArray(bookList,arrayCount);
                break;
            case 4:
                sortTitle(bookList,arrayCount);
                printArray(bookList,arrayCount);
                break;
            case 5:
                sortCost(bookList,arrayCount);
                printArray(bookList,arrayCount);
                break;
            case 6:
                sortPage(bookList,arrayCount);
                printArray(bookList,arrayCount);
                break;
            case 7:
                Cost CostArray[1];
                CostArray[0] = calcCost(bookList,arrayCount);
                cout << "Cost is: " << CostArray[0].total << endl;
                cout << "Average is: " << CostArray[0].ave <<endl;
                break;
        }
        cout << "Make another selection? (Y or N): ";
        cin >> selection;
    }
    while (selection == 'y' || selection == 'Y');
    return 0;
}

//function to fill array
int fillArray (EBook bookList[], int size)
{
    char ans;
    int index = 0;
    do
    {
        cin.ignore();
        bookList[index] = enterValue();
        index++;
        if (index < size)
        {
            cout << "Add another book? (Y or N) ";
            cin >> ans;
        }
        else
        {
            cout << "You have reached the maximum number of eBooks." << endl;
        }
    }
    while (ans == 'y' || ans == 'Y');
    return index;
}

//function to enter eBook properties
EBook enterValue()
{
    EBook temp;
    cout << "Enter the book title: ";
    getline(cin,temp.title);
    cout << "Enter author's name (last name, first name): ";
    getline(cin,temp.author);
    cout << "Enter publisher's name: ";
    getline(cin,temp.publisher);
    cout << "Enter copyright year: ";
    cin >> temp.copyrightYr;
    cout << "Enter page count: ";
    cin >> temp.pageNum;
    cout << "Enter cost: ";
    cin >> temp.cost;
    return temp;
}

/*
 Function to output all elements in array
 Input: Array of structure type, number of elements in array
 Output: Print elements in array
 Processing: Iterate through all the elements the array with a for-loop, call function to print properties the array
*/
void printArray(EBook record[], int size)
{
    for (int x=0; x < size; x++)
    {
        printProperties(record[x]);
    }
}

/*
 Function to output all values in properties in a single variable of EBook data type
 Input: Array of structure type
 Output: Properties in the structure
 Processing: Print each property in the array
 */
void printProperties(EBook record)
{
    cout << record.title << endl;
    cout << record.author << endl;
    cout << record.publisher << endl;
    cout << record.copyrightYr << endl;
    cout << record.pageNum << endl;
    cout << record.cost << endl;
}

/*
Function to sort array of structure variable ascending by author - Bubble Sort
Input: Array of structure type
Output: Sort by author name
Processing: 
 Iterate through all elements in array
 Compare first character of the last name of the first element to that of the second element
 If it comes afterwards, save it to a temporary variable
 Make that element the second element
 Make the second element the temporary element
 Keep going until everything is in order
 */
 void sortAuthor (EBook record[], int size)
{
    
    EBook temp;
    
    /*do
    {
    swap = false;
        for (int x = 0; x < (size - 1); x++)
        {
            if (record[x].author[x] > record[x+1].author[x])
            {
                temp = record[x];
                record[x] = record[x+1];
                record[x+1] = temp;
                swap = true;
            }
        }
    }
    while(swap);*/
    for(int x=0; x<(size-1);x++) {
        for(int y=0; y<(size-1);y++) {
            bool swap=true;
            if(x!=y) {
                for(int z=0;z<record[x].author.size();z++) {
                    if (record[x].author[z] > record[y].author[z]&&swap)
                    {
                        temp = record[x];
                        record[x] = record[y];
                        record[y] = temp;
                        swap = false;
                    }
                }
            }
        }
    }
}

//function to sort array in ascending order by book title - Bubble Sort
void sortTitle (EBook record[], int size)
{
    bool swap;
    EBook temp;
    
    do
    {
        swap = false;
        for (int x = 0; x < (size - 1); x++)
        {
            if (record[x].title[x] > record[x+1].title[x])
            {
                temp = record[x];
                record[x] = record[x+1];
                record[x+1] = temp;
                swap = true;
            }
        }
    }
    while(swap);
}

//function to sort array in descending order by cost -  Selection Sort
void sortCost (EBook record[], int size)
{
    int x, next, first;
    EBook temp;
    
    for (x = size - 1; x > 0; x--)
    {
        first = 0;
        for (next = 1; next <= x ; next++)
        {
            if (record[next].cost < record[first].cost)
            {
                first = next;
            }
        }
        temp = record[first];
        record[first] = record[x];
        record[x] = temp;
    }
}

//function to sort array in descending order by number of pages - Insertion Sort
void sortPage (EBook record[], int size)
{
    int x,y;
    EBook temp;
    
    for (y = 1; y < size; y++) //start with 2nd element bc 1st element is already sorted
    {
        temp = record[y]; //2nd element saved in temp
        for (x = (y-1); (x >= 0) && record[x].pageNum < temp.pageNum; x--)
        {
            record[x+1] = record[x]; //save the element to the right to left
        }
        record[x+1] = temp;
    }
}

/*
 Function to calculate total and average cost
 Input: Cost from all the books in the array, number of elements in array
 Output: Total and average cost
 Processing:
 Iterate through all elements in array and add all the cost.
 Divide by array size.
 Return to main
 */
Cost calcCost (EBook record[], int size)
{
    Cost temp;
    
    for (int index = 0; index < size; index++)
    {
        temp.total += record[index].cost;
    }
    
    temp.ave = temp.total / static_cast<double>(size);
    
    return temp;
    
}