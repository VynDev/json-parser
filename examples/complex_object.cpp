#include <iostream>
#include "json-parser/JSON.h"

using namespace std;

int main()
{
	JSON::Object json;
    
    /* Add basic variables */
    json["number"] = 42;
    json["string"] = "hello world!";
    json["boolean"] = true;

    /* Add an Object and an Array */
    json.AddObject("object");
    json.AddArray("array");

    /* Add variables inside the Object */
    json["object"].AsObject()["number"] = -42;
    json["object"].AsObject()["string"] = "!dlrow olleh";
    json["object"].AsObject()["boolean"] = false;
    json["object"].AsObject().AddObject("object");
    json["object"].AsObject().AddArray("array");

    /* Add variables inside the Array */
    json["array"].AsArray().AddElement(-42);
    json["array"].AsArray().AddElement("!dlrow olleh");
    json["array"].AsArray().AddElement(false);
    json["array"].AsArray().AddObject();
    json["array"].AsArray().AddArray();

    /* Print each basic variables */
    cout << json["number"].AsNumber() << endl;
    cout << json["string"].AsString() << endl;
    cout << json["boolean"].AsBool() << endl;

    // OR

    /* Print the whole JSON */
    cout << json.ToString() << endl;

	return 0;
}