#include <ros/ros.h>
#include "test_node.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(TestSuite, testCase1)
{
    ASSERT_TRUE(random_int() != 1000);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "tester");
    ros::NodeHandle node_handle;
    return RUN_ALL_TESTS();
}
