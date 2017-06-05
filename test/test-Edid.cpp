#include <gtest/gtest.h>

#include "../src/Edid.h"

using namespace std;

TEST(Edid_constructor, validEdid) {
    const size_t len = EDID_MIN_LENGTH * 3 / 2;
    unsigned char val[len];
    memset(val, 1, len);

    Edid(val, len, "blargh");
}

TEST(Edid_constructor, shortEdid) {
    const size_t len = EDID_MIN_LENGTH - 1;
    unsigned char val[len];
    memset(val, 1, len);

    EXPECT_THROW(Edid(val, len, "blargh"), invalid_argument);
}

TEST(Edid_maxCmHorizVert, valid) {
    const size_t len = EDID_MIN_LENGTH;
    unsigned char val[len];
    memset(val, 1, len);
    val[EDID_BYTE_MAX_CM_HORIZ] = 2;
    val[EDID_BYTE_MAX_CM_VERT] = 3;

    Edid edid = Edid(val, len, "blargh");

    EXPECT_EQ(2, edid.maxCmHoriz());
    EXPECT_EQ(3, edid.maxCmVert());
}