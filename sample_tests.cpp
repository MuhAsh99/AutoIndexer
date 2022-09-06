////
//// Created by MARK FONTENOT on 9/14/21.
////

#include "catch.hpp"
#include "DSVector.h"
#include "DSString.h"

TEST_CASE("DSVector", "[DSVector]") {
    REQUIRE((2 * 2) == 4);
    REQUIRE((1 * 5) == 5);

    SECTION("find(const T& value)"){
        DSVector<DSString> v1;
        DSString temp = "hi";
        v1.push_back(temp);
        v1.find("hi");
        REQUIRE(v1.find("hi") == 0);
        DSVector<int> v2;
        int x = 4;
        v2.push_back(x);
        x = 5;
        v2.push_back(x);
        x = 6;
        v2.push_back(x);
        v2.find(7);
        REQUIRE(!v2.find(7) == 0);
        DSVector<DSString> v3;
        DSString word = "hello";
        v3.push_back(word);
        word = "my";
        v3.push_back(word);
        word = "love";
        v3.push_back(word);
        v3.find("love");
        REQUIRE(v3.find("my") == 1);

    }

    SECTION("sizeOf()"){
        DSVector <int> v1;
        v1.push_back(1);
        REQUIRE(v1.sizeOf() == 1);
        v1.push_back(2);
        v1.push_back(3);
        REQUIRE(v1.sizeOf() == 3);
        DSVector <DSString> v2;
        v2.push_back("hello");
        v2.push_back("my");
        v2.push_back("friend");
        REQUIRE(v2.sizeOf() == 3);
    }

    SECTION("operator[]"){
        DSVector <int> v1;
        v1.push_back(1);
        v1.push_back(2);
        REQUIRE(v1[1] == 2);
        DSVector <DSString> v2;
        v2.push_back("hello");
        v2.push_back("hi");
        v2.push_back("yo");
        REQUIRE(v2[2] == "yo");
        REQUIRE(!(v2[0] == "hi"));

    }

    SECTION("removeAt(const pos num)"){
        DSVector <int> v1;
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        v1.removeAt(2);
        REQUIRE(!(v1[2] == 4));
        v1.removeAt(0);
        REQUIRE(!(v1[0] == 2));
        v1.removeAt(1);
        REQUIRE(!(v1[3] == 5));
    }

    SECTION("insert( int pos, const T& value )"){
        DSVector<int> v1;
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.insert(1, 4);
        REQUIRE(v1[1] == 4);

    }

    SECTION("findSomething(const T& value, int index)"){
        DSVector<DSString> v1;
        v1.push_back("hi");
        v1.push_back("hey");
        v1.push_back("hello");
        REQUIRE(v1.findSomething("hi", 0) == 0);
        REQUIRE(v1.findSomething("hey", 1) == 1);
        REQUIRE(v1.findSomething("hello", 2) == 2);
    }



}