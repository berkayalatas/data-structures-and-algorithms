#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
float numaraTara(char ch) {
   int deger;
   deger = ch;
   return float(deger-'0');  
}
int operatorMu(char ch) {
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;    
   return -1;   
}
int operandMi(char ch) {
   if(ch >= '0' && ch <= '9')
      return 1;  
   return -1;   
}
float operation(int a, int b, char op) {

   if(op == '+')
      return b+a;
   else if(op == '-')
      return b-a;
   else if(op == '*')
      return b*a;
   else if(op == '/')
      return b/a;
   else if(op == '^')
      return pow(b,a); // b^a
   else
      return INT_MIN; 
}
float postfixX(string postfix) {
   int a, b;
   stack<float> value;
   string::iterator itr;
   
   for(itr=postfix.begin(); itr!=postfix.end(); itr++) {

      if(operatorMu(*itr) != -1) {
      	
         a = value.top();
         value.pop();
         
         b = value.top();
         value.pop();
         
         value.push(operation(a, b, *itr));
         
      }else if(operandMi(*itr) > 0) {
         value.push(numaraTara(*itr));
      }
   }
   return value.top();
}
main() {
	
	string postfix;
	
	cout << "Postfix ifade giriniz: ";
	cin >> postfix;
	
    cout << "The result is: "<<postfixX(postfix);
}
