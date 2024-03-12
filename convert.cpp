/*
    convert.cpp

    Convert the text

    Note: The "@concern" are for pedagogical purposes only.

    * @concern are assume to be [in], meaning they are predefined and used in the code
    * @concern marked [out] meaning they are produced in that section
*/

#include <iostream>
#include <string>
#include <cctype>

// @concern "--lower", isOptionLower[out]
bool isOptionLower(const std::string& s) {

    return s == "--lower";
}

// @concern "--upper", isOptionUpper[out]
bool isOptionUpper(const std::string& s) {

    return s == "--upper";
}

// @concern std::toupper(), toUpper[out]
void toUpper(char& c) {
    c = std::toupper(c);
}

// @concern std::tolower(), toLower[out]
void toLower(char& c) {
    c = std::tolower(c);
}

// output character to standard output
// @concern output format, std::cout, output[out]
void output(char& c) {
    std::cout << c;
}

// Conversion function type
typedef void (*Conversion)(char& c);

// @concern std::string, iteration, apply, myforeach[out]
void myforeach(std::string::iterator begin, std::string::iterator end, Conversion apply) {

    for (auto pc = begin; pc != end; ++pc)
        apply(*pc);
}

int main(int argc, char* argv[]) {

    // requires conversion option and string
    // @concern input format, argc, argv, error handling, std::cerr
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <option> <string>\n";
        return 1;
    }

    // conversion option
    // @concern input format, argv, std::string, option[out]
    std::string option(argv[1]);

    // input text
    // @concern input format, argv, std::string, text[out]
    std::string text(argv[2]);

    // convert the string according to the option
    // @concern option, isOptionUpper(), isOptionLower()
    // @concern std::string, toUpper(), toLower()
    // @concern error handling, std::cerr
    Conversion convert = nullptr;
    if (isOptionUpper(option)) {

        convert = toUpper;

    } else if (isOptionLower(option)) {

        convert = toLower;

    } else {

        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }

    // convert the string according to the conversion function
    // @concern myforeach(), text
    myforeach(text.begin(), text.end(), convert);

    // output converted text
    // @concern output format, text, output(), myforeach()
    myforeach(text.begin(), text.end(), output);
    std::cout << '\n';

    return 0;
}
