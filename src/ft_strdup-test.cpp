#include "gtest/gtest.h"

#include "libasm.h"
#include <string>

namespace {

TEST(ft_strdupTest, BasicString) {
    char *str = ft_strdup("Hello World!");
    EXPECT_TRUE(strcmp(str, "Hello World!") == 0);
    free(str);
}

TEST(ft_strdupTest, StringWithNullInMiddle) {
    char *str = ft_strdup("Hello\0World!");
    EXPECT_TRUE(strcmp(str, "Hello\0World!") == 0);
    free(str);
}

TEST(ft_strdupTest, EmptyString) {
    char *str = ft_strdup("");
    EXPECT_TRUE(strcmp(str, "") == 0);
    free(str);
}

TEST(ft_strdupDeathTest, NullString) {
    EXPECT_EXIT(ft_strdup(NULL), ::testing::KilledBySignal(SIGSEGV), ".*");
}

// TODO: test malloc null by mocking malloc

}
