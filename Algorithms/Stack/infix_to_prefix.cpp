
#include <bits/stdc++.h>
#include<string>
#include<stack>
using namespace std;


    string removeSpaces(string s)  //Removes Spaces from input
    {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        return s;
    }

    bool isOperator(char c)  //Check for operator
    {
       return (!isalpha(c) && !isdigit(c));
    }

    int getPriority(char C)  //Get priority of operators
    {
      if (C == '-' || C == '+')
        return 1;
      else if (C == '*' || C == '/')
        return 2;
      else if (C == '^')
        return 3;
      return 0;
    }

    string infixToPrefix(string infix)   //Converts Infix to Prefix
{ 
      // stack for operators. 
      stack<char> operators; 
    
      // stack for operands. 
      stack<string> operands; 
    
      for (int i = 0; i < infix.length(); i++) { 
    
          // If current character is an 
          // opening bracket, then 
          // push into the operators stack. 
          if (infix[i] == '(') { 
              operators.push(infix[i]); 
          } 
    
          // If current character is a 
          // closing bracket, then pop from 
          // both stacks and push result 
          // in operands stack until 
          // matching opening bracket is 
          // not found. 
          else if (infix[i] == ')') { 
              while (!operators.empty() &&  
                    operators.top() != '(') { 
    
                  // operand 1 
                  string op1 = operands.top(); 
                  operands.pop(); 
    
                  // operand 2 
                  string op2 = operands.top(); 
                  operands.pop(); 
    
                  // operator 
                  char op = operators.top(); 
                  operators.pop(); 
    
                  // Add operands and operator 
                  // in form operator + 
                  // operand1 + operand2. 
                  string tmp = op + op2 + op1; 
                  operands.push(tmp); 
              } 
    
              // Pop opening bracket from 
              // stack. 
              operators.pop(); 
          } 
    
          // If current character is an 
          // operand then push it into 
          // operands stack. 
          else if (!isOperator(infix[i])) { 
              operands.push(string(1, infix[i])); 
          } 
    
          // If current character is an 
          // operator, then push it into 
          // operators stack after popping 
          // high priority operators from 
          // operators stack and pushing 
          // result in operands stack. 
          else { 
              while (!operators.empty() &&  
                    getPriority(infix[i]) <=  
                      getPriority(operators.top())) { 
    
                  string op1 = operands.top(); 
                  operands.pop(); 
    
                  string op2 = operands.top(); 
                  operands.pop(); 
    
                  char op = operators.top(); 
                  operators.pop(); 
    
                  string tmp = op + op2 + op1; 
                  operands.push(tmp); 
              } 
    
              operators.push(infix[i]); 
          } 
      } 
    
      // Pop operators from operators stack 
      // until it is empty and add result 
      // of each pop operation in 
      // operands stack. 
      while (!operators.empty()) { 
          string op1 = operands.top(); 
          operands.pop(); 
    
          string op2 = operands.top(); 
          operands.pop(); 
    
          char op = operators.top(); 
          operators.pop(); 
    
          string tmp = op + op2 + op1; 
          operands.push(tmp); 
      } 
    
      // Final prefix expression is 
      // present in operands stack. 
      return operands.top(); 
  } 


    int main()
    {
      int value;
      string s;
      cout<<"Enter Infix expression here\n";
      getline(cin,s);
      if(s.size()>=1){
      s=removeSpaces(s);
      cout<<"Prefix : "<<infixToPrefix(s)<<endl;
      }
      return 0;
    }
