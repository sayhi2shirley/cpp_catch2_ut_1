# cpp_catch2_ut_1
This repository will provide an overall knowledge for the Catch2 by creating a simple test case where the class functions are verfied.


Functional/Black Box Testing (Testers)
Internal architecture is unknown

Applies at all granularity levels - unit-testing, integration testing, system testing, regression testing, etc., 

High-Level Testing 

Structural/White Box testing (Developer)
In BB testing, part of the program can't be executed, a defect may loom in that. 

The part can be condition, statement, transition etc., 

Interesting part is this can be automated. 

Low-Level testing 

Fuzz Testing

There are plenty of test framework for C++, but why another?
Some popular other test frameworks of C++ are Boost.Test, Google Test, Cute, CPP Unit, etc., 

Too much ceremony is needed, to set the framework and too much friction too. 
What is Catch2 ?
When a SuperHero catches bullet, it is the fastest catch. Similarly, this header only framework helps us to identify the bugs in our code by just downloading catch2.hpp header file. 
Catch stands for C++ Automated Test Cases in Header.
We want to lower the defect rate always. 
C++ is not a part for ecosystem like other languages. 
It is the test framework for Unit-tests, used to test the modern C++.
Traditional assert
Assert is a preprocessor macro and used to provide two results like success or failure if certain conditions are true. It evaluates the conditional expression. 

assert(value > 5); 

If the given value is 4, the program will terminate stating invalid assertion is issued with the function name and line number.

Advantages
It helps in efficient debugging. 
Ridiculously simple to get started with and doesn't require any dependencies since it is header only framework. 
It is an Open source. 
Too many ceremonies are needed to set the framework. 
Catch looks promising tool to write clearer testcases. 
This will be used to check,

Parameters passed to the function are valid or not. 
In C programming, we used to write the following:
int error_handling(char *val) {
      if (val == NULL) {
          printf("The given value is NULL");
          return 0;
      }

      /* Execute the other statements*/
      return 1;
}
With the help of assert calls, C++ avoids writing more code. 

#include <cassert> // Header to be added

int error_handling(char *val) {

      /* if (val == nullptr) {
       *    cout << "The given value is NULL";
       * }
       */

      assert(val != nullptr);

      /* Execute the other statements*/
      return 1;
}
Return value of the function 
Checks the array bounds
#include <iostream>
#include <cassert> // Header to be added
using namespace std;

int error_handling(char *val) {

      /* if (val == nullptr) {
       *    cout << "The given value is NULL";
       * }
       */

      assert(val != nullptr);
      cout << "Value is " << val << endl;
      
      return 1;
}

int main() {
   char *str = "Hello";
   error_handling(str);
   cout << str << " is printed" << endl;
   error_handling(nullptr);
   cout << "nullptr is printed" << endl;
   return 0;
}
Output 

Value is Hello
Hello is printed
a.out: main.cpp:12: int error_handling(char*): Assertion `val != nullptr' failed.
These assertions calls shouldn't be invoked in the release build of the application. So, to disable these assertion calls, we have NDEBUG macro which disables all calls to assert.

#include <iostream>
#include <cassert> // Header to be added
using namespace std;

#define NDEBUG

int error_handling(char *val) {

      /* if (val == nullptr) {
       *    cout << "The given value is NULL";
       * }
       */

      assert(val != nullptr);
      cout << "Value is " << val << endl;
      
      return 1;
}

int main() {
   char *str = "Hello";
   error_handling(str);
   cout << str << " is printed" << endl;
   error_handling(nullptr);
   cout << "nullptr is printed" << endl;
   return 0;
}

NDEBUG is added after the cassert header file inclusion, so it couldn't disable the assert calls. So, the program is terminated. 

main.cpp:21:16: warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
   21 |    char *str = "Hello";
      |                ^~~~~~~
Value is Hello
Hello is printed
a.out: main.cpp:14: int error_handling(char*): Assertion `val != nullptr' failed.
#include <iostream>
#define NDEBUG
#include <cassert> // Header to be added
using namespace std;

int error_handling(char *val) {

      /* if (val == nullptr) {
       *    cout << "The given value is NULL";
       * }
       */

      assert(val != nullptr);
      cout << "Value is " << val << endl;
      
      return 1;
}

int main() {
   char *str = "Hello";
   error_handling(str);
   cout << str << " is printed" << endl;
   error_handling(nullptr);
   cout << "nullptr is printed" << endl;
   return 0;
}
main.cpp:20:16: warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
   20 |    char *str = "Hello";
      |                ^~~~~~~
Value is Hello
Hello is printed
Value is 

When the NDEBUG is included before the cassert inclusion, it could disable all the assert calls. So, the program is still alive with the invalid inputs.
Demo for Catch2
Catch is a single header library. C++ headers are suffixed as hpp. It can be downloaded from here.
1. Firstly add header file in main.cpp which is located in CatchTest4

#include "catch.hpp"
Output

catch.hpp: No such file or directory
2. Now, add the catch.hpp file into the folder, now t threw linking error, so add the #define 

#define CATCH_CONFIG_MAIN 

This tells the compiler that catch has to provide main to this file, so we can build a binary executable. 

3. Now, just run the test 

./CatchTest4 
It would give result as 

=========================================================

No tests ran

There are more options in catch2 to explore 

4. We can't just start writing the tests in main.cpp because CATCH_CONFIG_MAIN will load a huge library files, so we have to create a new file Tests.cpp 

CatchTest4 

    |________ CMake_Lists.txt

    |________ main.cpp

    |________ catch.hpp

    |________ Tests.cpp 

In the real-time project, it would properly fit in the project framework as below. 

├── build
├── CMakeLists.txt
├── include
│   └── sample.hpp
├── src
│   ├── sample.cpp
│   └── main.cpp
└── tests
    ├── catch.hpp
    └── test.cpp
4 directories, 6 files
5. Start writing a test case in Tests.cpp

Testcases in Catch are really functions. 

TEST_CASE("testcase_name", "[tagName]")
{
   REQUIRE(expression);
}
TEST_CASE - It is basically a function which introduces a test condition using maro. 

tagName filters the testcases to run

But we can also write without the parameters in TEST_CASE if we have only one test case. 

TEST_CASE()
{
   REQUIRE(10 * 6 == 54);
}
Output 

CatchTest4/Tests.cpp : Failed 

..............

=========================================================

testcases : 1   |   1 failed

assertions: 1  |   1 failed

These kind of plain catch was introduced before 11 years. Catch was originally written in C++98. 

In the year 2017, Catch2 rebased on C++.

New features added into Catch 2 are :

New Name - Catch 2
Matchers - it is already available in catch1 at the end.
Additional Reporters
Listeners 
Run Sections 
Special Tags 
Commas in Assertions 
New Clara (Command Line)
Micro BenchMarks
BDD (Behaviour Driven Development)
Testcases are written using BDD(Behaviour Driven Development) style.

Instead of naming the tests with function calls, tests can be written as nested series of Given-When-Then statements. It is a lot more easier to understand what the hell the tests are doing. This is called BDD style. 

void
test_GivenString_WhenTheWordStartsWithA_ThenDisplayTrue()
{
  // Test goes here.
}
The above is how traditionally I could write the test function. 

SCENARIO("Words with A Tests", "[Word_Start_A]")
{
  GIVEN("string words")
  {
    // Check the word.
    WHEN("the word starts with A")
    {
      // Word starts with A
      THEN("print true")
      {
        // Display True.
      }
    }
  }
}
Isn't a lot more clearer? Each of the clause takes its own place

SCENARIO("Words with A Tests", "[Word_Start_A]")
{
  GIVEN("string words")
  {
    // Check the word.
    WHEN("the word starts with A")
    {
      // Word starts with A
      THEN("print true")
      {
        // Display True.
      }
    }

    // Check the word.
    WHEN("the word starts with B")
    {
      // Word starts with not A
      THEN("print false")
      {
        // Display False.
      }
    }
  }
}
Scenario: word starts with A or not       
     Given: A string with some characters 
      When: word starts with A            
      Then: display true                  


hello@linux:~/Documents/cpp/catch2$ ls -al 
total 1338
drwx------+ 2 sv187 sv187       8 Jan 31 11:27 .
drwxrwxr-x  4 sv187 sv187       5 Jan 31 08:58 ..
-rw-------+ 1 sv187 sv187  657174 Jan 31 08:59 catch.hpp
-rwx------+ 1 sv187 sv187 3083704 Jan 31 11:27 hello
-rw-------+ 1 sv187 sv187      94 Jan 31 11:27 string_word.cpp  >>> Testcase functions
-rw-------+ 1 sv187 sv187     681 Jan 31 11:26 string_word.h       >>> Class & testcase prototype
-rw-------+ 1 sv187 sv187     245 Jan 31 11:09 test_main.cpp    >>> Separate file for loading catch.hpp
-rw-------+ 1 sv187 sv187     740 Jan 31 11:26 test_string_word.cpp  >>> Catch2 testcase
hello@linux:~/Documents/cpp/catch2$ 
The above example is in a separate post to keep things clearer. Click Here. 

The hello binary have a bunch of fun built-in command line options. 

The results will be thrown like this based on the string I passed. 

hello@linux::~/Documents/cpp/catch2$ g++ string_word.cpp test_main.cpp test_string_word.cpp -o hello
hello@linux::~/Documents/cpp/catch2$ ./hello

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
hello is a Catch v2.13.8 host application.
Run with -? for options

-------------------------------------------------------------------------------
Scenario: Words with A Tests
      Given: string words
       When: the word starts with B
       Then: print false
-------------------------------------------------------------------------------
test_string_word.cpp:29
...............................................................................

test_string_word.cpp:31: FAILED:
  REQUIRE( string_word_getFirstLetter(army->getName()) != 'A' )
with expansion:
  'A' != 'A'

===============================================================================
test cases: 1 | 1 failed
assertions: 2 | 1 passed | 1 failed

hello@linux:~/Documents/cpp/catch2$

Use of SECTIONS in catch2 
While testing the entity using REQUIRE, we might additionally wants to check what happens if the entity size is less or more. In this case, we will go for SECTION. 

SECTION will be executed freshly from the start (TESTCASE)

#include <catch2/catch_test_macros.hpp>

#include <iostream>

TEST_CASE("Section showcase") {
    std::cout << '1';
    SECTION("A") {
        std::cout << 'A';
    }
    SECTION("B") {
        std::cout << 'B';
    }
    std::cout << '\n';
}
Output 
clang-12: warning: -lCatch2Main: 'linker' input unused [-Wunused-command-line-argument]
ASM generation compiler returned: 0
Execution build compiler returned: 0
Program returned: 0
1A
1B
===============================================================================
test cases: 1 | 1 passed
assertions: - none -


New features in Catch 2 
Matchers, Listeners, Additional reporters, Run Sections, Special tags, commas in assertions, New clara (command line), new name (Catch2), Micro-benchmarks.

Regular Macros
REQUIRE/CHECK 
The REQUIRE family of macros tests an expression and aborts the test case if it fails. The CHECK family are equivalent but execution continues in the same test case even if the assertion fails but reports the error.

Evaluates and records the result. If an exception is caught, it will be reported and counted as failure. 

Overly complex expressions can't be decomposed by compiler and thus will not compile so split into two macros.

CHECK(a == 1 && b == 2);    ====>    CHECK( a == 1 ); CHECK( b == 2);  
REQUIRE_FALSE/CHECK_FALSE
Evaluates and records the logical NOT of the result. 

FLOATING POINT COMPARISONS
REQUIRE( performComputation() == Approx( 2.1 ) );

Study is required for epsilon, margin, and scale. 
EXCEPTIONS
REQUIRE_NOTHROW
CHECK_NOTHROW

Expects that no exception is thrown during evaluation of the expression.

REQUIRE_THROWS
CHECK_THROWS

REQUIRE_THROWS_AS
CHECK_THROWS_AS
REQUIRE_THROWS_WITH
CHECK_THROWS_WITH
REQUIRE_THROWS_MATCHES
CHECK_THROWS_MATCHES

REQUIRE_NOTHROW([&](){
    int i = 1;
    int j = 2;
    auto k = i + j;
    if (k == 3) {
        throw 1;
    }
}());
-fno-expressions 
Click here to read more about exception. Usually the exceptions can't be disabled, but with the help of -fno-expressions can disable the exceptions. If the environment doesn't have exceptions, we can't run catch. But from Catch2 onwards, we can run catch even if there is no exceptions. 
 Matcher Expression 
We can also include the header file for matchers. 

#include <catch2/matchers/catch_matchers_string.hpp>

REQUIRE_THAT( lhs, matcher expression ) and
CHECK_THAT( lhs, matcher expression )


For example, to assert that a string ends with the "as a service" substring, you can write the following assertion

using Catch::Matchers::EndsWith;

REQUIRE_THAT( getSomeString(), EndsWith("as a service") );
Individual matchers can also be combined using the C++ logical operators, that is &&, ||, and !, like so:

using Catch::Matchers::EndsWith;
using Catch::Matchers::ContainsSubstring;

REQUIRE_THAT( getSomeString(),
              EndsWith("as a service") && ContainsSubstring("web scale"));
In the above case, the matchers are dead after the execution of the line REQUIRE_THAT, but we still want the matchers to be outlived. 
String Matchers 

New Clara (Command Line)
CATCH_CONFIG_RUNNER
It is a macro which will still compile the implementation but we need to supply our own main. 

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int main(int argc, char* argv[]) 
{
    Catch::Session session;

    auto exitCode = session.applyCommandLine(argc, argv);
    if (exitCode != 0) {
        return exitCode;
    }

    return session.run();
}
session.run() will run our tests. 

This gives some point that we can hook into. Let's consider that we want to set an integer from command line so write a parser.

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int main(int argc, char* argv[]) 
{
    Catch::Session session;
    int number = 0;

    using namespace Catch::clara;

    /* Get the current command line interface objects.
     * Then opt will bind the number passed from CLI.
     * Provide the options also like m 
     */
    auto cli = session.cli() | Opt(number, "a number")
               ["-m"] ["--number"]
               ("Some Custom Parser");
    session.cli(cli);

    auto exitCode = session.applyCommandLine(argc, argv);
    if (exitCode != 0) {
        return exitCode;
    }

    std::cout << "The number is " << number << endl;
    return session.run();
}
If the application has different components but they need to be configured from the command line, It is not necessary that they need to know each other. Each can provide their own parsers upto a top level that composes them together, and you will get rich command line interface to the whole system. 

Generators 
It provides potentially large sets of test data to a single test case, and can provide combinations of test data. It is quite powerful. 

TEST_CASE("10*10 ints")
{
   auto x = GENERATE(range(1, 11));
   auto y = GENERATE(range(101, 111));
   
   CHECK(x < y);
}


TEST_CASE("10*10 sstrings")
{
   /* Instead of range, specific values can be passed. */
   auto x = GENERATE(as<std::string>(), "a", "b", "c");

   SECTION("ONE") {
       /* WE can ttest for whole range values 
        * like (1,11) and some edge cases 2
        */
       auto x = GENERATE(range(1, 11), 2);
       CAPTURE(i, x);
       SUCCEED;
   }
   SECTION("TWO") {
       auto y = GENERATE(range(101.12, 111.90));
       CAPTURE(i, y);
       SUCCEED;
   }

   CHECK(x < y);
}
It will run for the cross product of the GENERATE. 

We can also use GENERATE on top of the structure.



References :

BDD style testcase - http://www.electronvector.com/blog/using-catch-to-write-bdd-style-unit-tests-for-c

https://www.softwaretestinghelp.com/assert-in-cpp/#:~:text=Answer%3A%20An%20assert%20in%20C%2B%2B,and%20the%20program%20is%20terminated.

https://mariusbancila.ro/blog/2018/03/29/writing-cpp-unit-tests-with-catch2/

https://github.com/catchorg/Catch2

https://github.com/catchorg/Catch2/blob/devel/docs/assertions.md#top
