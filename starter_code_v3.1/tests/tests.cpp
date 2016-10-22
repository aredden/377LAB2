// tests.cpp
#include "../src/BoundedBuffer.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>

//Test checking if bounded buffer is empty
TEST(PCTest, Test1) {
    BoundedBuffer *BB = new BoundedBuffer(5);
    EXPECT_TRUE(BB->isEmpty());

    delete BB;
}

//Test checking append() and remove() from buffer
TEST(PCTest, Test2){
    BoundedBuffer *BB = new BoundedBuffer(5);
    BB->append(0);
    ASSERT_EQ(0,BB->remove());

    delete BB;
}

//TODO: add test cases here
TEST(PCTest, Test3){
    BoundedBuffer *BB = new BoundedBuffer(5);
    BB->append(0);
    BB->append(1);
    ASSERT_EQ(0,BB->remove());
    delete BB;
}

TEST(PCTest, Test4){
    BoundedBuffer *BB = new BoundedBuffer(5);
    BB->append(0);
    BB->append(3);
    BB->append(7);
    ASSERT_EQ(0,BB->remove());
    ASSERT_EQ(3,BB->remove());
    EXPECT_FALSE(BB->isEmpty());
    BB->append(13);
    ASSERT_EQ(7,BB->remove());
    ASSERT_EQ(13,BB->remove());
    EXPECT_TRUE(BB->isEmpty());

    delete BB;
}
// TEST(test_case_name, test_name) {
//  ... test body ...
// }


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
