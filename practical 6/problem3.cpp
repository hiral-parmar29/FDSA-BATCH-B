#include <iostream>
#include <string>
using namespace std;

char s[100];
int top = -1;

void push(char ch)
{
    if (top < 99)
    {
        top++;
        s[top] = ch;
    }
}

char pop()
{
    char ch = s[top];
    top--;
    return ch;
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int main()
{
    string infix, postfix = "";

    cout << "Enter infix expression: ";
    getline(cin, infix);

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if ((ch >= '0' && ch <= '9') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z'))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && s[top] != '(')
            {
                postfix += pop();
            }

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && s[top] != '(' &&
                   precedence(s[top]) >= precedence(ch))
            {
                postfix += pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        postfix += pop();
    }

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}