#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const * argv[]) {
    /* code */
    // Check the number of parameters
    if (argc < 2) {
        // Tell the user how to run the program
        std::cerr << "Usage: " << argv[0] << " NAME" << std::endl;
        /* "Usage messages" are a conventional way of telling the user
         * how to run a program if they enter the command incorrectly.
         */
        return 1;
    }

    // cout << "There are " << argc << " arguments:\n";
    // // Loop through each argument and print its number and value
    // for (int count = 0; count < argc; ++count) {
    //     cout << count << " " << argv[count] << '\n';
    // }

    ifstream inFile;
    inFile.open(argv[1]);

    int a, b;
    inFile >> a;
    inFile >> b;
    cout << a + b << endl;
    return 0;
}
