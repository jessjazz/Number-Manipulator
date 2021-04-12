#include <iostream>
#include <vector>
#include <string>

using namespace std;

void display_menu();
char read_selection();
void print_vector(const vector<int>&);
void add_number(vector<int>&);
void calc_mean(const vector<int>&);
void calc_smallest(const vector<int>&);
void calc_largest(const vector<int>&);
void say_goodbye();
void handle_unknown();

int main() {    
    vector <int> numbers{};
    char selection {};
    
    do {
        display_menu();
        selection = read_selection();
        switch (selection)
        {
            case 'P':
                print_vector(numbers);
                break;
            case 'A':
                add_number(numbers);
                break;
            case 'M':
                calc_mean(numbers);
                break;
            case 'S':
                calc_smallest(numbers);
                break;
            case 'L':
                calc_largest(numbers);
                break;
            case 'Q':
                say_goodbye();
                break;
            default:
                handle_unknown();
        }
    } while (selection != 'Q');
    return 0;
}

void display_menu()
{
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
}

char read_selection()
{
    char selection {};
    cout << "\nEnter your selection: ";
    cin >> selection;
    return toupper(selection);
}

void print_vector(const vector<int> &numbers)
{
    if (numbers.size() == 0)
            cout << "\n[] - the list is empty" << endl;
    else
    {
        cout << "\n[ ";
        for (auto item : numbers)
            cout << item << " ";
        cout << "]" << endl;
    }
    cout << endl;
}

void add_number(vector<int> &numbers)
{
    int number {};
    cout << "\nEnter a number to add to the list: ";
    cin >> number;
    numbers.push_back(number);
    cout << number << " added.\n" << endl;
}

void calc_mean(const vector<int> &numbers)
{
    int total {};
    if (numbers.size() == 0)
        cout << "Unable to calculate the mean - no data" << endl;
    else
    {
        for (auto item : numbers)
            total += item;
        cout << "\nThe mean is: " << static_cast<double>(total)/numbers.size() << endl;
    }
}

void calc_smallest(const vector<int> &numbers)
{
    int min {};
    if (numbers.size() == 0)
        cout << "Unable to determine the smallest number - list is empty" << endl;
    else
    {
        min = numbers.at(0);
        for (auto item : numbers)
        {
            if (item <= min)
                min = item;
        }
        cout << "\nThe smallest number is " << min << endl;
    }
}

void calc_largest(const vector<int> &numbers)
{
    int max {};
    if (numbers.size() == 0)
        cout << "Unable to determine the largest number - list is empty" << endl;
    else
    {
        max = numbers.at(0);
        for (auto item : numbers)
        {
            if (item >= max)
                max = item;
        }
        cout << "\nThe largest number is " << max << endl;
    }
}

void say_goodbye()
{
    cout << "\nGoodbye\n" << endl;
}

void handle_unknown()
{
    cout << "Unknown selection, please try again." << endl;
}