#ifndef STRUCTURED_PROGRAMMING_TASKS_DURENGO_TITLE_PAGE_GENERATOR_H
#define STRUCTURED_PROGRAMMING_TASKS_DURENGO_TITLE_PAGE_GENERATOR_H
#include "ReadUser_Input.h"
void Title_Page_Generator(char& User_Input, std::ofstream& Index){ //If this function is called it generates some basic information about the generated website and prints it into Index.html.

    std::string name; //Declare a string name to output user's input into Index.html

    std::cout << "Title Page Generator engaged!" << std::endl; //Informs user what is happening.

    Index << "\n\n\n" <<
          "    <section class=\"p-1\">\n"
          "        <div class=\"container\">\n"
          "            <div>\n"
          "\n"
          "                <div class=\"row-2 text-center\">\n"
          "                    <div><h1>Welcome to <span class=\"text-";

    std::cout << "Select an accent color for the name of your website:" << std::endl;
    std::cout << "(1) Dark (2) Blue (3) Green (4) Red: ";

    ReadUser_Input(User_Input, 3); //Prompt user for input.
    if(User_Input == '1'){
        Index << "dark";
        std::cout << "\nDark color chosen!" << std::endl;
    }
    if(User_Input == '2'){
        Index << "primary";
        std::cout << "\nBlue color chosen!" << std::endl;
    }
    if(User_Input == '3'){
        Index << "success";
        std::cout << "\nGreen color chosen!" << std::endl;
    }
    if(User_Input == '4'){
        Index << "danger";
        std::cout << "\nRed color chosen!" << std::endl;
    }

    std::cout << "\nWhat is the name of your website?" << std::endl;
    std::cin >> name; //Prompt user to enter the desired name for the website.

    Index << " text-capitalize\">" << name <<
          "</span></h1></div>\n"
          "                </div>\n\n";

    std::cout << "Would you like to insert an image for the title page?" << std::endl;
    std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0; " << std::endl;

    ReadUser_Input(User_Input, 1); //Prompt user for input.
    if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){ //If yes then user gets more options.

        std::cout << "Would you like to insert your own link link or use the default one?" << std::endl;
        std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0 for default link;" << std::endl;

        ReadUser_Input(User_Input, 1); //Prompt user for input.
        if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){ //If yes user will enter their own link.

            std::cout << "Example: http://www.mandysam.com/img/random.jpg" << std::endl;
            std::cout << "Please enter a link:" << std::endl;
            std::cin >> name; //Prompt user to enter link.

            Index << "                <div class=\"container col-lg-4 col-sm-7 justify-content-center\">\n"
                     "                    <div class=\"row-2\">\n"
                     "                        <img class=\"img-fluid\" src=\""
                  <<
                  name
                  <<
                  "\" alt=\"\">\n"
                  "                    </div>\n"
                  "                </div>\n\n";
        }
        else{ //If no, the default link will be used.
            Index << "                <div class=\"container col-lg-4 col-sm-7 justify-content-center\">\n"
                     "                    <div class=\"row-2\">\n"
                     "                        <img class=\"img-fluid\" src=\"http://www.mandysam.com/img/random.jpg\" alt=\"\">\n"
                     "                    </div>\n"
                     "                </div>\n\n";
        }
    }

    Index << "                <div class=\"row-3 py-4 text-center\">\n"
             "                    <svg xmlns=\"http://www.w3.org/2000/svg\" width=\"16\" height=\"16\" fill=\"currentColor\" class=\"bi bi-circle-fill\" viewBox=\"0 0 16 16\">\n"
             "                        <circle cx=\"8\" cy=\"8\" r=\"8\"/>\n"
             "                    </svg>\n"
             "                </div>\n\n";

    std::cout << "Would you like to add a description for your website?" << std::endl;
    std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0; " << std::endl;

    ReadUser_Input(User_Input, 1); //Prompt user for input.
    if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){ //If yes user can input their descriptions.

        std::cout << "Please write your description (can't be left empty):" << std::endl;
        std::cin >> name; //Prompt user to enter description.

        Index << "                <div class=\"container col-md-8\">\n"
                 "                    <div class=\"text-wrap text-center fs-4\">\n"
              <<
              name
              <<
              "\n                    </div>\n"
              "                </div>";

        std::cout << "Description added!" << std::endl;
    }

    std::cout << "Adding button layer!" << std::endl;
    Index << "                <div class=\"row-4 py-4 text-center\">\n\n";

    std::cout << "Would you like to add VIKO button?" << std::endl;
    std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0; " << std::endl;

    ReadUser_Input(User_Input, 1); //Prompt user for input.
    if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){
        Index << "\n"
                 "                    <button type=\"button\" class=\"btn btn-success btn-lg\" data-bs-toggle=\"modal\" data-bs-target=\"#VikoModal\">VIKO</button>\n"
                 "\n"
                 "                    <!-- VIKO Website Modal -->\n"
                 "                    <div  id=\"VikoModal\" class=\"modal fade\" tabindex=\"-1\" aria-labelledby=\"VikoModalLabel\" aria-hidden=\"true\">\n"
                 "                        <div class=\"modal-dialog modal-xl\">\n"
                 "                            <div class=\"modal-content\">\n"
                 "                                <div class=\"modal-header\">\n"
                 "                                    <h5 class=\"modal-title\" id=\"VikoModalLabel\">VIKO website</h5>\n"
                 "                                    <button type=\"button\" class=\"btn-close\" data-bs-dismiss=\"modal\" aria-label=\"Close\"></button>\n"
                 "                                </div>\n"
                 "                                <div class=\"modal-body\">\n"
                 "                                    <iframe class=\"ratio ratio-16x9\" height=\"600\" src=\"https://viko.lt\"></iframe>\n"
                 "                                </div>\n"
                 "                                <div class=\"modal-footer\">\n"
                 "                                    <button type=\"button\" class=\"btn btn-secondary\" data-bs-dismiss=\"modal\">Close</button>\n"
                 "                                </div>\n"
                 "                            </div>\n"
                 "                        </div>\n"
                 "                    </div>\n\n";

        std::cout << "VIKO Button added!" << std::endl;
    }

    std::cout << "Would you like to add a youtube (redirect) button?" << std::endl;
    std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0; " << std::endl;

    ReadUser_Input(User_Input, 1); //Prompt user for input.
    if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){ //If yes then user gets more options.

        std::cout << "Would you like to add a custom url or use default?" << std::endl;
        std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0 for default; " << std::endl;

        ReadUser_Input(User_Input, 1); //Prompt user for input.
        if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){ //If yes user enters a link.
            Index << "                    <a href=\"";
            std::cout << "Example: https://youtu.be/dQw4w9WgXcQ" << std::endl;
            std::cout << "Please enter a link: " << std::endl;
            std::cin >> name;
            Index << name <<
                  R"(" class="link-light"><button type="button" class="btn btn-danger btn-lg">Youtube</button></a>)";
        }
        else{ //If no then generate default link.
            Index << "                    <a href=\"https://youtu.be/dQw4w9WgXcQ\" class=\"link-light\"><button type=\"button\" class=\"btn btn-danger btn-lg\">Youtube</button></a>\n\n";
        }
    }

    std::cout << "Would you like to add a custom url button (redirect)?" << std::endl;
    std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0; " << std::endl;

    ReadUser_Input(User_Input, 1); //Prompt user for input.
    if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){

        std::cout << "Would you like to add a custom url or use default?" << std::endl;
        std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0; " << std::endl;

        ReadUser_Input(User_Input, 1); //Prompt user for input.
        if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){ //If yes user gets more options.
            Index << "                    <a href=\"";
            std::cout << "Example: https://frame.work/" << std::endl;
            std::cout << "Please enter a link: " << std::endl;
            std::cin >> name;
            Index << name <<
                  R"(" class="link-light"><button type="button" class="btn btn-secondary btn-lg">Custom URL</button></a>)";
        }
        else{ //If no generate default link.
            Index << R"(                    <a href="https://frame.work/" class="link-light"><button type="button" class="btn btn-secondary btn-lg">Custom URL</button></a>)";
        }
    }
    Index << "\n\n                </div>\n\n";

    std::cout << "Would you like to add \"Fill out a form\" button?" << std::endl;
    std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0; " << std::endl;

    ReadUser_Input(User_Input, 1); //Prompt user for input.
    if(User_Input == 'Y' || User_Input == 'y' || User_Input == '1'){
        std::cout << "Generating \"Fill out a form\" button!" << std::endl;
        Index << "                <div class=\"row-5 text-center\">\n"
                 "                    <button type=\"button\" class=\"btn btn-info btn-lg\" id=\"FormPopUpButton\">Fill out a form!</button>\n"
                 "                </div>\n"
                 "        <div id=\"FormPopUp\"></div>\n";
        Index << "\n\n<script>\n"
                 "        var alertPlaceholder = document.getElementById('FormPopUp')\n"
                 "        var alertTrigger = document.getElementById('FormPopUpButton')\n"
                 "\n"
                 "        function alert(message, type) {\n"
                 "            var wrapper = document.createElement('div')\n"
                 "            wrapper.innerHTML = '<div class=\"alert alert-' + type + ' alert-dismissible\" role=\"alert\">' + message + '<button type=\"button\" class=\"btn-close\" data-bs-dismiss=\"alert\" aria-label=\"Close\"></button></div>'\n"
                 "\n"
                 "            alertPlaceholder.append(wrapper)\n"
                 "        }\n"
                 "\n"
                 "        if (alertTrigger) {\n"
                 "            alertTrigger.addEventListener('click', function () {\n"
                 "                alert('<form>\\n' +\n"
                 "                    '  <div class=\"form-group\">\\n' +\n"
                 "                    '    <label for=\"InputName\">Name</label>\\n' +\n"
                 "                    '    <input type=\"name\" class=\"form-control\" id=\"InputName\" aria-describedby=\"nameHelp\">\\n' +\n"
                 "                    '    <small id=\"nameHelp\" class=\"form-text text-muted\">Please write down your full name.</small>\\n' +\n"
                 "                    '  </div>\\n' +\n"
                 "                    '  <div class=\"form-group\">\\n' +\n"
                 "                    '    <label for=\"InputAge\">Age</label>\\n' +\n"
                 "                    '    <input type=\"age\" class=\"form-control\" id=\"InputAge\">\\n' +\n"
                 "                    '  </div>\\n' +\n"
                 "                    '  <div class=\"form-group form-check\">\\n' +\n"
                 "                    '    <input type=\"checkbox\" class=\"form-check-input\" id=\"Check1\">\\n' +\n"
                 "                    '    <label class=\"form-check-label\" for=\"Check1\">Do not save my age information</label>\\n' +\n"
                 "                    '  </div>\\n' +\n"
                 "                    '  <button type=\"submit\" class=\"btn btn-primary\">Submit</button>\\n' +\n"
                 "                    '</form>', 'success')\n"
                 "            })\n"
                 "        }\n"
                 "    </script>\n\n";
    }

    Index << "                 \n\n</div>"
             "                 \n\n</div>"
             "             \n\n</section>";

    std::cout << "Title Page Generator is complete!" << std::endl; //Inform user of completed operations.

    //Return to Body_Generator function.

}
#endif //STRUCTURED_PROGRAMMING_TASKS_DURENGO_TITLE_PAGE_GENERATOR_H
