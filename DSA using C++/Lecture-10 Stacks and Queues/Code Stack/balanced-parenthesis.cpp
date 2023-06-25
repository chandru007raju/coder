
#include <iostream>
// #include "stack-using-array.cpp"
#include "StackLLT.cpp" // You Can Use This Or You Can Use The InBuilt Library called Stack by including the stack header file

#include <string>
// #include <stack> // If This Program Does Not Run Then Run This file in the Replit online this works well !;
using namespace std;

bool isBalanced(string expression) // (a+b(c)) -->input
{
    StackLLT<char> s;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            s.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            if (s.isEmpty())
            {
                return false;
            }
            else if (s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return (s.isEmpty() ? true : false);
}

int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}