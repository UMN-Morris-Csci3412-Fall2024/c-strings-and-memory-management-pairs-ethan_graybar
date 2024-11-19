#include <gtest/gtest.h>

#include "disemvowel.h"

char *temp;

TEST(Disemvowel, HandleEmptyString) {
        //newly added
	temp = disemvowel((char*) "");
	ASSERT_STREQ("", temp);
	free(temp);
}

TEST(Disemvowel, HandleNoVowels) {
        //newly added
	temp = disemvowel((char*) "pqrst");
	ASSERT_STREQ("pqrst", temp);
	free(temp);
}

TEST(Disemvowel, HandleOnlyVowels) {
        //newly added
	temp = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
	ASSERT_STREQ("", temp);
	free(temp);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
        //newly added
	temp = disemvowel((char*) "Morris, Minnesota");
	ASSERT_STREQ("Mrrs, Mnnst", temp);
	free(temp);
}

TEST(Disemvowel, HandlePunctuation) {
        //newly added
	temp = disemvowel((char*) "An (Unexplained) Elephant!");
	ASSERT_STREQ("n (nxplnd) lphnt!", temp);
	free(temp);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  //newly added
  char *strDise = disemvowel(str);
  ASSERT_STREQ("xyz", strDise);

  free(str);
  free(strDise);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}