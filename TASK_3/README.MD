# structured-programming-tasks-Durengo
structured-programming-tasks-Durengo created by GitHub Classroom

**Task 3: Text exporting to HTML file**

**Problem:** Create a _simple_ c++ console application that can generate a
generic HTML page by exporting code into a text file.

Our program will consist of a single cpp source file and one or multiple
headers (different modules), that will be used by the source file. The main
source file will be kept as _simple_ as possible - code wise. The source file will declare some important libraries and
call functions from other header files. A user input header file will serve
as an intermediary between the user's input and the modules' generated text. 
Multiple header files (modules) will be used for different elements of the HTML code.

**Data / Variables used:**
* This program will rely heavily on the __string class__
  * We must also include the <_fstream_> library to be able to export the
  user's input into a text file.
  * This program should be able to work by using only the <_void_> data type.
  * A header file which will be called throughout the whole code with a single function that will read the users input.
  * Multiple header files for different HTML elements.

**Formulas / Functions:**
1. We must generate and include header files into our source file.
2. Generate a header file for each major HTML element. 
3. Generate an Index.html file into which different header files (modules) will import the HTML code.
4. Prompt the user for input (Yes or NO).
5. If the user requires the shown module proceed with calling the corresponding module. Do this for each module.
6. Prompt user for any options (changes in the printed HTML code).
7. Save user selected options (temporarily) and export them into Index.html.
8. Prompt user to open the generated HTMLs file in the browser after the program ends its runtime.

**Algorithm design:**
* User is prompted with questions:
   * What should be included in the <body\> tag?
   * Call each module:
     * Should a navigation bar be added?
       * Yes -> Call Navigation Bar module
         * When a bar is added should additional functionality be added? (Buttons, dropdown buttons, etc)
           * Name of the button.
     * Title Page
       * Website name
       * Website description 
       * Additional options: Import image/video from link, other...
         * Where should it be added? (Top, Bottom? Vertically? Horizontally?)
       * Other...
     * Should other modules be added?
       * Should the specified functionality be added?


1. We take the user's input and run it through our code.
2. The program generates the user's selected options then exports each 
section, one after another into the Index.html file.
3. The program saves the text file.
4. User is prompted: open generated HTML site or not on program termination.
