#include <iostream>
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
   // Input data: target code and current code
    // Entered as four-digit numbers
    int total_moves = 0; // Move counter
    int a, a1; // Current code value
    int b, b1; // Target code value
    int m = 0; // Number of digits in the current code
    int n = 0; // Number of digits in the target code
    // Reading input data
    std::cout << "Enter the current code: ";
    std::cin >> a;
    std::cout << "Enter the target code: ";
    std::cin >> b;
    n = 0; // Number of digits in the current code
    a1 = a;
    b1 = b;
    // Number of digits in the current code
    while (a1 > 0)
    {
        m += 1; // Calculate the number of digits in the value.
        a1 /= 10; // Divide the value by 10.
    }
    // Number of digits in the target code
    while (b1 > 0)
    {
        n += 1; // Calculate the number of digits in the value.
        b1 /= 10; // Divide the value by 10.
    }
    // Check if the lengths of the current and target codes match
    // If the lengths are not equal, or if either code is not four digits long,
    // the program terminates.
    if ((m != 4) || (n != 4) || (m != n))
    {
        std::cout << "The combination for the combination "
        		  << "lock must be 4 digits long.";
        std::cout << "The current and target codes must be of the same length.";
        return 0;
    }
    a1 = a;
    b1 = b;
    // Iterate through the digits of the current and target codes
    while ((a1 > 0) && (b1 > 0))
    {
        int d1 = a1 % 10; // Digit from the current code
        int d2 = b1 % 10; // Digit from the target code
        // Difference between digits (direct rotation)
        int diff1 = abs(d1 - d2);
        // Difference between digits (reverse rotation)
        int diff2 = 10 - abs(d1 - d2);
        // The minimum number of moves is the smallest
        // distance between each corresponding
        // digit of the target code and the current code of the safe lock.
        total_moves += std::min(diff1, diff2);
        a1 /= 10; // Move to the next digit of the current code
        b1 /= 10; // Move to the next digit of the target code
    }
    // Display information on the screen
    std::cout << "Current code: " << a << "\r\n";
    std::cout << "Target code: " << b << "\r\n";
    std::cout << "Minimum number of moves: " << total_moves << "\r\n";
    return 0;
}
