# structured-programming-tasks-Durengo
structured-programming-tasks-Durengo created by GitHub Classroom

**Task 2: Dynamic memory**

**Problem:** Create a console application that is basically an electronic shop that sells cloud services e.g.: cloud storage, cloud database, other.
We must use dynamic memory to allocate and generate values for this service. **New and delete must be used.**

This program will have a multiple modules which will interact with each other. Starting with a "Linked List" module, a "User" class,
a "Data manager" module, a "Console" module and a "Logging" module.

**Data / Variables used:**

* Class: Data manager
  * Keep track of all data and variables.
    * Keep track of the amount of users.
    * Keep track of every users' total and individual usage amount.
  * Allocate heap memory and delete allocated heap memory.

* Class: Linked_List
  * To create a dynamic list which allocates every node to heap memory.
  * To allow the user dynamically create and delete users.
  * To allow other functions to find the required user by counting down each node from the start to the finish.

* Class: User
  * Object types:
      * Admin - to modify and manipulate: server information, other user account information and services' usage information, access log files;
      * User - to buy or refund certain services, to modify their own account information (username, password, or delete account).

* Class: Server
  * Object Types:
      * Class Object: Cloud Storage;
      * Class Object: Cloud Database;
      * Class Object: Cloud Bandwidth;
      * Other class objects...

* Class: Console
  * To print to console any message.
  * To take any required user input.
  * To prevent input and output from breaking the program.

* Class: Logging
  * To keep track of time:
    * When the program has started execution. 
    * When the program was terminated.
  * To keep track of everything that was printed and at what time it was printed.
  * To keep track of what kind of inputs were given by the user.
  * Keep track of exceptions in the runtime code.

**Formulas / Functions:**
1. _Randomly_ generate an integer and allocate that integer to heap memory.
2. Prompt user to login or create an account: choose (1) Admin or (2) User (3) Create and account.
    * The admin has the ability to freely modify the data of server class objects and modify user information. (This step is mostly for debugging purposes.)
    * The user can only buy a service/services (remove from the cloud), sell back a certain amount of said service(-s) (return an amount of storage to the cloud),
      check their account information, extend their subscription, resize their service (reallocate the amount of storage) opt-out of cloud services (return all the storage).

**Algorithm design:**
