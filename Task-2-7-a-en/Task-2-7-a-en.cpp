#include <iostream>
#include <tchar.h>
#include <locale>
#include <string>
#include <math.h>
#include <algorithm>

int _tmain(int argc, _TCHAR* argv[])
{
	std::string a; // string for the current code
	std::string b; // string for the target code
	int total_moves = 0; // Move counter
	// Reading input data
	std::cout << "Enter the current code: ";
	std::getline(std::cin, a); // Input the current code
	std::cout << "Enter the target code: ";
	std::getline(std::cin, b); // Input the target code
	int n_len1 = a.length(); // Calculate the length of the first string
	int n_len2 = b.length(); // Calculate the length of the second string
	// Check if the lengths of the current and target codes match
	// If the length of the current code does not equal
	// the length of the target code,
	// or if either code is not four digits long, the program terminates.
	if ((n_len1 != 4) || (n_len2 != 4) || (n_len1 != n_len2))
	{
		std::cout << "The combination for the code lock "
        		  << "must be 4 digits long.\r\n";
		std::cout << "The current code and the target code must be of "
        		  << "the same length.\r\n";
		// Pause output until the "Enter" key is pressed
		std::cin.ignore();
		std::cin.get();
        return 0;
	}
	// Calculate the minimum number of moves
	for (int i = 0; i < n_len1; i++)
	{
		int x = a[i]; // Extract the digit from the current code
		int y = b[i]; // Extract the digit from the target code
        // Difference between digits (forward rotation)
		int diff1 = abs(x - y);
        // Difference between digits (reverse rotation)
		int diff2 = 10 - abs(x - y);
		// The minimum number of moves is the
        // shortest distance between each digit
		// of the current code and the target code on the safe dial.
		// The total number of moves is the final answer.
		total_moves += std::min(diff1, diff2);
	}
	// Display information on the screen
	std::cout << "Current code: " << a << "\r\n";
	std::cout << "Target code: " << b << "\r\n";
	std::cout << "Minimum number of moves: " << total_moves << "\r\n";
	// Pause output until the "Enter" key is pressed
	// std::cin.ignore();
	std::cin.get();
	return 0;
}
