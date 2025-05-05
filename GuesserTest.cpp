/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, First_try_guess)
{
  Guesser object("Secret");
  ASSERT_TRUE( object.match("Secret"));
}

TEST(GuesserTest, First_try_guess_remaning)
{
  Guesser object("Secret");
	object.match("Secret");
  ASSERT_EQ(3, object.remaining());
}

TEST(GuesserTest, Second_try_guess)
{
  Guesser object("Secret");
	object.match("secret");
  ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, Second_try_guess_remaning)
{
  Guesser object("Secret");
	object.match("secret");
  ASSERT_EQ(2, object.remaining());
}

TEST(GuesserTest, Third_try_guess)
{
  Guesser object("Secret");
        object.match("secret");
	object.match("secret");
  ASSERT_TRUE(object.match("Secret"));
}
TEST(GuesserTest, Third_try_guess_remaning)
{
  Guesser object("Secret");
        object.match("secret");
	object.match("secret");
  ASSERT_EQ(1, object.remaining());
}

TEST(GuesserTest, Ran_out_of_guesses)
{
  Guesser object("Secret");
	object.match("secret");
        object.match("secret");
	object.match("secret");
  ASSERT_FALSE(object.match("Secret"));
}
TEST(GuesserTest, Out_of_guess_remaning)
{
  Guesser object("Secret");
        object.match("secret");
        object.match("secret");
	object.match("secret");
  ASSERT_EQ(0, object.remaining());
}
TEST(GuesserTest, Special_characters)
{
  Guesser object("!@#$%^&*()");
  ASSERT_TRUE(object.match("!@#$%^&*()"));
}
TEST(GuesserTest, empty_string)
{
  Guesser object("");
  ASSERT_TRUE(object.match(""));
}
TEST(GuesserTest, Just_5_spaces)
{
  Guesser object("     ");
  ASSERT_TRUE(object.match("     "));
}

TEST(GuesserTest, longer_than_32_charcters)
{
  Guesser object("qwertyuiopasdfghjklzxcvbnm1234567890!");
  ASSERT_TRUE(object.match("qwertyuiopasdfghjklzxcvbnm1234567890!"));
}

TEST(GuesserTest, bypass_password_using_guesser_constructor)
{
  Guesser object("qwertyuiopasdfghjklzxcvbnm1234567890!");
  ASSERT_FALSE(object.match("qwertyuiopasdfghjklzxcvbnm123456"));
}
