include <gtest/gtest.h>

#include "Soundex.h"

TEST(SoundexTestsuite, ReplacesConstantsWithDigits) {
 char soundex[5];
 generateSoundex("BX", soundex);
 ASSERT_STREQ(soundex, "B200");
}

TEST(SoundexTestsuite, IgnoresNonAlphabeticCharacters) {
 char soundex[5];
 generateSoundex("A1X", soundex);
 ASSERT_STREQ(soundex, "A200");
}

TEST(SoundexTestsuite, HandlesEmptyInputString) {
 char soundex[5];
 generateSoundex("", soundex);
 ASSERT_STREQ(soundex, "0000");
}

TEST(SoundexTestsuite, HandlesDifferentCodesForSameChar) {
 char soundex[5];
 generateSoundex("CUYHIJ", soundex);
 ASSERT_STREQ(soundex, "C000");
}

TEST(SoundexTestsuite, HandlesVowels) {
 char soundex[5];
 generateSoundex("AEIOUHWY", soundex);
 ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestsuite, HandlesLowerCaseInput) {
 char soundex[5];
 generateSoundex("smith", soundex);
 ASSERT_STREQ(soundex, "S530");
}

TEST(SoundexTestsuite, HandlesUpperCaseInput) {
 char soundex[5];
 generateSoundex("JOHNSON", soundex);
 ASSERT_STREQ(soundex, "J525");
}

TEST(SoundexTestsuite, HandlesMixedCaseInput) {
 char soundex[5];
 generateSoundex("McDonald", soundex);
 ASSERT_STREQ(soundex, "M235");
}

TEST(SoundexTestsuite, HandlesLongInput) {
 char soundex[5];
 generateSoundex("Washington", soundex);
 ASSERT_STREQ(soundex, "W252");
}

TEST(SoundexTestsuite, HandlesInputWithNonAlphabeticCharacters) {
 char soundex[5];
 generateSoundex("O'Conner", soundex);
 ASSERT_STREQ(soundex, "O256");
}

TEST(SoundexTestsuite, HandlesMultipleSameCodeCharacters) {
 char soundex[5];
 generateSoundex("YYYY", soundex);
 ASSERT_STREQ(soundex, "Y000");
}

int main(int argc, char **argv) {
 ::testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}
