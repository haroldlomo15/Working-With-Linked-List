#include <cstdlib>
#include <iostream>
using namespace std;

class List{
    
private:
    
    struct node {
        string data;
        node* next;
    };
    
    typedef struct node* nodePtr;
    nodePtr head;
    nodePtr curr;
    nodePtr temp;
    
public: //This is where the functions go
    
    List(); //constructor
    void ListAppend(string addData);  //adds data(appends)
    void ListRemove(string delData); //removes data
    void printData();
    
};

List::List() {  //defining the constructor. For defining the private data.
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void List::ListAppend(string addData){  //List Append function
    nodePtr n = new node;
    n->next = NULL;
    n->data = addData;
    
    if(head != NULL){
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = n;
    }
    else{
        head = n;
    }
}

void List::ListRemove(string delData) { //List remove function
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    while (curr != NULL && curr->data != delData) {
        temp = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << delData << " was not in the list\n";
        delete delPtr;
    }
    else {
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        if(delPtr == head) {
            head = head->next;
            temp = NULL;
        }
        delete delPtr;
        cout << "The value " << delData << " was deleted\n";
    }
}

void List::printData(){ //print function
    curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main () {
    
    List ListObject;
    string nameOfList, item, itemRemove;
    char userResponse, remove;
    
    cout << "Enter name of List: " ;
    cin >> nameOfList;
    cout << endl;
    
    do {
        cout << "Enter Item: ";
        cin >> item;
        ListObject.ListAppend(item);
        cout << endl;
        cout << "Are You Done? Y or N: ";
        cin >> userResponse;
        cout << endl;
    } while (userResponse == 'N');
    cout << "Wanna Remove An item?: ";
    cin >> remove;
    if (remove == 'Y')
    {
    
        do {
            cout << "What item do you want to remove?" << endl;
            cin >> itemRemove;
            ListObject.ListRemove(itemRemove);
            cout << endl;
            cout << "Wanna remove an item? " << endl;
            cin >> remove;
        
    }  while (remove == 'Y');
    }
    cout << "******Prints out******\n\nMy grocery list is:\n" << endl;
    ListObject.printData();
    cout << endl;
    
    return 0;
}


