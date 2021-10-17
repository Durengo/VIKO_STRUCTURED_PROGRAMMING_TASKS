#ifndef STRUCTURED_PROGRAMMING_TASKS_DURENGO_MODULE_GENERATOR_H
#define STRUCTURED_PROGRAMMING_TASKS_DURENGO_MODULE_GENERATOR_H

#include "ReadUser_Input.h"

void Module_Generator(char& User_Input, std::ofstream& Index) { //If this function is called it gives the user to generate some modules(tables, slides, etc...) and prints it into Index.html.

    std::cout << "Modules - you can choose from four modules." << std::endl;
    std::cout << "Modules: (1) Educational text module; (2) Slide show module; (3) Table module; (4) Educational text module and slide show module." << std::endl;

    while (true) {

        Index << "\n\n    <section class=\"py-5\">\n";

        std::cout << "Do you want to generate a module or exit?" << std::endl;
        std::cout << "Answer with: (Y)es /or/ 1; (N)o /or/ 0; " << std::endl;

        ReadUser_Input(User_Input, 1); //Prompt user for input.
        if (User_Input == 'Y' || User_Input == 'y' || User_Input == '1') { //If yes continue.

            std::cout << "Available Modules: (1) Educational text module; (2) Slide show module; (3) Table module; (4) Educational text module and slide show module." << std::endl;
            std::cout << "Which module do you want to generate?" << std::endl;
            std::cout << "Answer with: (1), (2), (3), (4)" << std::endl;

            ReadUser_Input(User_Input, 3); //Prompt user for input.
            if (User_Input == '1') { //If user selects "(1) Educational text module" continue from here.

                std::cout << "Educational text module selected!" << std::endl;
                std::cout << "What placement do you wish to select?" << std::endl;
                std::cout << "Answer with: (L)eft, (C)enter, (R)ight" << std::endl;

                ReadUser_Input(User_Input, 4); //Prompt user for input.
                if (User_Input == 'L' || User_Input == 'l') { //If user selects "Left" generate Educational Text module on the left.

                    Index << "\n<div class=\"d-flex justify-content-start\">\n"
                             "        <div class=\"accordion fs-4\" id=\"EductionAccordion\">\n"
                             "            <div class=\"accordion-item\">\n"
                             "                <h2 class=\"accordion-header\" id=\"headingOne\">\n"
                             "                    <button class=\"accordion-button\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseOne\" aria-expanded=\"true\" aria-controls=\"collapseOne\">\n"
                             "                        <strong>What is education?</strong>\n"
                             "                    </button>\n"
                             "                </h2>\n"
                             "                <div id=\"collapseOne\" class=\"accordion-collapse collapse show\" aria-labelledby=\"headingOne\" data-bs-parent=\"#EductionAccordion\">\n"
                             "                    <div class=\"accordion-body\">\n"
                             "                        <strong>Education</strong> is the process of facilitating learning, or the acquisition of knowledge, skills, values, morals, beliefs, and habits.\n"
                             "                    </div>\n"
                             "                </div>\n"
                             "            </div>\n"
                             "            <div class=\"accordion-item\">\n"
                             "                <h2 class=\"accordion-header\" id=\"headingTwo\">\n"
                             "                    <button class=\"accordion-button collapsed\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseTwo\" aria-expanded=\"false\" aria-controls=\"collapseTwo\">\n"
                             "                        <strong>What kind of educational methods are there?</strong>\n"
                             "                    </button>\n"
                             "                </h2>\n"
                             "                <div id=\"collapseTwo\" class=\"accordion-collapse collapse\" aria-labelledby=\"headingTwo\" data-bs-parent=\"#EductionAccordion\">\n"
                             "                    <div class=\"accordion-body\">\n"
                             "                        <strong>Educational methods</strong> include teaching, training, storytelling, discussion and directed research.\n"
                             "                    </div>\n"
                             "                </div>\n"
                             "            </div>\n"
                             "            <div class=\"accordion-item\">\n"
                             "                <h2 class=\"accordion-header\" id=\"headingThree\">\n"
                             "                    <button class=\"accordion-button collapsed\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseThree\" aria-expanded=\"false\" aria-controls=\"collapseThree\">\n"
                             "                        <strong>More info</strong>\n"
                             "                    </button>\n"
                             "                </h2>\n"
                             "                <div id=\"collapseThree\" class=\"accordion-collapse collapse\" aria-labelledby=\"headingThree\" data-bs-parent=\"#EductionAccordion\">\n"
                             "                    <div class=\"accordion-body\">\n"
                             "                        <strong>Education</strong> frequently takes place under the guidance of educators; however, learners can also educate themselves. Education can take place in formal or informal settings, and any experience that has a formative effect on the way one thinks, feels, or acts may be considered educational. The methodology of teaching is called pedagogy. Formal education is commonly divided formally into stages such as preschool or kindergarten, primary school, secondary school and then college, university, or apprenticeship. In most regions, education is compulsory up to a certain age. There are movements for education reforms, such as for improving quality and efficiency of education towards relevance in students' lives and efficient problem solving in modern or future society at large, or for evidence-based education methodologies.\n"
                             "                    </div>\n"
                             "                </div>\n"
                             "            </div>\n"
                             "        </div>\n"
                             "    </div>\n";
                    Index << "\n\n </section>\n";

                }
                if (User_Input == 'C' || User_Input == 'c') { //If user selects "Center" generate Educational Text module in the center.

                    Index << "\n<div class=\"d-flex justify-content-center\">\n"
                             "        <div class=\"accordion fs-4\" id=\"EductionAccordion\">\n"
                             "            <div class=\"accordion-item\">\n"
                             "                <h2 class=\"accordion-header\" id=\"headingOne\">\n"
                             "                    <button class=\"accordion-button\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseOne\" aria-expanded=\"true\" aria-controls=\"collapseOne\">\n"
                             "                        <strong>What is education?</strong>\n"
                             "                    </button>\n"
                             "                </h2>\n"
                             "                <div id=\"collapseOne\" class=\"accordion-collapse collapse show\" aria-labelledby=\"headingOne\" data-bs-parent=\"#EductionAccordion\">\n"
                             "                    <div class=\"accordion-body\">\n"
                             "                        <strong>Education</strong> is the process of facilitating learning, or the acquisition of knowledge, skills, values, morals, beliefs, and habits.\n"
                             "                    </div>\n"
                             "                </div>\n"
                             "            </div>\n"
                             "            <div class=\"accordion-item\">\n"
                             "                <h2 class=\"accordion-header\" id=\"headingTwo\">\n"
                             "                    <button class=\"accordion-button collapsed\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseTwo\" aria-expanded=\"false\" aria-controls=\"collapseTwo\">\n"
                             "                        <strong>What kind of educational methods are there?</strong>\n"
                             "                    </button>\n"
                             "                </h2>\n"
                             "                <div id=\"collapseTwo\" class=\"accordion-collapse collapse\" aria-labelledby=\"headingTwo\" data-bs-parent=\"#EductionAccordion\">\n"
                             "                    <div class=\"accordion-body\">\n"
                             "                        <strong>Educational methods</strong> include teaching, training, storytelling, discussion and directed research.\n"
                             "                    </div>\n"
                             "                </div>\n"
                             "            </div>\n"
                             "            <div class=\"accordion-item\">\n"
                             "                <h2 class=\"accordion-header\" id=\"headingThree\">\n"
                             "                    <button class=\"accordion-button collapsed\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseThree\" aria-expanded=\"false\" aria-controls=\"collapseThree\">\n"
                             "                        <strong>More info</strong>\n"
                             "                    </button>\n"
                             "                </h2>\n"
                             "                <div id=\"collapseThree\" class=\"accordion-collapse collapse\" aria-labelledby=\"headingThree\" data-bs-parent=\"#EductionAccordion\">\n"
                             "                    <div class=\"accordion-body\">\n"
                             "                        <strong>Education</strong> frequently takes place under the guidance of educators; however, learners can also educate themselves. Education can take place in formal or informal settings, and any experience that has a formative effect on the way one thinks, feels, or acts may be considered educational. The methodology of teaching is called pedagogy. Formal education is commonly divided formally into stages such as preschool or kindergarten, primary school, secondary school and then college, university, or apprenticeship. In most regions, education is compulsory up to a certain age. There are movements for education reforms, such as for improving quality and efficiency of education towards relevance in students' lives and efficient problem solving in modern or future society at large, or for evidence-based education methodologies.\n"
                             "                    </div>\n"
                             "                </div>\n"
                             "            </div>\n"
                             "        </div>\n"
                             "    </div>\n";
                    Index << "\n\n </section>\n";

                }
                if (User_Input == 'R' || User_Input == 'r') { //If user selects "Right" generate Educational Text module on the right.

                    Index << "\n<div class=\"d-flex justify-content-end\">\n"
                             "        <div class=\"accordion fs-4\" id=\"EductionAccordion\">\n"
                             "            <div class=\"accordion-item\">\n"
                             "                <h2 class=\"accordion-header\" id=\"headingOne\">\n"
                             "                    <button class=\"accordion-button\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseOne\" aria-expanded=\"true\" aria-controls=\"collapseOne\">\n"
                             "                        <strong>What is education?</strong>\n"
                             "                    </button>\n"
                             "                </h2>\n"
                             "                <div id=\"collapseOne\" class=\"accordion-collapse collapse show\" aria-labelledby=\"headingOne\" data-bs-parent=\"#EductionAccordion\">\n"
                             "                    <div class=\"accordion-body\">\n"
                             "                        <strong>Education</strong> is the process of facilitating learning, or the acquisition of knowledge, skills, values, morals, beliefs, and habits.\n"
                             "                    </div>\n"
                             "                </div>\n"
                             "            </div>\n"
                             "            <div class=\"accordion-item\">\n"
                             "                <h2 class=\"accordion-header\" id=\"headingTwo\">\n"
                             "                    <button class=\"accordion-button collapsed\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseTwo\" aria-expanded=\"false\" aria-controls=\"collapseTwo\">\n"
                             "                        <strong>What kind of educational methods are there?</strong>\n"
                             "                    </button>\n"
                             "                </h2>\n"
                             "                <div id=\"collapseTwo\" class=\"accordion-collapse collapse\" aria-labelledby=\"headingTwo\" data-bs-parent=\"#EductionAccordion\">\n"
                             "                    <div class=\"accordion-body\">\n"
                             "                        <strong>Educational methods</strong> include teaching, training, storytelling, discussion and directed research.\n"
                             "                    </div>\n"
                             "                </div>\n"
                             "            </div>\n"
                             "            <div class=\"accordion-item\">\n"
                             "                <h2 class=\"accordion-header\" id=\"headingThree\">\n"
                             "                    <button class=\"accordion-button collapsed\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseThree\" aria-expanded=\"false\" aria-controls=\"collapseThree\">\n"
                             "                        <strong>More info</strong>\n"
                             "                    </button>\n"
                             "                </h2>\n"
                             "                <div id=\"collapseThree\" class=\"accordion-collapse collapse\" aria-labelledby=\"headingThree\" data-bs-parent=\"#EductionAccordion\">\n"
                             "                    <div class=\"accordion-body\">\n"
                             "                        <strong>Education</strong> frequently takes place under the guidance of educators; however, learners can also educate themselves. Education can take place in formal or informal settings, and any experience that has a formative effect on the way one thinks, feels, or acts may be considered educational. The methodology of teaching is called pedagogy. Formal education is commonly divided formally into stages such as preschool or kindergarten, primary school, secondary school and then college, university, or apprenticeship. In most regions, education is compulsory up to a certain age. There are movements for education reforms, such as for improving quality and efficiency of education towards relevance in students' lives and efficient problem solving in modern or future society at large, or for evidence-based education methodologies.\n"
                             "                    </div>\n"
                             "                </div>\n"
                             "            </div>\n"
                             "        </div>\n"
                             "    </div>\n";
                    Index << "\n\n </section>\n";

                }

                std::cout << "Educational text module Generated!" << std::endl; //Inform user that the module has been generated.
            }
            if (User_Input == '2') { //If user selects "(2) Slide show module" continue from here.

                Index << "\n        <div class=\"col d-none d-xl-block\">\n"
                         "            <div id=\"carouselExampleSlidesOnly\" class=\"carousel slide carousel-fade\" data-bs-ride=\"carousel\">\n"
                         "                <div class=\"carousel-inner d-flex justify-content-start\">\n"
                         "                    <div class=\"carousel-item active\">\n"
                         "                        <img src=\"http://analyticsindiamag.com/wp-content/uploads/2017/09/college-1.jpg\" class=\"ratio ratio-16x9 d-block w-100\" alt=\"...\">\n"
                         "                    </div>\n"
                         "                    <div class=\"carousel-item\">\n"
                         "                        <img src=\"https://www.migration.lt/media/cache/d/6/b/9/5/d6b9525a9c53aa41843c888607678f0f61404609.jpeg\" class=\"ratio ratio-16x9 d-block w-100\" alt=\"...\">\n"
                         "                    </div>\n"
                         "                    <div class=\"carousel-item\">\n"
                         "                        <img src=\"https://makeinbusiness.com/wp-content/uploads/2019/11/Improve-Education-Experiences.jpg\" class=\"ratio ratio-16x9 d-block w-100\" alt=\"...\">\n"
                         "                    </div>\n"
                         "                </div>\n"
                         "            </div>\n"
                         "        </div>\n";
                Index << "\n\n </section>\n";

                std::cout << "Slide show module generated!" << std::endl; //Inform user that the module has been generated.
            }
            if (User_Input == '3') { //If user selects "(3) Table module" continue from here.

                std::cout << "Table module selected!" << std::endl;
                std::cout << "What placement do you wish to select?" << std::endl;
                std::cout << "Answer with: (L)eft, (C)enter, (R)ight" << std::endl;

                ReadUser_Input(User_Input, 4); //Prompt user for input.
                if (User_Input == 'L' || User_Input == 'l') { //If user selects "Left" Table module on the left.

                    Index << "\n\n<div class=\"d-flex justify-content-start text-center\">\n"
                             "        <div class=\"row p-4\">\n"
                             "        <h2>Something Something Table</h2>\n"
                             "            <table class=\"table\">\n"
                             "                <thead>\n"
                             "                <tr>\n"
                             "                    <th scope=\"col\">#</th>\n"
                             "                    <th scope=\"col\">One</th>\n"
                             "                    <th scope=\"col\">Two</th>\n"
                             "                    <th scope=\"col\">Three</th>\n"
                             "                    <th scope=\"col\">Four</th>\n"
                             "                </tr>\n"
                             "                </thead>\n"
                             "                <tbody>\n"
                             "                <tr>\n"
                             "                    <th scope=\"row\">1</th>\n"
                             "                    <td>A<span class=\"align-baseline fs-6\">11</span></td>\n"
                             "                    <td>A<span class=\"align-baseline fs-6\">12</span></td>\n"
                             "                    <td>A<span class=\"align-baseline fs-6\">13</span></td>\n"
                             "                    <td>A<span class=\"align-baseline fs-6\">14</span></td>\n"
                             "                </tr>\n"
                             "                <tr>\n"
                             "                    <th scope=\"row\">2</th>\n"
                             "                    <td>B<span class=\"align-baseline fs-6\">21</span></td>\n"
                             "                    <td>B<span class=\"align-baseline fs-6\">22</span></td>\n"
                             "                    <td>B<span class=\"align-baseline fs-6\">23</span></td>\n"
                             "                    <td>B<span class=\"align-baseline fs-6\">24</span></td>\n"
                             "                </tr>\n"
                             "                <tr>\n"
                             "                    <th scope=\"row\">3</th>\n"
                             "                    <td>C<span class=\"align-baseline fs-6\">31</span></td>\n"
                             "                    <td>C<span class=\"align-baseline fs-6\">32</span></td>\n"
                             "                    <td>C<span class=\"align-baseline fs-6\">33</span></td>\n"
                             "                    <td>C<span class=\"align-baseline fs-6\">34</span></td>\n"
                             "                </tr>\n"
                             "                </tbody>\n"
                             "            </table>\n"
                             "\n"
                             "        <div class=\"px-5\">\n"
                             "            <p>\n"
                             "                <button class=\"btn btn-primary\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseExample\" aria-expanded=\"false\" aria-controls=\"collapseExample\">\n"
                             "                    Something about this table\n"
                             "                </button>\n"
                             "            </p>\n"
                             "            <div class=\"collapse\" id=\"collapseExample\">\n"
                             "                <div class=\"card card-body\">\n"
                             "                    Description about something...\n"
                             "                </div>\n"
                             "            </div>\n"
                             "        </div>\n"
                             "        </div>\n"
                             "    </div>\n\n";
                    Index << "\n\n </section>\n";

                }
                if (User_Input == 'C' || User_Input == 'c') { //If user selects "Center" Table module in the center.

                    Index << "\n\n<div class=\"d-flex justify-content-center text-center\">\n"
                             "        <div class=\"row p-4\">\n"
                             "        <h2>Something Something Table</h2>\n"
                             "            <table class=\"table\">\n"
                             "                <thead>\n"
                             "                <tr>\n"
                             "                    <th scope=\"col\">#</th>\n"
                             "                    <th scope=\"col\">One</th>\n"
                             "                    <th scope=\"col\">Two</th>\n"
                             "                    <th scope=\"col\">Three</th>\n"
                             "                    <th scope=\"col\">Four</th>\n"
                             "                </tr>\n"
                             "                </thead>\n"
                             "                <tbody>\n"
                             "                <tr>\n"
                             "                    <th scope=\"row\">1</th>\n"
                             "                    <td>A<span class=\"align-baseline fs-6\">11</span></td>\n"
                             "                    <td>A<span class=\"align-baseline fs-6\">12</span></td>\n"
                             "                    <td>A<span class=\"align-baseline fs-6\">13</span></td>\n"
                             "                    <td>A<span class=\"align-baseline fs-6\">14</span></td>\n"
                             "                </tr>\n"
                             "                <tr>\n"
                             "                    <th scope=\"row\">2</th>\n"
                             "                    <td>B<span class=\"align-baseline fs-6\">21</span></td>\n"
                             "                    <td>B<span class=\"align-baseline fs-6\">22</span></td>\n"
                             "                    <td>B<span class=\"align-baseline fs-6\">23</span></td>\n"
                             "                    <td>B<span class=\"align-baseline fs-6\">24</span></td>\n"
                             "                </tr>\n"
                             "                <tr>\n"
                             "                    <th scope=\"row\">3</th>\n"
                             "                    <td>C<span class=\"align-baseline fs-6\">31</span></td>\n"
                             "                    <td>C<span class=\"align-baseline fs-6\">32</span></td>\n"
                             "                    <td>C<span class=\"align-baseline fs-6\">33</span></td>\n"
                             "                    <td>C<span class=\"align-baseline fs-6\">34</span></td>\n"
                             "                </tr>\n"
                             "                </tbody>\n"
                             "            </table>\n"
                             "\n"
                             "        <div class=\"px-5\">\n"
                             "            <p>\n"
                             "                <button class=\"btn btn-primary\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseExample\" aria-expanded=\"false\" aria-controls=\"collapseExample\">\n"
                             "                    Something about this table\n"
                             "                </button>\n"
                             "            </p>\n"
                             "            <div class=\"collapse\" id=\"collapseExample\">\n"
                             "                <div class=\"card card-body\">\n"
                             "                    Description about something...\n"
                             "                </div>\n"
                             "            </div>\n"
                             "        </div>\n"
                             "        </div>\n"
                             "    </div>\n\n";
                    Index << "\n\n </section>\n";

                }
                if (User_Input == 'R' || User_Input == 'r') { //If user selects "Right" Table module on the right.

                    Index << "\n\n<div class=\"d-flex justify-content-end text-center\">\n"
                             "        <div class=\"row p-4\">\n"
                             "        <h2>Something Something Table</h2>\n"
                             "            <table class=\"table\">\n"
                             "                <thead>\n"
                             "                <tr>\n"
                             "                    <th scope=\"col\">#</th>\n"
                             "                    <th scope=\"col\">One</th>\n"
                             "                    <th scope=\"col\">Two</th>\n"
                             "                    <th scope=\"col\">Three</th>\n"
                             "                    <th scope=\"col\">Four</th>\n"
                             "                </tr>\n"
                             "                </thead>\n"
                             "                <tbody>\n"
                             "                <tr>\n"
                             "                    <th scope=\"row\">1</th>\n"
                             "                    <td>A<span class=\"align-baseline fs-6\">11</span></td>\n"
                             "                    <td>A<span class=\"align-baseline fs-6\">12</span></td>\n"
                             "                    <td>A<span class=\"align-baseline fs-6\">13</span></td>\n"
                             "                    <td>A<span class=\"align-baseline fs-6\">14</span></td>\n"
                             "                </tr>\n"
                             "                <tr>\n"
                             "                    <th scope=\"row\">2</th>\n"
                             "                    <td>B<span class=\"align-baseline fs-6\">21</span></td>\n"
                             "                    <td>B<span class=\"align-baseline fs-6\">22</span></td>\n"
                             "                    <td>B<span class=\"align-baseline fs-6\">23</span></td>\n"
                             "                    <td>B<span class=\"align-baseline fs-6\">24</span></td>\n"
                             "                </tr>\n"
                             "                <tr>\n"
                             "                    <th scope=\"row\">3</th>\n"
                             "                    <td>C<span class=\"align-baseline fs-6\">31</span></td>\n"
                             "                    <td>C<span class=\"align-baseline fs-6\">32</span></td>\n"
                             "                    <td>C<span class=\"align-baseline fs-6\">33</span></td>\n"
                             "                    <td>C<span class=\"align-baseline fs-6\">34</span></td>\n"
                             "                </tr>\n"
                             "                </tbody>\n"
                             "            </table>\n"
                             "\n"
                             "        <div class=\"px-5\">\n"
                             "            <p>\n"
                             "                <button class=\"btn btn-primary\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseExample\" aria-expanded=\"false\" aria-controls=\"collapseExample\">\n"
                             "                    Something about this table\n"
                             "                </button>\n"
                             "            </p>\n"
                             "            <div class=\"collapse\" id=\"collapseExample\">\n"
                             "                <div class=\"card card-body\">\n"
                             "                    Description about something...\n"
                             "                </div>\n"
                             "            </div>\n"
                             "        </div>\n"
                             "        </div>\n"
                             "    </div>\n\n";
                    Index << "\n\n </section>\n";

                }

                std::cout << "Table module generated!" << std::endl; //Inform user that the module has been generated.
            }
            if (User_Input == '4') { //If user selects "(4) Educational text module and slide show module" continue from here.

                Index << "\n\n    <div class=\"container\">\n"
                         "        <div class=\"row\">\n"
                         "            <div class=\"col\">\n"
                         "                <div class=\"accordion fs-4\" id=\"EductionAccordion\">\n"
                         "                    <div class=\"accordion-item\">\n"
                         "                        <h2 class=\"accordion-header\" id=\"headingOne\">\n"
                         "                            <button class=\"accordion-button\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseOne\" aria-expanded=\"true\" aria-controls=\"collapseOne\">\n"
                         "                                <strong>What is education?</strong>\n"
                         "                            </button>\n"
                         "                        </h2>\n"
                         "                        <div id=\"collapseOne\" class=\"accordion-collapse collapse show\" aria-labelledby=\"headingOne\" data-bs-parent=\"#EductionAccordion\">\n"
                         "                            <div class=\"accordion-body\">\n"
                         "                                <strong>Education</strong> is the process of facilitating learning, or the acquisition of knowledge, skills, values, morals, beliefs, and habits.\n"
                         "                            </div>\n"
                         "                        </div>\n"
                         "                    </div>\n"
                         "                    <div class=\"accordion-item\">\n"
                         "                        <h2 class=\"accordion-header\" id=\"headingTwo\">\n"
                         "                            <button class=\"accordion-button collapsed\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseTwo\" aria-expanded=\"false\" aria-controls=\"collapseTwo\">\n"
                         "                                <strong>What kind of educational methods are there?</strong>\n"
                         "                            </button>\n"
                         "                        </h2>\n"
                         "                        <div id=\"collapseTwo\" class=\"accordion-collapse collapse\" aria-labelledby=\"headingTwo\" data-bs-parent=\"#EductionAccordion\">\n"
                         "                            <div class=\"accordion-body\">\n"
                         "                                <strong>Educational methods</strong> include teaching, training, storytelling, discussion and directed research.\n"
                         "                            </div>\n"
                         "                        </div>\n"
                         "                    </div>\n"
                         "                    <div class=\"accordion-item\">\n"
                         "                        <h2 class=\"accordion-header\" id=\"headingThree\">\n"
                         "                            <button class=\"accordion-button collapsed\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#collapseThree\" aria-expanded=\"false\" aria-controls=\"collapseThree\">\n"
                         "                                <strong>More info</strong>\n"
                         "                            </button>\n"
                         "                        </h2>\n"
                         "                        <div id=\"collapseThree\" class=\"accordion-collapse collapse\" aria-labelledby=\"headingThree\" data-bs-parent=\"#EductionAccordion\">\n"
                         "                            <div class=\"accordion-body\">\n"
                         "                                <strong>Education</strong> frequently takes place under the guidance of educators; however, learners can also educate themselves. Education can take place in formal or informal settings, and any experience that has a formative effect on the way one thinks, feels, or acts may be considered educational. The methodology of teaching is called pedagogy. Formal education is commonly divided formally into stages such as preschool or kindergarten, primary school, secondary school and then college, university, or apprenticeship. In most regions, education is compulsory up to a certain age. There are movements for education reforms, such as for improving quality and efficiency of education towards relevance in students' lives and efficient problem solving in modern or future society at large, or for evidence-based education methodologies.\n"
                         "                            </div>\n"
                         "                        </div>\n"
                         "                    </div>\n"
                         "                </div>\n"
                         "            </div>\n"
                         "            <div class=\"col d-none d-xl-block\">\n"
                         "                <div id=\"carouselExampleSlidesOnly\" class=\"carousel slide carousel-fade\" data-bs-ride=\"carousel\">\n"
                         "                    <div class=\"carousel-inner d-flex justify-content-start\">\n"
                         "                        <div class=\"carousel-item active\">\n"
                         "                            <img src=\"http://analyticsindiamag.com/wp-content/uploads/2017/09/college-1.jpg\" class=\"ratio ratio-16x9 d-block w-100\" alt=\"...\">\n"
                         "                        </div>\n"
                         "                        <div class=\"carousel-item\">\n"
                         "                            <img src=\"https://www.migration.lt/media/cache/d/6/b/9/5/d6b9525a9c53aa41843c888607678f0f61404609.jpeg\" class=\"ratio ratio-16x9 d-block w-100\" alt=\"...\">\n"
                         "                        </div>\n"
                         "                        <div class=\"carousel-item\">\n"
                         "                            <img src=\"https://makeinbusiness.com/wp-content/uploads/2019/11/Improve-Education-Experiences.jpg\" class=\"ratio ratio-16x9 d-block w-100\" alt=\"...\">\n"
                         "                        </div>\n"
                         "                    </div>\n"
                         "                </div>\n"
                         "            </div>\n"
                         "        </div>\n"
                         "    </div>\n\n";
                Index << "\n\n </section>\n";

                std::cout << "Educational text module and slide show module generated!" << std::endl; //Inform user that the module has been generated.
            }
        }
        else if (User_Input == 'N' || User_Input == 'n' || User_Input == '0') { //If no then break loop.
            Index << "\n\n </section>\n";
            break;
        }
    }

    //Return to Body_Generator function.

}

#endif //STRUCTURED_PROGRAMMING_TASKS_DURENGO_MODULE_GENERATOR_H
