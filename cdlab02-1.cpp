#include <iostream>
#include <string>
using namespace std;

void commentDetect()
{
    string input;

    cout << "Enter text (use multiple lines if needed, and press ENTER + CTRL+Z (Windows) or CTRL+D (Linux) to finish):\n";

    string line;
    while (getline(cin, line))
    {
        input += line + '\n';
    }

    bool found = false;

    for (int i = 0; i < input.length() - 1; i++)
    {
        // Detect single-line comment //
        if (input[i] == '/' && input[i + 1] == '/')
        {
            found = true;
            cout << "\nSingle-line Comment Found:\n";
            i += 2; // skip "//"
            while (i < input.length() && input[i] != '\n')
            {
                cout << input[i];
                i++;
            }
            cout << endl;
        }

        // Detect multi-line comment /* ... */
        else if (input[i] == '/' && input[i + 1] == '*')
        {
            found = true;
            cout << "\nMultiline Comment Found:\n";
            i += 2; // skip "/*"
            while (i < input.length() - 1)
            {
                if (input[i] == '*' && input[i + 1] == '/')
                {
                    cout << "\n(Comment ends here)\n";
                    i++;
                    break;
                }
                cout << input[i];
                i++;
            }
        }
    }

    if (!found)
        cout << "\nNo comment found.\n";
}

int main()
{
    commentDetect();
    return 0;
}
