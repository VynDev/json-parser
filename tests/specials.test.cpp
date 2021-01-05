#include "catch.hpp"
#include "../include/json-parser/JSON.h"

TEST_CASE("Nested Object and Array", "[nested]") {

    JSON::Object json;
    
    json["number"] = 42;
    json["string"] = "hello world!";
    json["boolean"] = true;
    json.AddObject("object");
    json.AddArray("array");

    json["object"].AsObject()["number"] = -42;
    json["object"].AsObject()["string"] = "!dlrow olleh";
    json["object"].AsObject()["boolean"] = false;
    json["object"].AsObject().AddObject("object");
    json["object"].AsObject().AddArray("array");

    json["array"].AsArray().AddElement(-42);
    json["array"].AsArray().AddElement("!dlrow olleh");
    json["array"].AsArray().AddElement(false);
    json["array"].AsArray().AddObject();
    json["array"].AsArray().AddArray();

    REQUIRE(json["number"].IsNumber());
    REQUIRE(json["number"].AsNumber() == 42);

    REQUIRE(json["string"].IsString());
    REQUIRE(json["string"].AsString() == "hello world!");

    REQUIRE(json["boolean"].IsBool());
    REQUIRE(json["boolean"].AsBool() == true);

    REQUIRE(json["object"].IsObject());
    REQUIRE(json["array"].IsArray());




    REQUIRE(json["object"].AsObject()["number"].IsNumber());
    REQUIRE(json["object"].AsObject()["number"].AsNumber() == -42);

    REQUIRE(json["object"].AsObject()["string"].IsString());
    REQUIRE(json["object"].AsObject()["string"].AsString() == "!dlrow olleh");

    REQUIRE(json["object"].AsObject()["boolean"].IsBool());
    REQUIRE(json["object"].AsObject()["boolean"].AsBool() == false);

    REQUIRE(json["object"].AsObject()["object"].IsObject());
    REQUIRE(json["object"].AsObject()["array"].IsArray());
    REQUIRE(json["object"].AsObject()["array"].AsArray().GetLenth() == 0);

    REQUIRE(json["array"].AsArray().GetLenth() == 5);

    REQUIRE(json["array"].AsArray()[0].IsNumber());
    REQUIRE(json["array"].AsArray()[0].AsNumber() == -42);

    REQUIRE(json["array"].AsArray()[1].IsString());
    REQUIRE(json["array"].AsArray()[1].AsString() == "!dlrow olleh");

    REQUIRE(json["array"].AsArray()[2].IsBool());
    REQUIRE(json["array"].AsArray()[2].AsBool() == false);

    REQUIRE(json["array"].AsArray()[3].IsObject());
    REQUIRE(json["array"].AsArray()[4].IsArray());
    REQUIRE(json["array"].AsArray()[4].AsArray().GetLenth() == 0);

    const std::string path = "./tests/json_examples/test_save.json";

    json.Save(path);

    JSON::Object loadedJson(path);

    REQUIRE(loadedJson.IsValid() == true);
    REQUIRE(json.ToString() == loadedJson.ToString());
}

TEST_CASE("Quotes", "[quotes]") {
    const std::string path = "./tests/json_examples/quotes_save.json";
    JSON::Object json;

    json["text_with_quotes"] = "This is a \"text with quotes\"";

    json.Save(path);

    JSON::Object loadedJson(path);

    REQUIRE(loadedJson.IsValid() == true);
    REQUIRE(loadedJson.HasKey("text_with_quotes") == true);
    REQUIRE(loadedJson["text_with_quotes"].AsString() == "This is a \"text with quotes\"");
    REQUIRE(json.ToString() == loadedJson.ToString());
}