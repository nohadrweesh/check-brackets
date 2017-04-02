#include <iostream>
#include <stack>
#include <string>

struct Bracket {
	Bracket(char type, int position) :
		type(type),
		position(position)
	{}


	bool Matchc(char c) {
		if (type == '[' && c == ']')
			return true;
		if (type == '{' && c == '}')
			return true;
		if (type == '(' && c == ')')
			return true;
		return false;
	}

	char type;
	int position;
};

int main() {
	std::string text;
	getline(std::cin, text);
	char chartyop;
	//int pos = -1;
	int flag = -1;

	std::stack <Bracket> opening_brackets_stack;

	char c = ' '; int p = -1;
	struct Bracket b2(c, p);
	int endBracket = -1, endBracketPos = 0;

	for (int position = 0; position < text.length(); ++position) {
		char next = text[position];

		if (next == '(' || next == '[' || next == '{') {
			// Process opening bracket, write your code here
			struct Bracket b(next, position);
			opening_brackets_stack.push(b);

		}

		else if (opening_brackets_stack.empty() && (next == ')' || next == ']' || next == '}')){
			// Process closing bracket, write your code here
			endBracket = 1;
			if (flag == -1){
				endBracketPos = position + 1;
			}
			flag++;
		}
		else if (!opening_brackets_stack.empty() && (next == ')' || next == ']' || next == '}')){
			// Process closing bracket, write your code here
			//endBracket = 1; endBracketPos = position + 1;

			b2 = opening_brackets_stack.top();
			if (b2.Matchc(next)){
				opening_brackets_stack.pop();
			}
			else{
				endBracket = 1;
				if (flag == -1){
					endBracketPos = position + 1;
				}
				flag++;
			}
		}

	}

	// Printing answer, write your code here
	if (endBracket == -1 && opening_brackets_stack.empty())
		std::cout << "Success\n";
	else if (endBracket == -1 && !opening_brackets_stack.empty())
		std::cout << opening_brackets_stack.top().position + 1 << "\n";
	else{

		std::cout << endBracketPos << "\n";

	}

	system("pause");

	return 0;
}
//#include<iostream>
//#include<stack>
//#include<string>
//
//using namespace std;
//// Function to check whether two characters are opening 
//// and closing of same type. 
//bool ArePair(char opening, char closing)
//{
//	if (opening == '(' && closing == ')') return true;
//	else if (opening == '{' && closing == '}') return true;
//	else if (opening == '[' && closing == ']') return true;
//	return false;
//}
//bool AreParanthesesBalanced(string exp)
//{
//	stack<char>  S;
//	for (int i = 0; i<exp.length(); i++)
//	{
//		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
//			S.push(exp[i]);
//		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
//		{
//			if (S.empty() || !ArePair(S.top(), exp[i]))
//				return false;
//			else
//				S.pop();
//		}
//	}
//	return S.empty() ? true : false;
//}
//
//int main()
//{
//	/*Code to test the function AreParanthesesBalanced*/
//	string expression;
//	cout << "Enter an expression:  "; // input expression from STDIN/Console
//	cin >> expression;
//	if (AreParanthesesBalanced(expression))
//		cout << "Balanced\n";
//	else
//		cout << "Not Balanced\n";
//	system("pause");
//}
