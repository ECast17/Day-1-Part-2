#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>
using namespace std;

const string numberAsStrings[10] = { "zero", "one", "two", "three", "four",
"five", "six", "seven", "eight", "nine" };

int parseLine(string& toParse) 
{
    vector<int> nums;
    string currentNum = "";

    for (char c : toParse) 
    {
        if (isdigit(c)) 
        {
            currentNum += c;
        }
        else if (isalpha(c)) 
        {
            currentNum += tolower(c);
            for (int j = 0; j < 10; j++)
            {
              if (currentNum == numberAsStrings[j]) 
              {
                nums.push_back(j);
                currentNum = "";
                 break;
              }
            }
        }
        else if (!currentNum.empty()) 
        {
            try 
            {
                nums.push_back(stoi(currentNum));
            }
            catch (exception& e) 
            {
                cout << "Invalid number: " << currentNum << endl;
            }
            currentNum = "";
        }
    }
    if (!currentNum.empty()) 
    {
        try 
        {
            nums.push_back(stoi(currentNum));
        }
        catch (exception& e) 
        {
            cout << "Invalid number: " << currentNum << endl;
        }
    }
    if (nums.empty()) 
    {
        cout << "No numbers found in line: " << toParse << endl;
        return 0;
    }
    else if (nums.size() < 2) 
    {
        return nums.front();
    }
    else 
    {
        return nums.front() * 10 + nums.back();
    }
}
int main()
{
	int outputSum = 0; // This is a local variable that stores the sum of all the numbers in the file, initialized to zero

	ifstream fs; // This is an object of the ifstream class that represents a file input stream

	fs.open("C:\\Users\\EricC\\OneDrive\\Advent Coding\\Day 1 text file.txt");

	string line; // This is another local variable that stores the current line of the file

	if (fs.is_open())
	{
		while (getline(fs, line)) // This is a while loop that reads each line of the file and stores it in the line variable
		{
			outputSum += parseLine(line);
			// This is an assignment statement that adds the result of calling the parseLine function with 
			// the line variable to the outputSum variable
		}
	}
	cout << outputSum; // This is an output statement that prints the outputSum variable to the standard output stream

	fs.close();
}