#include "catch.hpp"
#include "string_word.h"
#include <string.h>

SCENARIO("Words with A Tests", "[Word_Start_A]")
{
  Army *army = new Army;
  army->addClass("Ahirley");

  GIVEN("string words")
  {
    // Check the word.
    WHEN("the word starts with A")
    {
      // Word starts with A
      THEN("print true")
      {
        REQUIRE(string_word_getFirstLetter(army->getName()) == 'A');
        army->removeClass();
        // Display True.
      }
    }

    army->addClass("Shirley");
    // Check the word.
    WHEN("the word starts with B")
    {
      // Word starts with not A
      THEN("print false")
      {
        REQUIRE(string_word_getFirstLetter(army->getName()) != 'A');
        // Display False.
      }
    }
  }
}
