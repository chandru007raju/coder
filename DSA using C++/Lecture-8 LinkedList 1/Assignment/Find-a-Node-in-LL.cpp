
#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

// int findNode(Node *head, int n)
// {

//     Node *temp = head;
//     int count = 0;
//     while (temp != NULL)
//     {
//         if (temp->data == n)
//         {
//             return count;
//         }
//         temp = temp->next;
//         count++;
//     }
//     return -1;
// }

//
int findNode(Node *head, int n) // head-->1 -->2 -->3 -->4
{
    Node * temp = head;
    int count = 0;
    while(temp!= NULL){

        if(temp->data == n){
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;    
}
//

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int val;
        cin >> val;
        cout << findNode(head, val) << endl;
    }
}