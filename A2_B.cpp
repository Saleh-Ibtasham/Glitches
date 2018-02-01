#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

struct content
{
	string number;
	char symbol;
	bool flag; // true if number
};

char operators[6] = {'+', '-', '*', '/', '(', ')'};

void replaceSymbols(string &numbers)
{
	for(int i=0;i< 6;i++)
	{
		for(int j=0; j<numbers.length(); j++)
		{
			if(numbers[j]==operators[i]) numbers[j]= ' ';
		}
	}
}

void makeContentWithSymbol(content &node, char symbol)
{
	node.symbol = symbol;
	node.flag = false;
}

void makeContentWithNumber(content &node, string number)
{
	node.number = number; 
	node.flag = true;
}

void parsingInput(string inputString, vector <content> &infix)
{
	string numbers = inputString;
	replaceSymbols(numbers);
	
	istringstream iss(numbers);
	
	vector <string> numbersObtained;
	string temp;
	while(iss>>temp)
	{
		numbersObtained.push_back(temp);
	}
	
	for(int i=0; i<numbers.length(); i++)
	{
		if(numbers[i] == ' ')
		{
			if(i!=0)
			{
				if(numbers[i-1] != ' ')
				{
					content node;
					
					makeContentWithNumber(node, numbersObtained[0]);
					infix.push_back(node);
					numbersObtained.erase(numbersObtained.begin());
					
					makeContentWithSymbol(node, inputString[i]);
					infix.push_back(node);
				}
				else
				{
					content node;
					makeContentWithSymbol(node, inputString[i]);
					infix.push_back(node);
				}
			}
			else
			{
				content node;
				makeContentWithSymbol(node, inputString[i]);
				infix.push_back(node);
			}
		}
	}
	
	if(!numbersObtained.empty())
	{
		content node;
		makeContentWithNumber(node, numbersObtained[0]);
		infix.push_back(node);
		numbersObtained.erase(numbersObtained.begin());
	}
}

bool lowerPrecedence(char infixSymbol, char stackSymbol)
{
	if((infixSymbol=='/'|| infixSymbol=='*')&&(stackSymbol=='+'||stackSymbol=='-')) return true;
	else return false;
}

void infixToPostfix(vector <content> infix, vector <content> &postfix)
{
	stack <content> myStack;
	
	content node;
	makeContentWithSymbol(node, '(');
	myStack.push(node);
	
	makeContentWithSymbol(node, ')');
	infix.push_back(node);
	
	for(int i=0; i<infix.size(); i++)
	{
		if(infix[i].flag)
		{
			postfix.push_back(infix[i]);
		}
		else
		{
			if(infix[i].symbol == '(')
			{
				myStack.push(infix[i]);
			}
			else if(infix[i].symbol == ')')
			{
				while(1)
				{
					content tempNode = myStack.top();
					
					if(tempNode.symbol=='(')
					{
						myStack.pop();
						break;
					}
					else
					{
						postfix.push_back(tempNode);
						myStack.pop();
					}
				}
			}
			else
			{
				while(1)
				{
					content tempNode = myStack.top();
					if((lowerPrecedence(infix[i].symbol, tempNode.symbol))||(tempNode.symbol == '(')) break;
					postfix.push_back(tempNode);
					myStack.pop();
				}
				myStack.push(infix[i]);
			}
		}
	}
}

void printExpression(vector <content> expression)
{
	for(int i=0; i<expression.size(); i++)
	{
		if(expression[i].flag) cout << expression[i].number;
		else cout << expression[i].symbol;
	}
	cout << endl;
}

int main (void)
{
	int n;
	string temp;
	
	cin >> n;
	getline(cin,temp);
	
	while(n--)
	{
		string inputString;
		getline(cin,inputString);
	
		vector <content> infix;
		parsingInput(inputString, infix);
	
		vector <content> postfix;
		infixToPostfix(infix, postfix);
	
		printExpression(postfix);
	
	}
	
	return 0;
}
