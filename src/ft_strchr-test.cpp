#include "gtest/gtest.h"

#include "libasm.h"
#include <string>

namespace {

TEST(ft_strchrTest, BasicString) {
    const char *str = "Hello World!";
    EXPECT_EQ(ft_strchr(str, 'o'), strchr(str, 'o'));
}

TEST(ft_strchrTest, FirstCharOfString) {
    const char *str = "Hello World!";
    EXPECT_EQ(ft_strchr(str, 'H'), strchr(str, 'H'));
}

TEST(ft_strchrTest, LastCharOfString) {
    const char *str = "Hello World!";
    EXPECT_EQ(ft_strchr(str, '!'), strchr(str, '!'));
}

TEST(ft_strchrTest, NotFound) {
    const char *str = "Hello World!";
    EXPECT_EQ(ft_strchr(str, 'X'), strchr(str, 'X'));
}

TEST(ft_strchrTest, CharAfterNull) {
    const char *str = "Hello World!\0SecretX";
    EXPECT_EQ(ft_strchr(str, 'X'), strchr(str, 'X'));
}

TEST(ft_strchrTest, EmptyString) {
    const char *str = "";
    EXPECT_EQ(ft_strchr(str, 'o'), strchr(str, 'o'));
}

TEST(ft_strchrTest, NullChar) {
    const char *str = "Hello\0World!";
    EXPECT_EQ(ft_strchr(str, '\0'), strchr(str, '\0'));
}

TEST(ft_strchrDeathTest, NullString) {
    EXPECT_EXIT(ft_strchr(NULL, '?'), ::testing::KilledBySignal(SIGSEGV), ".*");
}

}
