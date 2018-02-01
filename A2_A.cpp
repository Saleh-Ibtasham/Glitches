#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n;
    string astring;
    stack <char> mystack;

    cin >> n;

    while(n--)
    {
		cin >> astring;
		
		bool flag = true;
		
		for(int i=0; i<astring.length(); i++)
		{
			if((astring[i] == ')')||(astring[i] == ']'))
			{
				if(mystack.empty())
					flag = false;
				else if((astring[i] == ')') && (mystack.top() == '('))
					mystack.pop();
				else if((astring[i] == ']') && (mystack.top() == '['))
					mystack.pop();
				else
					flag = false;
			}
			
			else
				mystack.push(astring[i]);
		}
		if(flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
    }

    return 0;
}
