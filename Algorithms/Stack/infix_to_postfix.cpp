//Infix to Postfix Converter
//Language Used: C++
//Infix to Postfix Converter Algorithm uses Stack to convert given Infix expression to Postfix
//Input Format: Input contains only one line i.e., Infix Expression
//Output Format: Output contains only one line i.e., Postfix Expression
//Sample Input:  3*(7-9)
//Sample Output: 379-*
//author: adiXcodr

#include <bits/stdc++.h>
#include<string>
#include<stack>
using namespace std;


    string removeSpaces(string str)  //Removes spaces from input
    {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        return str;
    }

    bool isOperator(char opr)
    {
       return (!isalpha(opr) && !isdigit(opr));
    }

    int getPriority(char opr)  //Checks Priority of operators
    {
      if (opr == '-' || opr == '+')
        return 1;
      else if (opr == '*' || opr == '/')
        return 2;
      else if (opr == '^')
        return 3;
      return 0;
    }

    string infixToPostfix(string infix) //Conversion
    {
      infix = '(' + infix + ')';
      int len = infix.size();
      stack<char> char_stack;
      string output;

      for (int inx = 0; inx < len; inx++) {
        if (isalpha(infix[inx]) || isdigit(infix[inx]))
          output += infix[inx];
        else if (infix[inx] == '(')
          char_stack.push('(');
        else if (infix[inx] == ')') {
          while (char_stack.top() != '(') {
            output += char_stack.top();
            char_stack.pop();
          }
          char_stack.pop();
        }
        else {

          if (isOperator(char_stack.top())) {
            while (getPriority(infix[inx])
            <= getPriority(char_stack.top())) {
              output += char_stack.top();
              char_stack.pop();
            }
            char_stack.push(infix[inx]);
          }
        }
      }
      return output;
    }



    int main()
    {
      string infix;
      cout<<"Enter Infix expression here : ";
      getline(cin,infix);
      if(infix.size()>=1){
      infix=removeSpaces(infix);
      cout<<"Postfix : "<<infixToPostfix(infix);
      }
      return 0;
    }
