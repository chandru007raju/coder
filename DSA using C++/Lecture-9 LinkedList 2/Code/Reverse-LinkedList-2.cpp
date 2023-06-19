
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

/*

Node *reverseLinkedListRec(Node *head)
{
    if (head == NULL || head -> next == NULL){
        return head;
    }
	Node * smallOutput = reverseLinkedListRec(head -> next);
	Node * temp = smallOutput;
    while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = head;
    head -> next = NULL;
    return smallOutput;
}
*/
// O(n) but using extra space

class Pair{
    public:
    Node *head;
    Node *tail;
};

Pair helper(Node *head){
    if (head == NULL || head -> next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    
    Pair smallAns = helper(head -> next);
    smallAns.tail -> next = head;
    head -> next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reverseLinkedListRec(Node *head){
    return helper(head).head;
}

/*

// O(n) no extra space
// Node *reverseLinkedListRec(Node *head){
    
//     if (head == NULL || head -> next == NULL){
//         return head;
//     }
// 	Node * smallOutput = reverseLinkedListRec(head -> next);
// 	head -> next -> next = head;
//     head -> next = NULL;
//     return smallOutput;
// }

*/

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        head = reverseLinkedListRec(head);
        print(head);
    }

    return 0;
}