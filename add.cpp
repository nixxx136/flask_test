#include <iostream>
#include <fstream>
// JSON support library
#include <json/json.h>

#include "ArgumentParsing.h"
using namespace std;

int main(int argc, char * argv[]) {
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


    // Argument parser for handling input from the command line
    // options that might be provided by the user.
    sivelab::ArgumentParsing argParser;

    // Sets up the options that will be available on the command line
    argParser.reg("help", "help/usage information",
                  sivelab::ArgumentParsing::NONE, '?');
    argParser.reg("verbose", "turn on verbose output if utilized",
                  sivelab::ArgumentParsing::NONE, 'v');
    argParser.reg("inputfile", "input file name for reading initial parameters",
                  sivelab::ArgumentParsing::STRING, 'i');

    // processes the options specified above with those supplied by
    // the user through the argv character array
    argParser.processCommandLineArgs(argc, argv);

    // if help was specified, print out the usage
    if (argParser.isSet("help")) {
        argParser.printUsage();
        exit(EXIT_SUCCESS);
    }

    // Enable verbose mode for extra debugging output
    bool verbose = argParser.isSet("verbose");
    if (verbose) {
        std::cout << "Verbose Output: ON" << std::endl;
    }

    // Extract the input file to read the initial JSON-specified parameters
    std::string inputFileName;
    argParser.isSet("inputfile", inputFileName);
    if (verbose) {
        std::cout << "Setting input JSON filename to " << inputFileName
                  << std::endl;
    }

    // ////////////////////////////////////////
    // Parse the file using the JSON format
    // ////////////////////////////////////////

    // Create an input stream from the file to provide to the json
    // reader
    std::ifstream ifsJSON(inputFileName, std::ifstream::in);

    Json::Value jsonRoot; // will contains the root value after parsing.
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(ifsJSON, jsonRoot);
    if (!parsingSuccessful) {
        // report to the user the failure and their locations in the document.
        std::cout << "Failed to parse configuration\n"
                  << reader.getFormattedErrorMessages();
        return EXIT_FAILURE;
    }

    // cout << "There are " << argc << " arguments:\n";
    // // Loop through each argument and print its number and value
    // for (int count = 0; count < argc; ++count) {
    //     cout << count << " " << argv[count] << '\n';
    // }

    int a, b;
    a = jsonRoot["a"].asInt();
    b = jsonRoot["b"].asInt();
    cout << a + b << endl;
    cout << "end" << endl;
    return 0;
}
