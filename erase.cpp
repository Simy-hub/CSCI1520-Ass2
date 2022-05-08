//assignment3.cpp
/*CSCI1520
 *
 *Assignment: 3
 *Student ID: 1155157111
 *Name      : Jinmin Chen
 *Email     : 1155157111@link.cuhk.edu.hk
 */
#include<iostream>
using namespace std;
// Global variable to store the final answer
string ans = "";

/* A recursive funtion which checks the first character
of the passed argument string s and removes it straight away
if its a lower case character.
Else, the function just appends the character to the global variable
string "ans" and then deletes the character from the passed argument variable
so that the next recursion can process the remaining string.
This process is done till the size of the passed argument becomes 0 at which
point we return the global variable ans
*/
string removeLower(string s)
{
	if (s.size() == 0)
		return ans;
	// Check for lower case charcters
	if (s[0] >= 'a' && s[0] <= 'z')
		s.erase(0, 1); // Removes 1 character from index 0
	else
	{
		ans += s[0];
		s.erase(0, 1); // Removes 1 character from index 0
	}
	return removeLower(s);
}
int main()
{
	// Driver code to test the above function
	string testString = "aAbBcCdD";
	cout << removeLower(testString);
	return 0;
}