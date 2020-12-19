#include "catch.hpp"
#include "../include/json-parser/JSON.h"

TEST_CASE("Object", "[object]") {

    JSON::Object object;

    REQUIRE(object.IsValid() == true);

    SECTION("Basics") {

        REQUIRE(object.HasKey("hello") == false);

        SECTION("Boolean (true)") {
            object.AddField("hello", true);
            REQUIRE(object.HasKey("hello") == true);
            
            REQUIRE(object["hello"].IsBool() == true);
            REQUIRE(object["hello"].IsNumber() == false);
            REQUIRE(object["hello"].IsString() == false);
            REQUIRE(object["hello"].IsObject() == false);
            REQUIRE(object["hello"].IsArray() == false);

            REQUIRE(object["hello"].AsBool() == true);
        }

        SECTION("Boolean (false)") {
            object.AddField("hello", false);
            REQUIRE(object.HasKey("hello") == true);
            
            REQUIRE(object["hello"].IsBool() == true);
            REQUIRE(object["hello"].IsNumber() == false);
            REQUIRE(object["hello"].IsString() == false);
            REQUIRE(object["hello"].IsObject() == false);
            REQUIRE(object["hello"].IsArray() == false);

            REQUIRE(object["hello"].AsBool() == false);
        }

        SECTION("Number (integer)") {
            object.AddField("hello", 42);
            REQUIRE(object.HasKey("hello") == true);
            
            REQUIRE(object["hello"].IsBool() == false);
            REQUIRE(object["hello"].IsNumber() == true);
            REQUIRE(object["hello"].IsString() == false);
            REQUIRE(object["hello"].IsObject() == false);
            REQUIRE(object["hello"].IsArray() == false);

            REQUIRE(object["hello"].AsNumber() == 42);
        }

        SECTION("Number (double)") {
            object.AddField("hello", 42.042);
            REQUIRE(object.HasKey("hello") == true);
            
            REQUIRE(object["hello"].IsBool() == false);
            REQUIRE(object["hello"].IsNumber() == true);
            REQUIRE(object["hello"].IsString() == false);
            REQUIRE(object["hello"].IsObject() == false);
            REQUIRE(object["hello"].IsArray() == false);

            REQUIRE(object["hello"].AsNumber() == 42.042);
        }

        SECTION("String") {
            object.AddField("hello", "world");
            REQUIRE(object.HasKey("hello") == true);

            REQUIRE(object["hello"].IsBool() == false);
            REQUIRE(object["hello"].IsNumber() == false);
            REQUIRE(object["hello"].IsString() == true);
            REQUIRE(object["hello"].IsObject() == false);
            REQUIRE(object["hello"].IsArray() == false);

            REQUIRE(object["hello"].AsString() == "world");
        }

        SECTION("Object") {
            object.AddObject("hello");
            REQUIRE(object.HasKey("hello") == true);

            REQUIRE(object["hello"].IsBool() == false);
            REQUIRE(object["hello"].IsNumber() == false);
            REQUIRE(object["hello"].IsString() == false);
            REQUIRE(object["hello"].IsObject() == true);
            REQUIRE(object["hello"].IsArray() == false);
        }

        SECTION("Array") {
            object.AddArray("hello");
            REQUIRE(object.HasKey("hello") == true);

            REQUIRE(object["hello"].IsBool() == false);
            REQUIRE(object["hello"].IsNumber() == false);
            REQUIRE(object["hello"].IsString() == false);
            REQUIRE(object["hello"].IsObject() == false);
            REQUIRE(object["hello"].IsArray() == true);
        }
    }

    SECTION("Normal usages") {

        object.AddField("number", 2);
        object.AddField("decimal_number", 2.1);
        object.AddField("isTrue", true);
        object.AddField("isFalse", false);
        object.AddField("string", "I'm a full string :)");

        REQUIRE(object["number"].IsNumber());
        REQUIRE(object["number"].AsNumber() == 2);

        REQUIRE(object["decimal_number"].IsNumber());
        REQUIRE(object["decimal_number"].AsNumber() == 2.1);

        REQUIRE(object["isTrue"].IsBool());
        REQUIRE(object["isTrue"].AsBool() == true);

        REQUIRE(object["isFalse"].IsBool());
        REQUIRE(object["isFalse"].AsBool() == false);

        REQUIRE(object["string"].IsString());
        REQUIRE(object["string"].AsString() == "I'm a full string :)");
        
        SECTION("Change values") {
            object["number"].AsNumber() = 4;
            REQUIRE(object["number"].AsNumber() == 4);

            object["decimal_number"].AsNumber() = 4.4;
            REQUIRE(object["decimal_number"].AsNumber() == 4.4);

            object["isTrue"].AsBool() = false;
            REQUIRE(object["isTrue"].AsBool() == false);

            object["isFalse"].AsBool() = true;
            REQUIRE(object["isFalse"].AsBool() == true);

            object["string"].AsString() = "lol ?";
            REQUIRE(object["string"].AsString() == "lol ?");
        }

        SECTION("Delete values") {
            
            REQUIRE(object.HasKey("number") == true);
            REQUIRE(object.HasKey("decimal_number") == true);
            REQUIRE(object.HasKey("isTrue") == true);
            REQUIRE(object.HasKey("isFalse") == true);
            REQUIRE(object.HasKey("string") == true);

            SECTION("number") {
                object.Remove("number");
                REQUIRE(object.HasKey("number") == false);
                REQUIRE(object.HasKey("decimal_number") == true);
                REQUIRE(object.HasKey("isTrue") == true);
                REQUIRE(object.HasKey("isFalse") == true);
                REQUIRE(object.HasKey("string") == true);
            }

            SECTION("decimal_number") {
                object.Remove("decimal_number");
                REQUIRE(object.HasKey("number") == true);
                REQUIRE(object.HasKey("decimal_number") == false);
                REQUIRE(object.HasKey("isTrue") == true);
                REQUIRE(object.HasKey("isFalse") == true);
                REQUIRE(object.HasKey("string") == true);
            }

            SECTION("isTrue") {
                object.Remove("isTrue");
                REQUIRE(object.HasKey("number") == true);
                REQUIRE(object.HasKey("decimal_number") == true);
                REQUIRE(object.HasKey("isTrue") == false);
                REQUIRE(object.HasKey("isFalse") == true);
                REQUIRE(object.HasKey("string") == true);
            }

            SECTION("isFalse") {
                object.Remove("isFalse");
                REQUIRE(object.HasKey("number") == true);
                REQUIRE(object.HasKey("decimal_number") == true);
                REQUIRE(object.HasKey("isTrue") == true);
                REQUIRE(object.HasKey("isFalse") == false);
                REQUIRE(object.HasKey("string") == true);
            }

            SECTION("string") {
                object.Remove("string");
                REQUIRE(object.HasKey("number") == true);
                REQUIRE(object.HasKey("decimal_number") == true);
                REQUIRE(object.HasKey("isTrue") == true);
                REQUIRE(object.HasKey("isFalse") == true);
                REQUIRE(object.HasKey("string") == false);
            }
        }

        SECTION("Saving and loading json") {
            const std::string path = "./tests/json_examples/test_save.json";

            object.Save(path);

            JSON::Object loadedObject(path);

            REQUIRE(loadedObject.IsValid() == true);

            REQUIRE(loadedObject.HasKey("number") == true);
            REQUIRE(loadedObject["number"].IsNumber());
            REQUIRE(loadedObject["number"].AsNumber() == 2);

            REQUIRE(loadedObject.HasKey("decimal_number") == true);
            REQUIRE(loadedObject["decimal_number"].IsNumber());
            REQUIRE(loadedObject["decimal_number"].AsNumber() == 2.1);

            REQUIRE(loadedObject.HasKey("isTrue") == true);
            REQUIRE(loadedObject["isTrue"].IsBool());
            REQUIRE(loadedObject["isTrue"].AsBool() == true);

            REQUIRE(loadedObject.HasKey("isFalse") == true);
            REQUIRE(loadedObject["isFalse"].IsBool());
            REQUIRE(loadedObject["isFalse"].AsBool() == false);

            REQUIRE(loadedObject.HasKey("string") == true);
            REQUIRE(loadedObject["string"].IsString());
            REQUIRE(loadedObject["string"].AsString() == "I'm a full string :)");

            REQUIRE(loadedObject.HasKey("ramdom_key_that_shouldnt_exist") == false);
        }
    }

    SECTION("Unvalid loaded json") {

        SECTION("File not found") {
            JSON::Object object("./tests/json_examples/this_file_doesnt_exist.json");
            REQUIRE(object.IsValid() == false);
        }

        SECTION("Empty file") {
            JSON::Object object("./tests/json_examples/empty.json");
            REQUIRE(object.IsValid() == false);
        }

        SECTION("Key missing quote 1") {
            JSON::Object object("./tests/json_examples/object_key_missing_quote1.json");
            REQUIRE(object.IsValid() == false);
            REQUIRE(object.GetErrorCode() == JSON::ERRORS::KEY_MISSING_QUOTE_START);
        }

        SECTION("Key missing quote 2") {
            JSON::Object object("./tests/json_examples/object_key_missing_quote2.json");
            REQUIRE(object.IsValid() == false);
            REQUIRE(object.GetErrorCode() == JSON::ERRORS::KEY_MISSING_SEPARATOR);
        }

        SECTION("Object missing bracket 1") {
            JSON::Object object("./tests/json_examples/object_missing_bracket1.json");
            REQUIRE(object.IsValid() == false);
            REQUIRE(object.GetErrorCode() == JSON::ERRORS::OBJECT_MISSING_OPENING_BRACKET);
        }

        SECTION("Object missing bracket 2") {
            JSON::Object object("./tests/json_examples/object_missing_bracket2.json");
            REQUIRE(object.IsValid() == false);
            REQUIRE(object.GetErrorCode() == JSON::ERRORS::OBJECT_MISSING_CLOSING_BRACKET);
        }

        SECTION("Missing comma") {
            JSON::Object object("./tests/json_examples/object_missing_comma.json");
            REQUIRE(object.IsValid() == false);
            REQUIRE(object.GetErrorCode() == JSON::ERRORS::MISSING_COMMA);
        }

        SECTION("String missing quote 1") {
            JSON::Object object("./tests/json_examples/object_string_missing_quote1.json");
            REQUIRE(object.IsValid() == false);
        }

        SECTION("String missing quote 2") {
            JSON::Object object("./tests/json_examples/object_string_missing_quote2.json");
            REQUIRE(object.IsValid() == false);
            REQUIRE(object.GetErrorCode() == JSON::ERRORS::MISSING_COMMA);
        }
    }
}