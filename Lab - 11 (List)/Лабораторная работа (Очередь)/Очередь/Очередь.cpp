#include <iostream>
using namespace std;
struct Node                          
{
    int x;                           
    Node* Next;                      
};
Node* Head = 0, * Tail = 0;
void Clear()
{
    Node* temp = Head;                     
    while (temp != NULL)                   
    {
        temp = Head->Next;                 
        delete Head;                     
        Head = temp;                      
    }
}
void Add(int x)
{
    Node* temp = new Node;
    temp->x = x;                      
    temp->Next = NULL;                 
    if (Head != NULL)                  
    {
        Tail->Next = temp;              
        Tail = temp;
    }
    else Head = Tail = temp;     
}
void Show()
{
    Node* temp = Head;                 
    while (temp != NULL)             
    {
        cout << temp->x << " ";       
        temp = temp->Next;             
    }
    cout << endl;
}
void del()
{
    if (Head != NULL)                 
    {
        Node* temp = Head;            
        cout << "Элемент " << Head->x << " вышел" << endl;
        Head = Head->Next;            
        delete temp;                  
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    system("CLS");
    srand(time(0));
    int choose;
    int size;
    while (true)
    {
        system("cls");
        cout << "Добавть элемент - 1" << endl;
        cout << "Вывести очередь - 2" << endl;
        cout << "Удалить элемент - 3" << endl;
        cout << "Выйти из программы - любое число, кроме пердставленных выше" << endl;
        cout << "Введите команду - ";
        cin >> choose;
        cin.get();
        switch (choose)
        {
            case 1:
            {
                system("cls");
                cout << "Сколько элементов хотите добавить? ";
                cin >> size;
                cin.get();
                for (int i = 0; i < size; i++)
                {
                    int a = 10 + rand() % 50;
                    Add(a);
                    cout << "Элемент - " << a << " был добавлен в очередь" << endl;
                }
                cout << "Нажмите Enter, чтобы выйти" << endl;
                cin.get();
                break;
            }
            case 2:
            {
                system("cls");
                Show();
                cout << "Нажмите Enter, чтобы выйти" << endl;
                cin.get();
                break;
            }
            case 3:
            {
                system("cls");
                del();
                cout << "Нажмите Enter, чтобы выйти" << endl;
                cin.get();
                break;
            }
            default:
            {
                Clear();
                return 0;
            }
        }
    }
}
