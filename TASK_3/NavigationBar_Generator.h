#ifndef STRUCTURED_PROGRAMMING_TASKS_DURENGO_NAVIGATIONBAR_GENERATOR_H
#define STRUCTURED_PROGRAMMING_TASKS_DURENGO_NAVIGATIONBAR_GENERATOR_H

void Button_Name_Checker(std::string& ButtonName); //This function is created to reduce recursion. Function prototype for function NavigationBar_Generator to call.

void NavigationBar_Generator(char& User_Input, std::ofstream& Index){ //If this function is called it generates an HTML navigation bar. User can choose different options (colors, button names, button type, etc...).

    std::cout << "Navigation Bar Generator engaged!" << std::endl;
    std::cout << "What color do you want the navbar to be?\n"
                 "(1) Dark (2) Blue (3) Green (4) Red: ";

    ReadUser_Input(User_Input, 3); //Prompt user to choose a color for the navigation bar and generate code with chosen color into Index.html.
    if(User_Input == '1'){
        Index << "\n\n\n<nav class=\"navbar navbar-expand-lg navbar-dark bg-dark bg-gradient\">\n";
        std::cout << "\nDark navigation bar chosen!" << std::endl;
    }
    if(User_Input == '2'){
        Index << "\n\n\n<nav class=\"navbar navbar-expand-lg navbar-dark bg-info bg-gradient\">\n";
        std::cout << "\nBlue navigation bar chosen!" << std::endl;
    }
    if(User_Input == '3'){
        Index << "\n\n\n<nav class=\"navbar navbar-expand-lg navbar-dark bg-success bg-gradient\">\n";
        std::cout << "\nGreen navigation bar chosen!" << std::endl;
    }
    if(User_Input == '4'){
        Index << "\n\n\n<nav class=\"navbar navbar-expand-lg navbar-dark bg-danger bg-gradient\">\n";
        std::cout << "\nRed navigation bar chosen!" << std::endl;
    }

    //Since the navigation bar has been selected we generate at least one button.
    Index << "    <div class=\"container-fluid\">\n"
             "\n"
             "        <a class=\"navbar-brand\" href=\"#\">\n"
             "            <img src=\"https://pbs.twimg.com/profile_images/819237681/twitter_400x400.gif\" width=\"90\" height=\"90\" alt=\"\">\n"
             "        </a>\n"
             "\n"
             "        <button class=\"navbar-toggler col-sm-12 col-md-12\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#navmenu\" aria-controls=\"navbarSupportedContent\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">\n"
             "            <span class=\"navbar-toggler-icon\"></span>\n"
             "        </button>\n"
             "\n"
             "        <div id=\"navmenu\" class=\"collapse navbar-collapse\">\n"
             "            <ul class=\"navbar-nav me-auto mb-2 mb-lg-1\">\n"
             "                <li class=\"nav-item\">\n"
             "                    <a class=\"nav-link active fs-2\" aria-current=\"page\" href=\"#\">Home</a>\n"
             "                </li>";

    int t = 1; //t = the amount of buttons we have. We initialize t to 1 because we have already generated a "home" button in the above fstream operand. I have set the limit of buttons to 6, because if there are more than 6 buttons the generated site does not look good on small scale devices and below.
    int DropDownAmount = 0; //DropDownAmount = the amount of dropdown buttons we have. The limit is 1.
    std::string ButtonName; //Initialize a string ButtonName so that the user can enter the name of a button.

    std::cout << "The navigation bar has 1 button which is already included - the home button." << std::endl; //Inform the user about the generated "home" button.

    while(t < 6){ //Once t = 6 we stop the loop and do not generate any more buttons.

        std::cout << "The maximum amount of buttons is 6." << std::endl; //Inform the user about button amount limit.
        std::cout << "Currently using " << t << "/6 buttons" << std::endl; //Show the user how many buttons have currently been generated.

        std::cout << "Would you like to add a navigation button?" << std::endl;
        std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0 to exit this prompt; " << std::endl;

        ReadUser_Input(User_Input, 1); //Prompt user for input.
        if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){

            if(DropDownAmount == 0){ //If a dropdown button has already been generated we do not prompt the user to generate a dropdown button.

                std::cout << "Would you like to make this button a dropdown button?" << std::endl;
                std::cout << "You can only have ONE dropdown button." << std::endl;
                std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0;" << std::endl;

                ReadUser_Input(User_Input, 1); //Prompt user for input.
                if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){ //If yes, generate dropdown button.

                    Button_Name_Checker(ButtonName); //Call function Button_Name_Checker and prompt the user to input a button name.

                    //Start generating dropdown button with a custom name into Index.html.
                    Index << " <li class=\"nav-item dropdown\">\n"
                             "                    <a class=\"nav-link dropdown-toggle fs-2\" href=\"#\" id=\"navbarDropdown\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">\n"
                             "                        "
                             <<
                             ButtonName
                             <<
                             "\n"
                             "                    </a>\n"
                             "                    <ul class=\"dropdown-menu\" aria-labelledby=\"navbarDropdown\">\n"
                             "                        <li><a class=\"dropdown-item\" href=\"#\">Action</a></li>\n"
                             "                        <li><a class=\"dropdown-item\" href=\"#\">Another action</a></li>\n"
                             "                        <li><hr class=\"dropdown-divider\"></li>\n"
                             "                        <li><a class=\"dropdown-item\" href=\"#\">Something else here</a></li>\n"
                             "                    </ul>\n"
                             "                </li>\n";
                    //Stop generating a dropdown button.

                    t++; //Add to the total amount of buttons.
                    DropDownAmount = 1; //Set the amount of dropdown buttons to 1 so that this function does not repeat.
                }
                else{ //If user skips the above step then generate a regular button.

                    Button_Name_Checker(ButtonName); //Call function Button_Name_Checker and prompt the user to input a button name.

                    //Start generating a regular button with a custom name into Index.html.
                    Index << "                <li class=\"nav-item\">\n"
                             "                    <a class=\"nav-link fs-2\" href=\"#\">"
                    <<
                    ButtonName
                    <<
                          "</a>\n"
                          "                </li>\n";
                    //Stop generating a regular button.

                    t++; //Add to the total amount of buttons.
                }
            }
            else{ //If user has already generated a dropdown button then generate a regular button.

                Button_Name_Checker(ButtonName); //Call function Button_Name_Checker and prompt the user to input a button name.

                //Start generating a regular button with a custom name into Index.html.
                Index << "                <li class=\"nav-item\">\n"
                         "                    <a class=\"nav-link fs-2\" href=\"#\">"
                <<
                ButtonName
                <<
                      "</a>\n"
                      "                </li>\n";

                t++; //Add to the total amount of buttons.
            }
        }
        else{ //If user input = no then we break from this loop and continue.
            break;
        }
    }
    if(t == 1){ //If t is not to 1 that means that new buttons were not generated and this code runs to properly close down the html syntax, regardless if the user has not generated any new buttons.
        Index << "                </ul>\n"
                 "                <form class=\"d-flex\">\n"
                 "                    <input class=\"form-control me-2\" type=\"search\" placeholder=\"Search\" aria-label=\"Search\">\n"
                 "                    <button class=\"btn btn-outline-success\" type=\"submit\">Search</button>\n"
                 "                </form>\n"
                 "            </div>\n"
                 "        </div>\n"
                 "    </nav>\n";
    }
    if(t != 1){ //If t is not equal to 1 that means that new buttons were generated and this code runs to properly close down the html syntax, regardless if the user has generated any new buttons.
        Index << "            </ul>\n"
                 "                <form class=\"d-flex\">\n"
                 "                    <input class=\"form-control me-2\" type=\"search\" placeholder=\"Search\" aria-label=\"Search\">\n"
                 "                    <button class=\"btn btn-outline-success\" type=\"submit\">Search</button>\n"
                 "                </form>\n"
                 "            </div>\n"
                 "        </div>\n"
                 "    </nav>\n";
    }

    std::cout << "Navigation Bar Generation Completed!" << std::endl; //Inform the user that the navigation bar generation is completed.

    //Return to Body_Generator function.
}

void Button_Name_Checker(std::string& ButtonName){ //When called this function prompts the user to enter a name for any button.

    std::cout << "Minimum name length is 1 symbol and maximum is no more than 10 " << std::endl; //User is informed of the maximum length a button can have.

    ButtonName = ""; //Reset the last entered value so that the loop can run.
    while(ButtonName.size() < 1 || ButtonName.size() >= 11){ //Maximum name length has been set so that the generated text doesn't go out of bounds and make the website not look good.
        std::cout << "Enter a name for your button: ";
        std::cin >> ButtonName;
        std::cout << std::endl;
    }
}
#endif //STRUCTURED_PROGRAMMING_TASKS_DURENGO_NAVIGATIONBAR_GENERATOR_H
