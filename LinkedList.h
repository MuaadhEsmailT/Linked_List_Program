#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include <iostream>
using namespace std;
template <class T>
struct node {

    string Student_Name;
    string Matric_Number;
    int Year;
    double CGPA;
    node* next;// to point the next node
};
template <class T>
class LinkedList
{
public:
    void insert_end(string STU_NAME, string Matric_Numbers, int YEAR, double CGPA1);
    void insert_after(string STU_NAME, string Matric_num, int YEAR, double CGPA1);
    void unorder();
    void order();
    void display();
    void deletnode(string value1);
    void delete_beg();
    void delet_end();
    void search_MA(string x);
    void search_CGPA(double CGPA);
    void search_Year(int Year);
    LinkedList() {}
    ~LinkedList() {}

private:
    node<T>* head = NULL;

};


template<class T>
void LinkedList<T>::insert_end(string STU_NAME, string Matric_Numbers, int YEAR, double CGPA1)
{
    node<T>* new_node, * last;
    new_node = new node<T>;
    new_node->Student_Name = STU_NAME;
    new_node->Matric_Number = Matric_Numbers;
    new_node->Year = YEAR;
    new_node->CGPA = CGPA1;

    if (head == NULL) {
        head = new_node;
        new_node->next = NULL;
    }
    else
    {
        last = head;

        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = NULL;
    }
}


template<class T>
void LinkedList<T>::insert_after(string STU_NAME, string Matric_num, int YEAR, double CGPA1)
{
    node<T>* new_node, * last;

    new_node = new node<T>;
    new_node->Student_Name = STU_NAME;
    new_node->Matric_Number = Matric_num;
    new_node->Year = YEAR;
    new_node->CGPA = CGPA1;
    if (head == NULL) {
        head = new_node;
        new_node->next = NULL;
    }
    else
    {
        last = head;
       
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = NULL;
    }

  
    
    /*
    else if (new_node->CGPA >= before->CGPA) {
        before->next= new_node;
        new_node->next = NULL;
        before = new_node;
    }
    else if (new_node->CGPA <= before->CGPA) {
        new_node->next = before;
        before->next = NULL;
        before = new_node;

    }
    */
}


template <class T>
void LinkedList<T>::unorder()
{
    int OR_UNORDER = 0;
    string STU_NAME;
    string Matric_num;
    double CGPA = 0;
    int YEAR = 0;
    int select = 0;
    int delete_type = 0;
    string delete_mat;
    string search_M;
    int search_type = 0;
    int search_year = 0;
    double searchCGPA = 0;

    cout << "[1]ADD new student data" << endl;
    cout << "[2]Delete student data " << endl;
    cout << "[3]DISPLAY all information data" << endl;
    cout << "[4]Search for student by Matric Number" << endl;
   
    cout << "select what you want to do:" << endl;
    cin >> select;
 

        switch (select) {

        case 1:
            cout << "Enter student information as following" << endl;
            cout << "student Name:";
            cin >> STU_NAME;
            cout << endl;
            cout << "Matric Number:";
            cin >> Matric_num;
            cout << endl;
            cout << "student year:";
            cin >> YEAR;
            cout << endl;
            cout << "CGPA:";
            cin >> CGPA;
            insert_end(STU_NAME, Matric_num, YEAR, CGPA);

            break;

        case 2:

            cout << "[1]Delete first student data" << endl;
            cout << "[2]Delete last student data" << endl;
            cout << "[3]Delete by Matric number " << endl;
            cin >> delete_type;
            if (delete_type == 1) {
                delete_beg();
            }
            else if (delete_type == 2) {
                delet_end();
            }
            else if (delete_type == 3) {
                cout << "enter student Matric number:" << endl;
                cin >> delete_mat;
                deletnode(delete_mat);
            }
            else {

                cout << "wrong" << endl;
            }

            break;
        case 3:

            display();


            break;
        case 4:

            cout << "[1]Search for Specific student by MAtric Number" << endl;
            cout << "[2]list of student in year" << endl;
            cout << "[3]list of student with CGPA" << endl;
            cin >> search_type;
            if (search_type == 1) {
                cout << "Enter student Matric number " << endl;
                cin >> search_M;
                search_MA(search_M);
            }
            else if (search_type == 2) {
                cout << "Enter the year: " << endl;
                cin >> search_year;
                search_Year(search_year);

            }
            else if (search_type == 3) {
                cout << "Enter the CGPA: " << endl;
                cin >> searchCGPA;
                search_CGPA(searchCGPA);
            }

            break;
        default:
            return unorder();
            break;
        }
    
}


template<class T>
void LinkedList<T>::order()
{
    int OR_UNORDER = 0;
    string STU_NAME;
    string Matric_num;
    double CGPA = 0;
    int YEAR = 0;
    int select = 0;
    int delete_type = 0;
    string delete_mat;
    string search_M;
    int search_type = 0;
    int search_year = 0;
    double searchCGPA = 0;
    cout << "[1]ADD new student data" << endl;
    cout << "[2]Delete student data " << endl;
    cout << "[3]DISPLAY all information data" << endl;
    cout << "[4]Search for student by Matric Number" << endl;
   
    cout << "select what you want to do:" << endl;
    cin >> select;

    switch (select)
    {
    case 1:
        cout << "Enter student information as following" << endl;
        cout << "student Name:";
        cin >> STU_NAME;
        cout << endl;
        cout << "Matric Number:";
        cin >> Matric_num;
        cout << endl;
        cout << "student year:";
        cin >> YEAR;
        cout << endl;
        cout << "CGPA:";
        cin >> CGPA;
        insert_after(STU_NAME, Matric_num, YEAR, CGPA);

        break;
    case 2:

        cout << "[1]Delete first student data" << endl;
        cout << "[2]Delete last student data" << endl;
        cout << "[3]Delete by Matric number " << endl;
        cin >> delete_type;
        if (delete_type == 1) {
            delete_beg();
        }
        else if (delete_type == 2) {
            delet_end();
        }
        else if (delete_type == 3) {
            cout << "enter student Matric number:" << endl;
            cin >> delete_mat;
            deletnode(delete_mat);
        }
        else {

            cout << "wrong" << endl;
        }

        break;
    case 3:
        display();

        break;
    case 4:
        cout << "[1]Search for Specific student by MAtric Number" << endl;
        cout << "[2]list of student in year" << endl;
        cout << "[3]list of student with CGPA" << endl;
        cin >> search_type;
        if (search_type == 1) {
            cout << "Enter student Matric number " << endl;
            cin >> search_M;
            search_MA(search_M);
        }
        else if (search_type == 2) {
            cout << "Enter the year: " << endl;
            cin >> search_year;
            search_Year(search_year);

        }
        else if (search_type == 3) {
            cout << "Enter the CGPA: " << endl;
            cin >> searchCGPA;
            search_CGPA(searchCGPA);
        }
        break;
    default:
        return order();
        break;
    }
}

template<class T>
void LinkedList<T>::display()
{
    node<T>* current_node;
    if (head == NULL) {

        cout << "linked list is empty" << endl;
    }
    else {
        current_node = head;
        while (current_node != NULL)
        {

            cout << "student Name" << "     " << "Matric number" << "     " << "Year" << "   " << "CGPA" << endl;
            cout << current_node->Student_Name << "                 " << current_node->Matric_Number << "              " << current_node->Year << "      " << current_node->CGPA << endl;

            current_node = current_node->next;
        }
    }
    cout << endl;
}

template<class T>
void LinkedList<T>::deletnode(string value1)
{
    node<T>* current, * previous;
    current = head;
    previous = head;
    if (current->Matric_Number == value1) {
        head = current->next;
        free(current);
        return;
    }
    while (current->Matric_Number != value1)
    {
        previous = current;
        current = current->next;

    }
    previous->next = current->next;
    free(current);
    cout << "*****student has been deleted*****" << endl;
}

template<class T>
void LinkedList<T>::delete_beg()
{
    if (head == NULL) {
        cout << "linked list is empty" << endl;

    }
    else
    {
        node<T>* first_node = head;
        head = first_node->next;
        delete(first_node);
        cout << "***First node has been deleted***" << endl;
    }
}

template<class T>
void LinkedList<T>::delet_end()
{
    if (head == NULL) {
        cout << "linked list is empty" << endl;

    }
    else if (head->next == NULL) {
        delete(head);
        head = NULL;
    }
    else {
        node<T>* ptr = head;
        while (ptr->next->next != NULL) {

            ptr = ptr->next;
        }

        delete(ptr->next);
        ptr->next = NULL;
        cout << "***Last node has been deleted***" << endl;
    }
}

template<class T>
void LinkedList<T>::search_MA(string x)
{
    node<T>* current = head; // Initialize current  
    while (current != NULL)
    {
        if (current->Matric_Number == x) {
            cout << "student Name" << "     " << "Matric number" << "     " << "Year" << "   " << "CGPA" << endl;
            cout << current->Student_Name << "                 " << current->Matric_Number << "              " << current->Year << "      " << current->CGPA << endl;
        }
        current = current->next;
    }
}

template<class T>
void LinkedList<T>::search_CGPA(double CGPA)
{
    node<T>* current = head; // Initialize current  
    while (current != NULL)
    {
        if (current->CGPA == CGPA) {
            cout << "student Name" << "     " << "Matric number" << "     " << "Year" << "   " << "CGPA" << endl;
            cout << current->Student_Name << "                 " << current->Matric_Number << "              " << current->Year << "      " << current->CGPA << endl;
        }
        current = current->next;
    }
}

template<class T>
void LinkedList<T>::search_Year(int Year)
{
    node<T>* current = head; // Initialize current  
    while (current != NULL)
    {
        if (current->Year == Year) {
            cout << "student Name" << "     " << "Matric number" << "     " << "Year" << "   " << "CGPA" << endl;
            cout << current->Student_Name << "                 " << current->Matric_Number << "              " << current->Year << "      " << current->CGPA << endl;
        }
        current = current->next;
    }
}
#endif