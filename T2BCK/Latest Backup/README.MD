# structured-programming-tasks-Durengo
structured-programming-tasks-Durengo created by GitHub Classroom

**Task 2: Dynamic memory**

**Problem:** Create a console application that is basically an electronic shop that sells cloud services e.g.: cloud storage, cloud database, other.
We must use dynamic memory to allocate and generate values for this service. **Pointers must be used.**

Our program will consist of a single cpp source file which will call other headers for user input, generated data variables and stored data variables.
We will use 2 classes: one for the server data type and the other for the user data type.

**Data / Variables used:**

* Class: Server Type:
  * Class Object: Cloud Storage;
  * Class Object: Cloud Database;
  * Class Object: Cloud Bandwidth;
  * Other class objects...
* Class: User type:
  * Admin - to modify Server information;
  * User - to use the service without being able to modify the information.

**Formulas / Functions:**
1. _Randomly_ generate and allocate an amount of storage to server class objects.
2. Prompt user to login or register an account: choose (1) Admin or (2) User (3) Register. (Admin is password protected.)
   * The admin has the ability to freely modify the data of server class objects and modify user information. (This step is mostly for debugging purposes.)
   * The user can only buy a service/services (remove from the cloud), sell back a certain amount of said service(-s) (return an amount of storage to the cloud),
check their account information, extend their subscription, resize their service (reallocate the amount of storage) opt-out of cloud services (return all the storage).

**Algorithm design:**
