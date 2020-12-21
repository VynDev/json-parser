#include "catch.hpp"
#include "../include/json-parser/JSON.h"

TEST_CASE("Array", "[array]") {

    JSON::Array array;

    REQUIRE(array.IsValid() == true);

    SECTION("Basics") {

        REQUIRE(array.GetLenth() == 0);

        SECTION("Boolean (true)") {
            array.AddElement(true);
            REQUIRE(array.GetLenth() == 1);
            
            REQUIRE(array[0].IsBool() == true);
            REQUIRE(array[0].IsNumber() == false);
            REQUIRE(array[0].IsString() == false);
            REQUIRE(array[0].IsObject() == false);
            REQUIRE(array[0].IsArray() == false);

            REQUIRE(array[0].AsBool() == true);
        }

        SECTION("Boolean (false)") {
            array.AddElement(false);
            REQUIRE(array.GetLenth() == 1);
            
            REQUIRE(array[0].IsBool() == true);
            REQUIRE(array[0].IsNumber() == false);
            REQUIRE(array[0].IsString() == false);
            REQUIRE(array[0].IsObject() == false);
            REQUIRE(array[0].IsArray() == false);

            REQUIRE(array[0].AsBool() == false);
        }

        SECTION("Number (integer)") {
            array.AddElement(42);
            REQUIRE(array.GetLenth() == 1);
            
            REQUIRE(array[0].IsBool() == false);
            REQUIRE(array[0].IsNumber() == true);
            REQUIRE(array[0].IsString() == false);
            REQUIRE(array[0].IsObject() == false);
            REQUIRE(array[0].IsArray() == false);

            REQUIRE(array[0].AsNumber() == 42);
        }

        SECTION("Number (double)") {
            array.AddElement(42.042);
            REQUIRE(array.GetLenth() == 1);
            
            REQUIRE(array[0].IsBool() == false);
            REQUIRE(array[0].IsNumber() == true);
            REQUIRE(array[0].IsString() == false);
            REQUIRE(array[0].IsObject() == false);
            REQUIRE(array[0].IsArray() == false);

            REQUIRE(array[0].AsNumber() == 42.042);
        }

        SECTION("String") {
            array.AddElement("world");
            REQUIRE(array.GetLenth() == 1);

            REQUIRE(array[0].IsBool() == false);
            REQUIRE(array[0].IsNumber() == false);
            REQUIRE(array[0].IsString() == true);
            REQUIRE(array[0].IsObject() == false);
            REQUIRE(array[0].IsArray() == false);

            REQUIRE(array[0].AsString() == "world");
        }

        SECTION("Object") {
            array.AddObject();
            REQUIRE(array.GetLenth() == 1);

            REQUIRE(array[0].IsBool() == false);
            REQUIRE(array[0].IsNumber() == false);
            REQUIRE(array[0].IsString() == false);
            REQUIRE(array[0].IsObject() == true);
            REQUIRE(array[0].IsArray() == false);
        }

        SECTION("Array") {
            array.AddArray();
            REQUIRE(array.GetLenth() == 1);

            REQUIRE(array[0].IsBool() == false);
            REQUIRE(array[0].IsNumber() == false);
            REQUIRE(array[0].IsString() == false);
            REQUIRE(array[0].IsObject() == false);
            REQUIRE(array[0].IsArray() == true);
        }
    }

    SECTION("Normal usages") {

        array.AddElement(2);
        array.AddElement(2.1);
        array.AddElement(true);
        array.AddElement(false);
        array.AddElement("I'm a full string :)");

        REQUIRE(array.GetLenth() == 5);

        REQUIRE(array[0].IsNumber());
        REQUIRE(array[0].AsNumber() == 2);

        REQUIRE(array[1].IsNumber());
        REQUIRE(array[1].AsNumber() == 2.1);

        REQUIRE(array[2].IsBool());
        REQUIRE(array[2].AsBool() == true);

        REQUIRE(array[3].IsBool());
        REQUIRE(array[3].AsBool() == false);

        REQUIRE(array[4].IsString());
        REQUIRE(array[4].AsString() == "I'm a full string :)");
        
        SECTION("Change values") {
            array[0].AsNumber() = 4;
            REQUIRE(array[0].AsNumber() == 4);

            array[1].AsNumber() = 4.4;
            REQUIRE(array[1].AsNumber() == 4.4);

            array[2].AsBool() = false;
            REQUIRE(array[2].AsBool() == false);

            array[3].AsBool() = true;
            REQUIRE(array[3].AsBool() == true);

            array[4].AsString() = "lol ?";
            REQUIRE(array[4].AsString() == "lol ?");
        }

        SECTION("Delete values") {
            
            REQUIRE(array.GetLenth() == 5);

            SECTION("number") {
                array.Delete(0);
                REQUIRE(array.GetLenth() == 4);
            }

            SECTION("decimal_number") {
                array.Delete(1);
                REQUIRE(array.GetLenth() == 4);
            }

            SECTION("isTrue") {
                array.Delete(2);
                REQUIRE(array.GetLenth() == 4);
            }

            SECTION("isFalse") {
                array.Delete(3);
                REQUIRE(array.GetLenth() == 4);
            }

            SECTION("string") {
                array.Delete(4);
                REQUIRE(array.GetLenth() == 4);
            }
        }

        SECTION("Saving and loading json") {
            const std::string path = "./tests/json_examples/test2_save.json";

            array.Save(path);

            JSON::Array loadedArray(path);

            REQUIRE(loadedArray.IsValid() == true);
            REQUIRE(loadedArray.GetLenth() == 5);

            REQUIRE(loadedArray[0].IsNumber());
            REQUIRE(loadedArray[0].AsNumber() == 2);

            REQUIRE(loadedArray[1].IsNumber());
            REQUIRE(loadedArray[1].AsNumber() == 2.1);

            REQUIRE(loadedArray[2].IsBool());
            REQUIRE(loadedArray[2].AsBool() == true);

            REQUIRE(loadedArray[3].IsBool());
            REQUIRE(loadedArray[3].AsBool() == false);

            REQUIRE(loadedArray[4].IsString());
            REQUIRE(loadedArray[4].AsString() == "I'm a full string :)");
        }
    }

    SECTION("Normal usages 2 (alternatives)") {
        array.AddElement(2);
        array.AddElement(2.1);
        array.AddElement(true);
        array.AddElement(false);
        array.AddElement("I'm a full string :)");

        REQUIRE(array.GetLenth() == 5);

        REQUIRE(array[0].IsNumber());
        REQUIRE(array[0].AsNumber() == 2);

        REQUIRE(array[1].IsNumber());
        REQUIRE(array[1].AsNumber() == 2.1);

        REQUIRE(array[2].IsBool());
        REQUIRE(array[2].AsBool() == true);

        REQUIRE(array[3].IsBool());
        REQUIRE(array[3].AsBool() == false);

        REQUIRE(array[4].IsString());
        REQUIRE(array[4].AsString() == "I'm a full string :)");
        
        SECTION("Change values") {
            array[0] = 4;
            REQUIRE(array[0].AsNumber() == 4);

            array[1] = 4.4;
            REQUIRE(array[1].AsNumber() == 4.4);

            array[2] = false;
            REQUIRE(array[2].AsBool() == false);

            array[3] = true;
            REQUIRE(array[3].AsBool() == true);

            array[4] = "lol ?";
            REQUIRE(array[4].AsString() == "lol ?");
        }

        // Same atm
        SECTION("Delete values") {
            
            REQUIRE(array.GetLenth() == 5);

            SECTION("number") {
                array.Delete(0);
                REQUIRE(array.GetLenth() == 4);
            }

            SECTION("decimal_number") {
                array.Delete(1);
                REQUIRE(array.GetLenth() == 4);
            }

            SECTION("isTrue") {
                array.Delete(2);
                REQUIRE(array.GetLenth() == 4);
            }

            SECTION("isFalse") {
                array.Delete(3);
                REQUIRE(array.GetLenth() == 4);
            }

            SECTION("string") {
                array.Delete(4);
                REQUIRE(array.GetLenth() == 4);
            }
        }

        // Same atm
        SECTION("Saving and loading json") {
            const std::string path = "./tests/json_examples/test2_save.json";

            array.Save(path);

            JSON::Array loadedArray(path);

            REQUIRE(loadedArray.IsValid() == true);
            REQUIRE(loadedArray.GetLenth() == 5);

            REQUIRE(loadedArray[0].IsNumber());
            REQUIRE(loadedArray[0].AsNumber() == 2);

            REQUIRE(loadedArray[1].IsNumber());
            REQUIRE(loadedArray[1].AsNumber() == 2.1);

            REQUIRE(loadedArray[2].IsBool());
            REQUIRE(loadedArray[2].AsBool() == true);

            REQUIRE(loadedArray[3].IsBool());
            REQUIRE(loadedArray[3].AsBool() == false);

            REQUIRE(loadedArray[4].IsString());
            REQUIRE(loadedArray[4].AsString() == "I'm a full string :)");
        }
    }
}