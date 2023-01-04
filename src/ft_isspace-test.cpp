#include "gtest/gtest.h"

#include "libasm.h"
#include <string>

namespace {

TEST(ft_isspaceTest, AllAsciiChars) {
    for (int i = 0; i < 256; ++i) {
        EXPECT_EQ(static_cast<bool>(ft_isspace(i)), static_cast<bool>(isspace(i))) << "i = " << i;
    }
}

}
