#include <gtest/gtest.h>

#include "../../src/example/add.h"

TEST(operations, add) {
    ASSERT_EQ(operations::add(2, 3), 5);
}

