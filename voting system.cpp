#include <iostream>
#include <conio.h> // Added for password hiding
using namespace std;

// Define a structure to store user credentials
struct User
{
    string username;
    string password;
};

struct Voter
{
    string name;
    int age;
    string partyName;
};

int votes[8] = {0}; // Using an array to store votes for each party
int spoiltVotes = 0;
int numVoters = 0;

// Function to hide the password while typing
string getPassword()
{
    string password;
    char c;
    while ((c = _getch()) != 13) // 13 is the ASCII value for Enter key
    {
        if (c == 8) // 8 is the ASCII value for Backspace key
        {
            if (!password.empty())
            {
                cout << "\b \b"; // Move the cursor back, print a space to erase the character, and move the cursor back again
            }
        }
        else
        {
            password.push_back(c);
            cout << '*'; // Print asterisks instead of the actual characters
        }
    }
    cout << endl;
    return password;
}

int main()
{
    int i, age;
    User user;
    bool isLoggedIn = false;

    // Register a user
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t       ONLINE VOTING SYSTEM \n\n";
    cout << "\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t  REGISTRATION \n";
    cout << "\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\tEnter username: ";
    cin >> user.username;
    cout << "\t\t\t\t\tEnter Password: ";
    user.password = getPassword();

    // Log in the user
    while (!isLoggedIn)
    {
        system("CLS");
        cout << "\n\t\t\t\t\t\t     LOGIN \n";
        cout << "\t\t\t\t\t------------------------------\n\n";
        cout << "\t\t\t\t\tEnter username: ";
        string username;
        cin >> username;
        cout << "\t\t\t\t\tEnter Password: ";
        string password = getPassword();

        if (username == user.username && password == user.password)
        {
            cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
            isLoggedIn = true;
        }
        else
        {
            cout << "Invalid username or password. Please try again." << endl;
            system("PAUSE");
        }
    }

    int numVoters = 0;
    Voter voters[500];

    do
    {
        system("CLS");
        numVoters++;
        cout << "Enter your name: ";
        cin >> voters[numVoters].name;
        cout << "Enter your age: ";
        cin >> voters[numVoters].age;

        if (voters[numVoters].age >= 18)
        {
            cout << voters[numVoters].name << " is eligible for voting." << endl;
            cout << "List of political parties in Tamil Nadu:" << endl;
            cout << "1. BMK" << endl;
            cout << "2. IAADMK" << endl;
            cout << "3. CMK" << endl;
            cout << "4. DAMK" << endl;
                        cout << "5. DKDK" << endl;
            cout << "6. AMKM" << endl;
            cout << "7. NSK" << endl;
            cout << "8. Others" << endl;
            cout << "Select your political party: ";
            
            int partyChoice;
            cin >> partyChoice;
            
            if (partyChoice >= 1 && partyChoice <= 8)
            {
                votes[partyChoice - 1]++;
                switch (partyChoice)
                {
                    case 1:
                        voters[numVoters].partyName = "BMK";
                        break;
                    case 2:
                        voters[numVoters].partyName = "IAADMK";
                        break;
                    case 3:
                        voters[numVoters].partyName = "CMK";
                        break;
                    case 4:
                        voters[numVoters].partyName = "DAMK";
                        break;
                    case 5:
                        voters[numVoters].partyName = "DKDK";
                        break;
                    case 6:
                        voters[numVoters].partyName = "AMKM";
                        break;
                    case 7:
                        voters[numVoters].partyName = "NSK";
                        break;
                    case 8:
                        voters[numVoters].partyName = "Others";
                        break;
                }
                cout << "Thank you for voting!" << endl;
            }
            else
            {
                spoiltVotes++;
                voters[numVoters].partyName = "Spoilt Vote";
                cout << "Invalid party choice. Your vote is spoilt." << endl;
            }
        }
        else
        {
            cout << voters[numVoters].name << " is not eligible for voting." << endl;
            voters[numVoters].partyName = "Not Eligible";
        }
        
        cout << "Are there any more voters left? (Y/N): ";
        char option;
        cin >> option;
        
        if (option == 'N' || option == 'n')
            break;
            
    } while (true);

    system("CLS");
    cout << "Voting Summary:" << endl;
    cout << "----------------" << endl;
    cout << "Number of voters: " << numVoters << endl;
    cout << "----------------" << endl;
    
    for (int i = 0; i < 8; i++)
    {
        cout << "Number of votes for Party " << (i + 1) << ": " << votes[i] << endl;
    }
    
    cout << "Number of spoilt votes: " << spoiltVotes << endl;
    
    cout << "Do you want to access the Voting Data? (Y/N): ";
    char accessOption;
    cin >> accessOption;
    
    if (accessOption == 'Y' || accessOption == 'y')
    {
        system("CLS");
        cout << "Voting Data:" << endl;
        cout << "------------" << endl;
        
        for (int i = 1; i <= numVoters; i++)
        {
            cout << "Voter " << i << " - Name: " << voters[i].name << ", Age: " << voters[i].age << ", Party: " << voters[i].partyName << endl;
        }
    }
    else
    {
        cout << "Thank you for using the Online Voting System!" << endl;
    }
    
    return 0;
}