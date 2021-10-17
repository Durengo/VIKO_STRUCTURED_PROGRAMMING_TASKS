//Standard Library inclusions
#include <iostream> //Include <iostream> for input/output.
#include <fstream> //Include <fstream> for reading and writing to files.
#include <Windows.h> //Include <windows.h> to implement command prompt functionality.

//Implemented Library inclusions
#include "ReadUser_Input.h" //This module includes the main I/O (user interaction) functionality.
#include "NavigationBar_Generator.h" //This module generates HTML code for a navigation bar.
#include "Title_Page_Generator.h" //This module generates HTML code for the title page.
#include "Module_Generator.h" //This module generates HTML code for different modules.

const std::string HTML_Top = "<!doctype html>\n"
                             "<html lang=\"en\">\n"
                             "<head>\n"
                             "\n"
                             "    <!-- Required meta tags -->\n"
                             "    <meta charset=\"utf-8\">\n"
                             "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
                             "    <!-- Website Name -->\n"
                             "    <title>Index</title>\n"
                             "    <!-- Bootstrap CSS/JS -->\n"
                             "    <link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU\" crossorigin=\"anonymous\">\n"
                             "    <script src=\"https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.bundle.min.js\" integrity=\"sha384-/bQdsTh/da6pkI1MST/rWKFNjaCP5gBSY4sEBT38Q/9RBh9AH40zEOg7Hlq2THRZ\" crossorigin=\"anonymous\"></script>\n"
                             "\n"
                             "</head>\n"; //HTML code which initializes the file.

const std::string HTML_Bot = "</body>\n</html>"; //HTML code which stops initialization.

//Function prototypes:

void Body_Generator(char& User_Input, std::ofstream& Index); //This is a function which will generate the <body> code. The user will decide which code will be implemented.

int main(){ //Here we declare our main function.

    SetConsoleOutputCP(CP_UTF8); //Setting our console to read different language characters.

    char User_Input = '1'; //This is our main char variable for user input, which will be used throughout the whole process runtime, called User_Input.

    std::ofstream Index; //Declare ofstream variable called Index - here we will create our main HTML file which we will write our code into.
    Index.open("Index.html",std::ios::in | std::ios::trunc); //Initialize the creation of "Index.html" file with 'trunc' and allow writing to file with 'in'
    Index << HTML_Top; //Print HTML code initialization.

    std::cout << "Welcome to a basic HTML code generator!" << std::endl; //Here we explain what this program does to the user and explain how to operate this program.
    std::cout << "You will be able to choose basic body elements for your website..." << std::endl;

    Body_Generator(User_Input, Index); //Call Body_Generator function definition.

    Index << HTML_Bot;  //Print into Index.html to stop <html></html> & <body></body> initialization.
    Index.close(); //stop streaming 'Index.html' file.

    std::cout << "End of HTML code generation." << std::endl; //User is notified that the program has finished executing.

    std::cout << "Would you like to open the generated HTML file?" << std::endl; //Ask user if they want to open the generated HTML file.
    std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0; " << std::endl;

    ReadUser_Input(User_Input, 1);
    if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){ //If yes then open Index.html
        ShellExecute(nullptr, "open", "Index.html", nullptr, nullptr, SW_SHOWNORMAL);
    }

    return 0; //Stop execution.
}

//Function definitions:

void Body_Generator(char& User_Input, std::ofstream& Index){ //Here we will call all other functions from different source files (headers) and print all the HTML <body></body> code into Index.html.

    Index << "<body>\n"; //Open body tag in Index.html

    std::cout << "Body Generator Started!" << std::endl;
    std::cout << "Do you want to use a navigation bar?" << std::endl;
    std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0; " << std::endl;

    ReadUser_Input(User_Input, 1); //Prompt user for input.
    if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){ //If user's input is true then we will generate a navigation bar.
        NavigationBar_Generator(User_Input, Index); //Call this function from "NavigationBar_Generator.h" module.
    }

    std::cout << "A title page with the most important information is automatically generated. You must configure this content now." << std::endl;

    Title_Page_Generator(User_Input, Index); //Call this function from "Title_Page_Generator.h" module.

    Module_Generator(User_Input, Index); //Call this function from "Module_Generator.h" module.

    Index << "\n\n    <div class=\"text-center\">\n"
             "        <p><h2>Made by Sebastian Termen student at Vilniaus kolegija/Universtiy of Applied Sciences</h2></p>\n"
             "    </div>\n\n";

    //Return to int main();

}