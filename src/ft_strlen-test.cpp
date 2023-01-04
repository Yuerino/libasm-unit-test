#include "gtest/gtest.h"

#include "libasm.h"
#include <string>

namespace {

TEST(ft_strlenTest, BasicString) {
    const char *str = "Hello World!";
    EXPECT_EQ(ft_strlen(str), strlen(str));
}

TEST(ft_strlenTest, EmptyString) {
    const char *str = "";
    EXPECT_EQ(ft_strlen(str), 0);
}

TEST(ft_strlenTest, WhiteSpaceString) {
    const char *str = "\n\t\v\f\r ";
    EXPECT_EQ(ft_strlen(str), strlen(str));
}

TEST(ft_strlenTest, UnicodeString) {
    const char *str = "♫♪.ılılıll|̲̅̅●̲̅̅|̲̅̅=̲̅̅|̲̅̅●̲̅̅|llılılı.♫♪";
    EXPECT_EQ(ft_strlen(str), strlen(str));
}

TEST(ft_strlenTest, StringWithNullInMiddle) {
    const char *str = "Hello\0World!";
    EXPECT_EQ(ft_strlen(str), strlen(str));
}

TEST(ft_strlenTest, StringWithEscapeChar) {
    const char *str = "Hello\xbaWorld!";
    EXPECT_EQ(ft_strlen(str), strlen(str));
}

TEST(ft_strlenDeathTest, NullString) {
    EXPECT_EXIT(ft_strlen(NULL), ::testing::KilledBySignal(SIGSEGV), ".*");
}

}
