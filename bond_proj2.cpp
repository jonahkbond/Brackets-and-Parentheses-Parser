#include <cstdio>
#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main()
 {
    string line;
    //read from file input.txt
    ifstream myFile("input.txt");
    if (myFile.is_open()) 
      {
	//while reading lines from input.txt
        while (getline(myFile, line)) 
	  {
	    //create a stack for chars
            stack<char> theStack;
            int i = 0;
	    //add period to the end of the line read to signify the end of the string
            string w = line + ".";

	    //use while loop to iterate through the line
            while (w[i]) {
	      //check if the chars are parenthesis or brackets 
                if (w[i] == '(' || w[i] == ')' || w[i] == '[' || w[i] == ']' || w[i] == '.')
                {
		  //make sure that the stack is not empty to avoid segmentation fault
                    if (!theStack.empty())
                    {
		      //pop conditions
                        if (w[i] == ')' && theStack.top() == '(' || w[i] == ']' && theStack.top() == '[')
                        {
                            theStack.pop();
                        }
                    }
		    //for all other cases push in the pda, push
                    else if (w[i] == '(' || w[i] == ')' || w[i] == '[' || w[i] == ']')
                    {
                        theStack.push(w[i]);
                    }
		    //if we reach the end of the string and the stack is empty then the parentheses are balanced for the string
                    if (w[i] == '.' && theStack.empty())
                    {
                        cout << "Parentheses are balanced for string " << line << "." << endl;
                    }
		    //else the parentheses is not balanced for the string
                    else if (w[i] == '.' && !theStack.empty())
                    {
                        cout << "Parentheses are not balanced " << line << "." << endl;
                    }
                }
		//increment the loop
                i++;
            }
        }
	//close myfile
        myFile.close();
    } else cout << "Unable to open file";
    return 0;
}
