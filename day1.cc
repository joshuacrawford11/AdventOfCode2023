#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

string FindDigits (string &inputstring)
{
    int N = inputstring.length();
    string nums;

    // Scan line to find any digits

    for (int i = 0; i < N ; i++)
    {
        if (isdigit(inputstring[i]))
        {
            // Append digits to overall number
            nums.push_back(inputstring[i]);
        }
    }
    return nums;
}

int main ()
{
    ifstream inputfile ("./inputs/day1.txt");
    string line;
    string nums;
    int val;
    int sum = 0;
    
    if ( inputfile.is_open() )
    {
        while ( getline ( inputfile,line ) )
        {
            // Find digits in line
            nums = FindDigits( line );

            // Extract first and last digit
            char first = nums[0];
            char last = nums.back();
            // Create two digit number
            string val = string() + first + last ;
            cout << val << "\n";
            // Convert to integer
            stringstream container(val);
            int x;
            container >> x;
            // Add to sum
            sum = sum + x;

        }
        inputfile.close();
    }

    cout << "The sum of all two digit numbers is " << sum << "\n";
    return 0;
}