#include <iostream>
#include <vector>
#include <string>

//Esto es el Jelougüorld pero más fancy.

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    {
	std::cout << "Hello, world!";
	return 0;
}
} 