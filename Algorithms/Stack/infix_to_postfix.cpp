
#include <bits/stdc++.h>
#include<string>
#include<stack>
using namespace std;


    string removeSpaces(string s)  //Removes spaces from input
    {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        return s;
    }

    bool isOperator(char c)
    {
       return (!isalpha(c) && !isdigit(c));
    }

    int getPriority(char C)  //Checks Priority of operators
    {
      if (C == '-' || C == '+')
        return 1;
      else if (C == '*' || C == '/')
        return 2;
      else if (C == '^')
        return 3;
      return 0;
    }

    string infixToPostfix(string infix) //Conversion
    {
      infix = '(' + infix + ')';
      int l = infix.size();
      stack<char> char_stack;
      string output;

      for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i]))
          output += infix[i];
        else if (infix[i] == '(')
          char_stack.push('(');
        else if (infix[i] == ')') {
          while (char_stack.top() != '(') {
            output += char_stack.top();
            char_stack.pop();
          }
          char_stack.pop();
        }
        else {

          if (isOperator(char_stack.top())) {
            while (getPriority(infix[i])
            <= getPriority(char_stack.top())) {
              output += char_stack.top();
              char_stack.pop();
            }
            char_stack.push(infix[i]);
          }
        }
      }
      return output;
    }



    int main()
    {
      int value;
      string s;
      cout<<"Enter Infix expression here\n";
      getline(cin,s);
      if(s.size()>=1){
      s=removeSpaces(s);
      cout<<"Postfix : "<<infixToPostfix(s)<<endl;
      }
      return 0;
    }
